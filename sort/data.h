#include <stdio.h>
#include <gmp.h>


#ifndef SORTING__DATA_H
#define SORTING__DATA_H

typedef mpf_t data_t;
typedef data_t* data_ptr;
typedef data_ptr data_arr;
typedef void (*cmp)(data_t a, data_t b);

/* Initializes x of a specified data type to a default value.
 */
void init_data(data_t x);

/* Frees the memory associated with x of a specified data type.
 *
 * precondition:   x must have been initialized 
 * postcondition:  data that has been cleared is no longer considered
 *                 initialized
 */
void clear_data(data_t x);

/* Sets the value of x to the value stored in y.
 *
 * precondition: x and y must have been initialized 
 */
void set_data(data_t x, data_t y);

/* Compares the values of a and b.
 *
 * precondition: a and b must have been initialized 
 *
 * return: < 0 if a is strictly less than b
 *         = 0 if a is strictly equal to b
 *         > 0 if a is strictly greater than b
 */
int cmp_data(data_t a, data_t b);

/* Prints the value of x to stdout.
 *
 * precondition: x must have been been intialized
 */
void print_data(data_t x);

/* Prints the value of x to stream.
 *
 * precondition: x must have been been intialized
 */
void fprint_data(FILE* stream, data_t x);

/* Assigns a to random value using a pseudo-random number generaton.
 * (See documentation for GMP for gmp_randstate_t.)
 */
void generate_random(data_t a, gmp_randstate_t state);

#endif /* SORTING__DATA_H */
