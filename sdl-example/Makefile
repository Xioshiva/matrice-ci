# CC=gcc
CC=clang
COMPILE_OPTS= -Wall -Wextra -g -std=c11
OPTIM_OPTS= -O3
#SANITIZERS= -fsanitize=address -fsanitize=leak -fsanitize=undefined -fno-omit-frame-pointer  -static-libasan
# -fsanitize=leak semble superflu https://github.com/google/sanitizers/issues/859
# il faut lancer docker en mode privileged pour les leak check
# SANITIZERS= -fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer  #-static-libasan
SANITIZERS=
LIBS=-lSDL2

all: sdl_example

sdl_example: sdl_example.o gfx.o
	$(CC) $^ -o $@ $(LIBS) $(SANITIZERS) $(OPTIM_OPTS)

%.o : %.c
	$(CC) $(COMPILE_OPTS) $(OPTIM_OPTS) $(SANITIZERS) -c $^ -o $@

SUBDIR_ROOTS := src
DIRS := . $(shell find $(SUBDIR_ROOTS) -type d)
GARBAGE_PATTERNS := *.o 
GARBAGE := $(foreach DIR,$(DIRS),$(addprefix $(DIR)/,$(GARBAGE_PATTERNS)))

clean:
	rm -rf $(GARBAGE)
	rm -f sdl_example

.PHONY: clean test