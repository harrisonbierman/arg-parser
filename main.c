#include "arg_parser.h"
#include <stdlib.h>
#include <stdio.h>

int main (int argc, char *argv[]){

	struct arg_t *ap = AP_new(argc, argv);

	int i = 0;
	while(ap) {
		printf("arg %d: %s\n", i++, ap->arg);
		for (int j = 0; j < ap->flagc; j++) {
			printf("  flag %d, %s\n", j, ap->flagv[j]);
		}
		ap = ap->next;
	}

	AP_free(ap);

	  exit(EXIT_SUCCESS);
}

