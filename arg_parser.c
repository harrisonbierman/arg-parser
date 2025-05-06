/**
 * Argument Parsing API for CLI tools
 */

#include "arg_parser.h"
#include <stdlib.h>

struct arg_parse_t AP_new(int tokc, char *tokv[]) {
	
	struct arg_parse_t ap;
	ap.argc = 0;

	int n_args = 0;
	// each argument
	for (int i = 0; i < tokc; ++i) {
		
		arg_t a;

		// if token is not option 
		if (tokv[i][0] != '-') {
			a.arg = tokv[i];
		} else {
			a.optc = 0;
			while (tokv[i][0] == '-') {
				i++;
				a.optc++;
			}
			a.opt = malloc(a.optc * sizeof(a.opt));
			i = i - a.optc;
			for (int j = 0; j < a.optc; j++) {
				a.opt[j] = tokv[i];
			}
		}


		ap.argv[ap.argc] = malloc(sizeof(arg_t));
		ap.argv[ap.argc] = &a;
		ap.argc++;

	}

	return(ap);
}


/**
 * notes:
 *
 * API functions I want 
 *
 * struct arg_parse_t ap = AP_new(argc, &argv);
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

