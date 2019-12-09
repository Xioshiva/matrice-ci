all : string  string_comput string_compile

string : string.c
	gcc string.c -Wall -Wextra -std=c11 -c -pedantic 

string_comput : string_comput.c
	gcc string_comput.c -Wall -Wextra -std=c11 -c -pedantic	

string_compile : string.o string_comput.o
	gcc string.o string_comput.o -o prog 
clean :
	rm -f *.o string

rebuild : clean all