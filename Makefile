CC=gcc
COMPILE_OPTS= -Wall -Wextra -g -std=c11
OPTIM_OPTS= -O3
# il faut lancer docker en mode privileged pour les leak check
SANITIZERS= -fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer 
LIBS=-lcunit -lm -lSDL2

all: matrix_compute compile_test

matrix_compute: src/matrix_compute.o src/matrix.o
	$(CC) $^ -o $@ $(LIBS) $(SANITIZERS) $(OPTIM_OPTS)

compile_test: src/test/test.o src/test/test_matrix.o src/matrix.o
	$(CC) $^ -o test $(LIBS) $(SANITIZERS) $(OPTIM_OPTS)

test: compile_test
	./test

%.o : %.c
	$(CC) $(COMPILE_OPTS) $(OPTIM_OPTS) $(SANITIZERS) -c $^ -o $@

SUBDIR_ROOTS := src
DIRS := . $(shell find $(SUBDIR_ROOTS) -type d)
GARBAGE_PATTERNS := *.o 
GARBAGE := $(foreach DIR,$(DIRS),$(addprefix $(DIR)/,$(GARBAGE_PATTERNS)))

clean:
	rm -rf $(GARBAGE)
	rm -f matrix_compute test

.PHONY: clean test
