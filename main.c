#include "arg_parser.h"
#include <stdlib.h>
#include <stdio.h>

int main (int argc, char *argv[]){

	struct arg_t *head_args = AP_new(argc, argv);
	struct arg_t *iter_args = head_args;

	int i = 0;
	while(iter_args) {
		printf("arg %d: %s\n", i++, iter_args->arg);
		for (int j = 0; j < iter_args->flagc; j++) {
			printf("  flag %d, %s\n", j, iter_args->flagv[j]);
		}
		iter_args = iter_args->next;
	}

	AP_free(head_args);

	  exit(EXIT_SUCCESS);
}

