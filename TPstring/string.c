#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

int main()
{
	char *my_str1 = "pu";
	char *my_str2 = "raie";
	char *my_str3 = "raie";
	//printf("%ld\n", string_len(my_str));
	my_str1 = string_cat(my_str1, my_str2);

	printf("%s\n", my_str1);
	printf("%s\n", string_chr(my_str1, 'u'));
	printf("%d\n", string_cmp(my_str2, my_str1));
	return 0;
}