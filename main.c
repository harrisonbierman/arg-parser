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

	struct arg_t *arg1 = AP_get(head, 1);
	if(arg1 == NULL) {
		fprintf(stderr, "Error: element out of bounds\n");
		exit(EXIT_FAILURE);
	}
	struct arg_t *arg0 = AP_get(head, 0);

	printf("arg = %s\n", arg1->arg);
	printf("arg2 = %s\n", arg0->arg);

	if(AP_has_flag(arg1, "-h", "--help")) {
		printf("arg %s, has flag!\n", arg1->arg);
	}

	AP_free(head);

	  exit(EXIT_SUCCESS);
}

