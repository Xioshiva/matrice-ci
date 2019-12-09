#include <stdlib.h>
#include <stdbool.h>
#ifndef _STRING_H_
#define _STRING_H_

char *string_cat(char *dest, const char *src);
int string_len(const char *s);
char *string_chr(const char *s, char c);
bool string_cmp(const char *s1, const char *s2);

#endif