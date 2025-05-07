/**
 * Argument Parsing API for CLI tools
 */

#include "arg_parser.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int AP_parse(int tokc, char *tokv[], struct arg_t **out_head) {
	int error = 0;

	// I need to remember that you can initiate
	// pointers as NULL if you don't want to use
	// them yet
	struct arg_t *head = NULL, *tail = NULL;

	// each argument
	for (int i = 0; i < tokc;) {

		// calloc will zero out allocation 
		struct arg_t *node = calloc(1, sizeof(struct arg_t));

		node->next = NULL; // terminate by default

		// regular argument
		node->arg = tokv[i];	

		i++; // move to next token

		// collect all flags after arg
		int count = 0;
		while (i < tokc && tokv[i][0] == '-' && count < MAX_FLAGS) {;
			node->flagv[count++] = tokv[i++];
		}

		node->flagc = count;  
		node->flagv[count] = NULL;

		// better solution than I had last commit
		if(!head) {
			// tail and head will be the same
			// pointer of there is no other arguments
			head = tail = node;
		} else {
			tail->next = node;
			tail = node;
		}

	}

	*out_head = head;
	return(error); // use AP_free();
}

void AP_free(struct arg_t *head) {
	struct arg_t *curr = head;
	while(curr){
		struct arg_t *next = curr->next;
		free(curr);
		curr = next;
	}
}

struct arg_t* AP_get(struct arg_t *head, size_t element) {
	size_t i = 0;
	AP_FOREACH(curr, head) {
		if(i == element) 
			return curr;
		i++;
	}
	return NULL;
}

int AP_has_flag(struct arg_t *arg, char *flag_short, char *flag_long) {
	for(int i = 0; i < arg->flagc; i++) {

		if (flag_short != NULL) {
			if(!strcmp(arg->flagv[i], flag_short)) {
				return 1;
			}
		}

		if (flag_long != NULL) {
			if(!strcmp(arg->flagv[i], flag_long)) {
				return 1;
			}
		}

		return 0;
	}
	return 0;
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

