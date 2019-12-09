#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

char *string_cat(char *dest, const char *src)
{
	int totalsize = string_len(dest) + string_len(src) + 1;
	char *string_clone = malloc(sizeof(dest));
	int lenDest = string_len(dest);
	for (int i = 0; i < lenDest; i++)
		string_clone[i] = dest[i];
	dest = malloc(sizeof(char) * totalsize);
	int k;
	for (int j = 0; j < lenDest; j++)
	{
		dest[j] = string_clone[j];
		k = j;
	}
	for (int i = k; i < totalsize; i++)
		dest[i] = src[i - k];
	free(string_clone);
	return dest;
}

int string_len(const char *s)
{
	int i = 0;
	while(s[i])
	{
		i++;
	}
	return i + 1;
}

char *string_chr(const char *s, char c)
{
	for (int i = 0; i < string_len(s); i++)
	{
		if (s[i] == c)
			return &s[i];
	}
	return NULL;
}

bool string_cmp(const char *s1, const char *s2)
{
	if (string_len(s1) != string_len(s2))
		return false;
	for (int i = 0; i < string_len(s1); ++i)
	{
		if(s1[i] != s2[i])
			return false;
	}
	return true;
}