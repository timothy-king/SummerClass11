#include "sorting.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define RANDOM_BITS 120

/*  (See documentation in the header file data.h.)
 */
void init_data(data_t x){
  mpf_init(x);
}

void clear_data(data_t x){
  mpf_clear(x);
}

void set_data(data_t x, data_t y){
  mpf_set(x,y);
}

int cmp_data(data_t a, data_t b){
  return mpf_cmp(a, b);
}

void generate_random(data_t a, gmp_randstate_t state){
  mpf_urandomb(a, state, RANDOM_BITS);
}

void print_data(data_t x){
  fprint_data(stdout, x);
}

void fprint_data(FILE* stream, data_t x){
  gmp_fprintf(stream, "%.Ff", x);
}
