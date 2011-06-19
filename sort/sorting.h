#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "data.h"


#ifndef SORTING__SORTING_H
#define SORTING__SORTING_H

/* Defines a type of sorting function.
 * The original array is stored in source of length n.  
 * The sorted order of the original elements of the array is stored in
 * in perm (permutation), also of length n. 
 *
 * precondition: perm is originally the identity permuation i.e. perm[i] == i for all i
 * post condition: source[perm[i]] <= source[perm[i+1]] for 0 <= i < n - 1
 */
typedef void (*sort_func)(data_arr source, uint32_t* perm, uint32_t n);

/* Times a sort_func f and sorts a copy of the data_arr source of length n.
 * Returns a double containing the running time.
 * Stores whether the sort was correctly stably sorted in res.
 */
double time_sort(sort_func f, data_arr source, uint32_t n, bool* res);

/*
 * Times a sort_func f and sorts a copy of the data_arr source of length n.
 * Returns a double containing the running time.
 * Sorts whether the sort was correctly stably sort in res.
 */
double* time_sorts(sort_func* f, uint32_t k, data_arr source, uint32_t n, bool* res, double* times);

/*
 * bubble_sort is an instance of sort_func implementing a bubble sort.
 * (See documentation for sort_func.)
 */
void bubble_sort(data_arr source, uint32_t* order, uint32_t n);

/*
 * insertion_sort is an instance of sort_func implementing an insertion sort.
 * (See documentation for sort_func.)
 */
void insertion_sort(data_arr source, uint32_t* order, uint32_t n);

/*
 * quick_sort is an instance of sort_func implementing a quick sort.
 * (See documentation for sort_func.)
 */
void quick_sort(data_arr source, uint32_t* order, uint32_t n);


#endif /* SORTING__SORTING_H */
