#include <stdio.h>
#include <stdlib.h>
#include "assert.h"b

void assert(bool cnd, const char* msg){
  if(!cnd){

    fprintf(stderr, "An error occurred: %s", msg);
    exit(-1);
  }
}
