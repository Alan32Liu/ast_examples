CC=clang

default: clean main.c headers/utility.h headers/math/math_functions.h
	$(CC) -Xclang -ast-dump -fsyntax-only main.c > main.c.ast

json: clean main.c headers/utility.h headers/math/math_functions.h
	$(CC) -Xclang -ast-dump=json -fsyntax-only main.c > main.c.ast

clean:
	rm -f **/*.ast

.PHONY: clean

