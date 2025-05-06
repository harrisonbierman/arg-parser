/**
 * Argument Parsing API for CLI tools
 */

#include "arg_parser.h"
#include <stdlib.h>

struct arg_t* AP_new(int tokc, char *tokv[]) {
	

	struct arg_t *p_ap_head = malloc(sizeof(struct arg_t));

	struct arg_t *p_ap = p_ap_head;

	int first_pass = 1;

	// each argument
	for (int i = 0; i < tokc; i++) {

		if (!first_pass) {
			struct arg_t *p_ap_next = malloc(sizeof(struct arg_t));

			p_ap->next = p_ap_next;

			p_ap = p_ap_next;
		}

		first_pass = 0;

		// if token is not option 
		if (tokv[i][0] != '-') {
			p_ap->arg = tokv[i];	
		} else {
			int j = 0;
			while (tokv[i] != NULL && tokv[i][0] == '-') {;
				p_ap->flagv[j] = tokv[i];
				i++;
				j++;
			}
		}
	}

	return(p_ap_head);
}


/**
 * notes:
 *
 * API functions I want 
 *
 * struct arg_t ap = AP_new(argc, &argv);
 *
 *
 *
 *
 * switch(ap.arg[1]) {
 *		case(
 * }
 *
 * 
 * if (AP_has_opt(ap.arg[1], "--all", "-a")) {
 *		// handle option
 * }
 *
 * // can add NULL is there is no short or long option
 * if (AP_has_opt(ap.arg[2], "--oneline", NULL)) {
 *		// handle option
 * }
 *
 */ 

