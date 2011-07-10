#include "merge.h"
#include <stdlib.h>
#include "assert.h"
#include "utils.h"


static void _merge_sort(data_arr source, uint32_t* order, uint32_t l, uint32_t r);
static void merge(data_arr source, uint32_t* order, uint32_t l, uint32_t m, uint32_t r);


void merge_sort(data_arr source, uint32_t* order, uint32_t n){
  if(n > 1){
    _merge_sort(source, order, 0, n-1);
  }
}

void _merge_sort(data_arr source, uint32_t* order, uint32_t l, uint32_t r){
  assert(l <= r, "Left must be before the right!");
  if(r > l){
    uint32_t middle = (r - l)/2 + l;
    _merge_sort(source, order, l, middle);
    _merge_sort(source, order, middle+1, r);
    merge(source, order, l, middle, r);
  }
}

void merge(data_arr source, uint32_t* order, uint32_t l, uint32_t m, uint32_t r){
  assert(l <= m, "");
  assert(m <= r, "");
  if(!(l == m || m == r)){
    uint32_t range = r - l + 1;
    uint32_t* tmp = (uint32_t*) malloc(sizeof(uint32_t)*range);

    uint32_t left_iterator, right_iterator;
    left_iterator  = l;
    right_iterator = m + 1;
    uint32_t i = 0;
    while(left_iterator <= m && right_iterator <= r){      
      if(cmp_wrt_order(source, order, left_iterator, right_iterator) <= 0){
        tmp[i] = order[left_iterator];
        left_iterator++;
        i++;
      }else{
        tmp[i] = order[right_iterator];
        right_iterator++;
        i++;
      }
    }
    while(left_iterator <= m){
      tmp[i] = order[left_iterator];
      i++;
      left_iterator++;
    }
    while(right_iterator <= r){
      tmp[i] = order[right_iterator];
      i++;
      right_iterator++;
    }
    for(i = 0; i < range; i++){
      order[i+l] = tmp[i];
    }
    free(tmp);
  }
}
