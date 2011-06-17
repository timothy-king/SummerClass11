#include <gmp.h>
#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

uint32_t rand_range(gmp_randstate_t state, uint32_t min, uint32_t max){
  assert(min < max, "range_range requires min < max");

  mpz_t tmp;
  mpz_init(tmp);

  mpz_urandomb(tmp, state, 32);

  uint32_t random = mpz_get_ui(tmp);
  random = ((random) % (max - min)) + min;

  return random;
}

uint32_t* make_range(uint32_t n){
  uint32_t* range = (uint32_t*)malloc(sizeof(uint32_t)*n);
  assert(range != NULL, "Failed to allocate a range.");
  uint32_t i;
  for(i=0; i < n; ++i){
    range[i] = i;
  }
  return range;
}

void print_array(data_arr arr, uint32_t n){
  printf("[");
  if(n >=1){
    uint32_t i;
    for(i=0; i+1<n; i++){
      print_data(arr[i]);
      printf(",");
    }
    print_data(arr[n-1]);
  }
  printf("]\n");
}

void print_array_wrt_ord(data_arr arr, uint32_t* order, uint32_t n){
  printf("[");
  if(n >=1){
    uint32_t i;
    for(i=0; i+1<n; i++){
      print_data(arr[order[i]]);
      printf(",");
    }
    print_data(arr[order[n-1]]);
  }
  printf("]\n");
}

void generate_random_arr(uint32_t n, data_arr arr, gmp_randstate_t state){
  uint32_t i;
  for(i=0; i<n; i++){
    generate_random(arr[i], state);
  }
}

data_arr copy_array(data_arr arr, uint32_t n){
  data_arr cp = make_array(n);

  uint32_t i;
  for(i=0; i<n; i++){
    set_data(cp[i], arr[i]);
  }
  return cp;
}


data_arr make_array(uint32_t n){
  data_arr array = (data_arr) malloc(sizeof(data_t)*n);
  assert(array != NULL, "make_array malloc failed");

  uint32_t i;
  for(i=0; i<n; ++i){
    init_data(array[i]);
  }

  return array;
}


void swap(uint32_t* arr, uint32_t i, uint32_t j){
  uint32_t tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}


int cmp_wrt_order(data_arr source, uint32_t* order, uint32_t i, uint32_t j){
  int res = cmp_data(source[order[i]], source[order[j]]);
  //printf("order[%u] -> %u order[%u] -> %u\n, %d", i, order[i], j,order[j], res);
  return res;
}


bool check_stable_sortedness(data_arr source, uint32_t* order, uint32_t n){
  return local_stable_inversion(source, order,n) == 0;
}

uint32_t local_stable_inversion(data_arr source, uint32_t* order, uint32_t n){
  uint32_t i, ord;
  for(i = 1; i < n; ++i){
    ord = cmp_wrt_order(source, order, i-1, i); 
    if( ord < 0 || (ord ==0) && order[i-1] >= order[i]){
      return i;
    }
  }
  return 0;
}

void delete_array(data_arr arr, uint32_t n){
  uint32_t i;
  for(i=0; i<n; i++){
    clear_data(arr[i]);
  }
  free(arr);
}
