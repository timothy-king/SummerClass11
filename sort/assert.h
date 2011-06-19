#include <stdbool.h>

#ifndef SORTING__ASSERT_H
#define SORTING__ASSERT_H

/* If cnd is false, msg is printed on sterr,
 * and the program exits with the status -1.
 */
void assert(bool cnd, char* msg);

#endif /* SORTING__ASSERT_H */
