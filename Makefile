default:
	gcc -Wall -Wextra -std=c17 main.c arg_parser.c -o main

archive:
	gcc -O2 -fPIC -c arg_parser.c -o arg_parser.o
	ar rcs libargparser.a arg_parser.o
	rm arg_parser.o
	mkdir -p /usr/local/lib /usr/local/include
	cp libargparser.a /usr/local/lib/
	cp arg_parser.h /usr/local/include/
	ldconfig
