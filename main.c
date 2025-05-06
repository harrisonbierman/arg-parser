#include "arg_parser.h"
#include <stdlib.h>
#include <stdio.h>

int main (int argc, char *argv[]){

	struct arg_t *ap = AP_new(argc, argv);

	while(ap) {
		printf("arg: %s\n", ap->arg);
		ap = ap->next;
	}


	  exit(EXIT_SUCCESS);
}

