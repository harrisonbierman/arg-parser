#include "arg_parser.h"
#include <stdlib.h>
#include <stdio.h>

int main (int argc, char *argv[]){

	struct arg_t *args_head = AP_parse(argc, argv);

	struct arg_t *arg = AP_get(1, args_head);
	if(arg == NULL) {
		fprintf(stderr, "Error: element out of bounds\n");
		exit(EXIT_FAILURE);
	}
	struct arg_t *arg2 = AP_get(0, args_head);

	printf("arg = %s\n", arg->arg);
	printf("arg2 = %s\n", arg2->arg);

	if(AP_has_flag("-h", NULL, arg2)) {
		printf("arg %s, has flag!\n", arg2->arg);
	}

	AP_free(args_head);

	  exit(EXIT_SUCCESS);
}

