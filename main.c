#include "arg_parser.h"
#include <stdlib.h>
#include <stdio.h>

int main (int argc, char *argv[]){

	struct arg_t *head = NULL;
	int rc = AP_parse(argc, argv, &head);
	if(rc != 0) {
		perror("Error: something when wrong");
		exit(EXIT_FAILURE);
	}

	struct arg_t *arg = AP_get(head, 1);
	if(arg == NULL) {
		fprintf(stderr, "Error: element out of bounds\n");
		exit(EXIT_FAILURE);
	}
	struct arg_t *arg2 = AP_get(head, 0);

	printf("arg = %s\n", arg->arg);
	printf("arg2 = %s\n", arg2->arg);

	if(AP_has_flag(arg2, "-h", NULL)) {
		printf("arg %s, has flag!\n", arg2->arg);
	}

	AP_free(head);

	  exit(EXIT_SUCCESS);
}

