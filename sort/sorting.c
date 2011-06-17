#include "sorting.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "assert.h"
#include "data.h"
#include "utils.h"


void bubble_sort(data_arr source, uint32_t* order, uint32_t n){
  bool swapped_in_this_round;
  uint32_t i;

  do{
    swapped_in_this_round = false;

    for(i=1; i<n; i++){
      if(cmp_wrt_order(source, order, i-1, i) > 0){
	swap(order, i-1, i);
	swapped_in_this_round = true;
      }
    }
  }while(swapped_in_this_round);
}

void _insertion_sort(data_arr source, uint32_t* order, uint32_t l, uint32_t r){
  if(l >= r) return;

  uint32_t i,j;
  for(i=l+1; i<=r; i++){
    for(j=i; j>l; j--){
      if(cmp_wrt_order(source, order, j-1, j) > 0){
	swap(order, j-1, j);
      }else{
	break;
      }
    }
  }
}

void insertion_sort(data_arr source, uint32_t* order, uint32_t n){
  if(n >= 1){
    _insertion_sort(source, order, 0, n-1);
  }
}

uint32_t partition(data_arr source, uint32_t* order, uint32_t s, uint32_t e){
  assert(s <= e, "partition requires s <= e");

  uint32_t i, j;
  int cmp;
  j = s;
  for(i=s; i<e; i++){
    cmp = cmp_wrt_order(source, order, i, e); 
    if(cmp < 0 || (cmp == 0 && order[i] < order[e])){
      swap(order, j, i);
      j++;
    }
  }
  swap(order, j, e);
  return j;
}

void _quick_sort(data_arr source, uint32_t* order, uint32_t s, uint32_t e){
  assert(s <= e, "Quicksort requires s <= e.");

  uint32_t k;
  k = partition(source, order, s, e);
  if(k > s)
    _quick_sort(source, order, s, k-1);
  if(k < e)
    _quick_sort(source, order, k+1, e);
}

void quick_sort(data_arr source, uint32_t* order, uint32_t n){
  _quick_sort(source, order, 0, n-1);
}


double time_sort(sort_func f, data_arr source, uint32_t n, bool* res){
  clock_t c0, c1;
  double cputime;
  uint32_t* order = make_range(n);
  data_arr copy = copy_array(source,n);

  c0 = clock();
  f(copy, order, n);
  c1 = clock();

  cputime = ((double)(c1 - c0))/(CLOCKS_PER_SEC );

  if(res != NULL){
    *res = check_stable_sortedness(source, order, n) ; 
  }

  print_array(source, n);
  print_array(copy, n);
  print_array_wrt_ord(source, order, n);

  delete_array(copy, n);
  free (order);
  return cputime;
}

double* time_sorts(sort_func* f, uint32_t k, data_arr source, uint32_t n, bool* res, double* times){
  uint32_t i;
  bool localres;

  *res = true;
  for(i=0; i<k; i++){
    times[i] = time_sort(f[i], source, n, &localres);
    *res &= localres;
  }
}
