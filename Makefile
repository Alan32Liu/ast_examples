CC=clang

default: clean_ast main.c headers/utility.h headers/math/math_functions.h
	$(CC) -Xclang -ast-dump -fsyntax-only main.c > main.c.ast

json: clean_json main.c headers/utility.h headers/math/math_functions.h
	$(CC) -Xclang -ast-dump=json -fsyntax-only main.c > main.c.json

all: clean_ast main.c headers/utility.h headers/math/math_functions.h
	$(CC) -Xclang -ast-dump-all -fsyntax-only main.c > main.c.all.ast

all-json: clean_json main.c headers/utility.h headers/math/math_functions.h
	$(CC) -Xclang -ast-dump-all=json -fsyntax-only main.c > main.c.all.json

tags:
	ctags -n --fields=+iSst -R .

clean_ast:
	find . -name "*.ast" -type f -delete

clean_json:
	find . -name "*.json" -type f -delete

clean: clean_ast clean_json

.PHONY: clean

