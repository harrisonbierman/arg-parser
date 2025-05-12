default:
	gcc -Wall -Wextra -std=c17 main.c arg_parser.c -o main

# distributes to shared lib directory
dynamic-lib:
	gcc -O2 -fPIC -c arg_parser.c -o arg_parser.o
	ar rcs libargparser.a arg_parser.o
	rm arg_parser.o
	mkdir -p /usr/local/lib /usr/local/include
	cp libargparser.a /usr/local/lib/
	cp arg_parser.h /usr/local/include/
	ldconfig

# distributes local directories 
static-lib:
	gcc -O2 -fPIC -static -c arg_parser.c -o arg_parser.o
	ar rcs libargparser.a arg_parser.o
	rm arg_parser.o
	
	# copy to local include
	mkdir -p ~/c/cli-programs/jump-edit/include ~/c/cli-programs/jump-edit/lib
	cp arg_parser.h ~/c/cli-programs/jump-edit/include/
	cp libargparser.a ~/c/cli-programs/jump-edit/lib/

copy-src:
	cp arg_parser.h ~/c/cli-programs/jump-edit/include/
	cp arg_parser.c ~/c/cli-programs/jump-edit/lib/



