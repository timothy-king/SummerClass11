#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include "assert.h"
#include "data.h"
#include "utils.h"

#define MIN_DEFAULT 10
#define MAX_DEFAULT 20000000

const char help_msg[] =
  "The input format for generate is:\n"
  "\tgenerate <SEED>\n"
  "\tgenerate <SEED> <N>\n"
  "\tgenerate <SEED> <MIN> <MAX>\n";

void parse_input(int argc, const char* argv[], mpz_t seed, uint32_t* min, uint32_t* max){
  int tmp;

  if(argc <= 1 || argc > 4){
    printf(help_msg);
    exit(-1);
  }
  tmp = gmp_sscanf(argv[1], "%Zd\n", seed);

  *min = MIN_DEFAULT;
  *max = MAX_DEFAULT;

  if(argc >= 3){
    sscanf(argv[2], "%u", min);
  }

  if(argc == 3){
    *max = *min;
  }else if(argc == 4){
    sscanf(argv[3], "%u", max);
  }
}

int main(int argc, const char* argv[]) {

  gmp_randstate_t state;
  data_arr source;
  mpz_t seed;
  uint32_t min, max, n;


  mpz_init(seed);

  parse_input(argc, argv, seed, &min, &max);

  gmp_randinit_default(state);
  gmp_randseed(state, seed);

  n = rand_range(state, min, max);

  fprintf(stderr, "%u\n",n);
  source = make_array(n);

  generate_random_arr(n, source, state);
  
  
  fprint_array(stdout, source, n);

  gmp_randclear(state);
  delete_array(source, n);
  mpz_clear(seed);
  return 0;
}
