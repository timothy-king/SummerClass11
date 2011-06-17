#include "sorting.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "assert.h"
#include "data.h"
#include "utils.h"
#include "sorting.h"

#define MIN 20000
#define MAX 3000000
#define K 1

int main() {

  gmp_randstate_t state;
  mpz_t seed;
  uint32_t n;
  data_arr source;
  int tmp;
  sort_func sorts[K];
  double times[K];

  sorts[0] = quick_sort;
  //sorts[1] = bubble_sort;
  //sorts[2] = insertion_sort;



  mpz_init(seed);
  gmp_randinit_default(state);

  tmp = gmp_scanf("%Zd\n", seed);

  gmp_printf("%Zd\n", seed);

  gmp_randseed(state, seed);

  n = rand_range(state, MIN, MAX);
  printf("%u\n",n);
  source = make_array(n);

  generate_random_arr(n, source, state);

  bool res;

  time_sorts(sorts, K, source, n, &res, times);
  
  uint32_t i;
  printf("In order: %u\n", res);
  for(i=0; i<K; i++){
    printf("Time: %f\n", times[i]);
  }

  assert(res, "Not in order.");
 

  delete_array(source, n);
  mpz_clear(seed);
  return 0;
}
