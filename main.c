#include "arg_parser.h"
#include <stdlib.h>
#include <stdio.h>

int main (int argc, char *argv[]){

	struct arg_t *args_head = AP_new(argc, argv);

	AP_FOREACH(cur, args_head) {
		printf("arg: %s\n", cur->arg);
		for (int i = 0; i < cur->flagc; i++) {
			printf("  flag: %s\n", cur->flagv[i]);
		}

	}

	AP_free(args_head);

	  exit(EXIT_SUCCESS);
}

