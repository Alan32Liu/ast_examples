CC=clang

default: clean main.c headers/utility.h headers/math/math_functions.h
	$(CC) -Xclang -ast-dump -fsyntax-only main.c > main.c.ast

json: clean main.c headers/utility.h headers/math/math_functions.h
	$(CC) -Xclang -ast-dump=json -fsyntax-only main.c > main.c.json

all: clean main.c headers/utility.h headers/math/math_functions.h
        $(CC) -Xclang -ast-dump-all -fsyntax-only main.c > main.c.all.ast

all-json: clean main.c headers/utility.h headers/math/math_functions.h
         $(CC) -Xclang -ast-dump-all=json -fsyntax-only main.c > main.c.all.json

clean:
	rm -f **/*.ast

.PHONY: clean

