
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "assert.h"
#include "data.h"
#include "utils.h"
#include "algorithms.h"

#define K 3
const char* sort_names[] = {"bubble", "quick", "insertion"};
const sort_func sorts[] = {bubble_sort, quick_sort, insertion_sort};

const char help_msg[] =
  "The input to sort is\n"
  "\tsort <sort_name> N\n"
  "and is then given as a list of N decimal floating point numbers.\n";

void parse_input(int argc, char* argv[], uint32_t* sort_num, uint32_t* n, data_arr* input){
  if(argc != 3){
    printf(help_msg);
    exit(-1);
  }else{
    uint32_t i;
    int tmp;
    *sort_num = K;
    for(i=0; i < K; i++){
      if(strcmp(argv[1],sort_names[i]) == 0){
        *sort_num = i;
        break;
      }
    }
    if(*sort_num == K){
      printf("the sort name is unrecognized: %s\n", argv[1]);
      exit(-1);
    }

    sscanf(argv[2], "%u", n);
    assert(*n > 0, "n must be greater than 0.");

    *input = make_array(*n);
    for(i = 0; i< (*n); i++){
      tmp = gmp_scanf("%Fd\n", (*input)[i]);
    }
  }
}

int main(int argc, char *argv[]) {
  uint32_t n, sort_num;
  data_arr source;
  sort_func sort;
  double time;
  bool res;
  const char* name;

  parse_input(argc, argv, &sort_num, &n, &source);
  sort = sorts[sort_num];

  name = sort_names[sort_num];
  time = time_sort(sort, source, n, &res);
  
  printf("Sort %s is in order %u with time %f.\n", name, res, time);

  delete_array(source, n);
  return 0;
}
