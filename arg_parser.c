/**
 * Argument Parsing API for CLI tools
 */

#include "arg_parser.h"
#include <stdlib.h>

struct arg_t* AP_new(int tokc, char *tokv[]) {

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

	size_t i = 0;
	AP_FOREACH(cur, head) {
		cur->elmt = i++;
	}

	return(head); // use AP_free();
}

void AP_free(struct arg_t *head) {
	struct arg_t *cur = head;
	while(cur){
		struct arg_t *next = cur->next;
		free(cur);
		cur = next;
	}
}

struct arg_t* AP_get(size_t element, struct arg_t *head) {
	AP_FOREACH(cur, head) {
		if(cur->elmt == element) return cur;
	}
	return NULL;
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

