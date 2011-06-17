#include <gmp.h>

#ifndef SORTING__DATA_H
#define SORTING__DATA_H

typedef mpf_t data_t;
typedef data_t* data_ptr;
typedef data_ptr data_arr;
typedef void (*cmp)(data_t a, data_t b);

void init_data(data_t x);
void clear_data(data_t x);

void set_data(data_t x, data_t y);

int cmp_data(data_t a, data_t b);
void print_data(data_t x);

void generate_random(data_t a, gmp_randstate_t state);

#endif /* SORTING__DATA_H */
