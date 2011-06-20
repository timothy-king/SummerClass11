#include "data.h"
#include <gmp.h>
#include <stdint.h>
#include <stdbool.h>

#ifndef SORTING__UTILS_H
#define SORTING__UTILS_H

/* Generates and returns a random number within a range of min and max, inclusively,
 * using a pseudo-random number generator.
 * (See documention for GMP for gmp_randstate_t.)
 */
uint32_t rand_range(gmp_randstate_t state, uint32_t min, uint32_t max);

/* Makes an array filled with 0 to n-1 of length n.
 *
 * post condition: returned array is such that array[i] = i
 */
uint32_t* make_range(uint32_t n);
 
/* Prints the first n values of arr to stdout.
 */
void print_array(data_arr arr, uint32_t n);

/* Prints the first n values of arr to stream.
 */
void fprint_array(FILE * stream, data_arr arr, uint32_t n);

/* Prints the first n values of arr with respect to order.
 */
void print_array_wrt_ord(data_arr arr, uint32_t* order, uint32_t n);


void generate_random_arr(uint32_t n, data_arr arr, gmp_randstate_t state);

/* Makes an array of length n of initialized data_t values.
 * This array can be freed with delete_array(...).
 */
data_arr make_array(uint32_t n);

/* Frees an array allocated by make_array(). 
 */
void delete_array(data_arr arr, uint32_t n);

/* Creates an array of length n, then copies the first n elements of arr
 * into the created array.
 */
data_arr copy_array(data_arr arr, uint32_t n);


/* Swaps the value stored in the ith element in arr with 
 * the value stored in the jth element in arr.
 */
void swap(uint32_t* arr, uint32_t i, uint32_t j);

/* Returns the first position of a position i s.t. it is not the case that
 * position i and i+1 are stably sorted. Formally,
 *    !( source[order[i]] < source[order[i+1]] ||
 *       (source[order[i]] == source[order[i+1]] && order[i] < order[i+1])
 * Returns 0 if there is no local inversion. */
uint32_t local_stable_inversion(data_arr source, uint32_t* order, uint32_t n);

/* Returns true iff for all 0 <= i < j <= n-1, 
 * ( source[order[i]] < source[order[i+1]] ||
 *       (source[order[i]] == source[order[i+1]] && order[i] < order[i+1])
 */
bool check_stable_sortedness(data_arr source, uint32_t* order, uint32_t n);

int cmp_wrt_order(data_arr source, uint32_t* order, uint32_t i, uint32_t j);

#endif /* SORTING__UTILS_H */
