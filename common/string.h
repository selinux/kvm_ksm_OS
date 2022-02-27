#ifndef _STRING_COMMON_H_
#define _STRING_COMMON_H_

#include "types.h"

extern uint_t strlen(char *s);
extern char *strncpy(char *dest, const char *src, uint_t count);
extern int strcmp(const char *s1, const char *s2);
extern int strncmp(const char *s1, const char *s2, uint_t n);

#endif
