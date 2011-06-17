#include "data.h"
#include <gmp.h>
#include <stdint.h>
#include <stdbool.h>

#ifndef SORTING__UTILS_H
#define SORTING__UTILS_H

uint32_t rand_range(gmp_randstate_t state, uint32_t min, uint32_t max);

uint32_t* make_range(uint32_t n);


data_arr make_array(uint32_t n);
data_arr copy_array(data_arr arr, uint32_t n);

void print_array(data_arr arr, uint32_t n);

void print_array_wrt_ord(data_arr arr, uint32_t* order, uint32_t n);


void generate_random_arr(uint32_t n, data_arr arr, gmp_randstate_t state);

data_arr make_array(uint32_t n);
void delete_array(data_arr arr, uint32_t n);

data_arr copy_array(data_arr arr, uint32_t n);


void swap(uint32_t* arr, uint32_t i, uint32_t j);

/* Returns 0 if there is no local inversion. */
uint32_t local_stable_inversion(data_arr source, uint32_t* order, uint32_t n);
bool check_stable_sortedness(data_arr source, uint32_t* order, uint32_t n);

int cmp_wrt_order(data_arr source, uint32_t* order, uint32_t i, uint32_t j);

#endif /* SORTING__UTILS_H */
