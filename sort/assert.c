#include <stdio.h>
#include <stdlib.h>
#include "assert.h"b

/*  (See documentation in the header file assert.h.)
 */
void assert(bool cnd, char* msg){
  if(!cnd){

    fprintf(stderr, "An error occurred: %s", msg);
    exit(-1);
  }
}
