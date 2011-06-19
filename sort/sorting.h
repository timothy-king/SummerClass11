#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "data.h"


#ifndef SORTING__SORTING_H
#define SORTING__SORTING_H

typedef void (*sort_func)(data_arr source, uint32_t* order, uint32_t n);

double time_sort(sort_func f, data_arr source, uint32_t n, bool* res);
void time_sorts(sort_func* f, uint32_t k, data_arr source, uint32_t n, bool* res, double* times);

void bubble_sort(data_arr source, uint32_t* order, uint32_t n);
void insertion_sort(data_arr source, uint32_t* order, uint32_t n);
void quick_sort(data_arr source, uint32_t* order, uint32_t n);


#endif /* SORTING__SORTING_H */
