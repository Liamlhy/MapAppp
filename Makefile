
all: autocomplete

clean:
	rm -rf autocomplete autocomplete.dSYM

autocomplete: main.c autocomplete.c autocomplete.h
	gcc --std=c11 -g -o autocomplete main.c autocomplete.c -lncurses
