
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_N_32FIB 46

uint32_t fib_rec(uint8_t n){
  if(n > MAX_N_32FIB){
    fprintf(stderr, "I cannot compute fib(%d). I need more bits", n);
    exit(-1);
  }else if(n == 0){
    return 0;
  }else if(n == 1){
    return 1;
  }else{
    return fib_rec(n-1) + fib_rec(n-2);
  }
}

uint32_t fib_iter(uint8_t n){
  if(n > MAX_N_32FIB){
    fprintf(stderr, "I cannot compute fib(%d). I need more bits", n);
    exit(-1);
  }else if(n == 0){
    return 0;
  }else if(n == 1){
    return 1;
  }else{
    uint32_t i = 1;
    uint32_t prev = 0;
    uint32_t fib_i = 1;
    while(i < n){
      uint32_t tmp = fib_i;
      fib_i = fib_i + prev;
      prev = tmp;
      i++;
    }
    return fib_i;
  }
}


static uint32_t savedResults[MAX_N_32FIB+1];
static uint32_t savedResultsLength = 0;

uint32_t fib_memoize(uint8_t n){
  if(n > MAX_N_32FIB){
    fprintf(stderr, "I cannot compute fib(%d). I need more bits!\n", n);
    exit(-1);
  }else if (n < savedResultsLength){
    return savedResults[n];
  }else{
    if(savedResultsLength < 2){
      savedResults[0] = 0;
      savedResults[1] = 1;
      savedResultsLength = 2;
    }
    while(savedResultsLength <= n){
      savedResults[savedResultsLength] =
        savedResults[savedResultsLength-1] + savedResults[savedResultsLength-2];
      savedResultsLength++;
    }
    return savedResults[n];
  }
}

typedef uint32_t (*fib_func)(uint8_t);

void fib_range(fib_func f, uint8_t start, uint8_t end, const char* name){
  uint8_t i;
  for(i = start; i <= end; i++){
    printf("%s(%d) :-> %d.\n", name, i, f(i));
  }
}

int main(){
  fib_range(fib_iter, 0, MAX_N_32FIB, "fib_iter");
  fib_range(fib_memoize, 0, MAX_N_32FIB, "fib_memoize");
  fib_range(fib_rec, 0, MAX_N_32FIB, "fib_rec");

  return 0;
}
