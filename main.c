#include "arg_parser.h"
#include <stdlib.h>
#include <stdio.h>

int main (int argc, char *argv[]){

	struct arg_t *args_head = AP_new(argc, argv);

	struct arg_t *arg = AP_get(2, args_head);
	struct arg_t *arg2 = AP_get(5, args_head);

	printf("arg = %s\n", arg->arg);
	printf("arg2 = %s\n", arg2->arg);

	AP_free(args_head);

	  exit(EXIT_SUCCESS);
}

