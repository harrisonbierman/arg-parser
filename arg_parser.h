#ifndef ARG_PARSER_H
#define ARG_PARSER_H
#include <stdlib.h> // size_t


#define MAX_FLAGS 16

struct arg_t{

	char *arg;
	struct arg_t *next;

	int flagc;
	char *flagv[MAX_FLAGS + 1]; // room for NULL terminate
};


int AP_parse(int tokc, char *tokv[], struct arg_t **out_head); // use AP_free()

void AP_free(struct arg_t *a);

#define AP_FOREACH(node, head) \
	for (struct arg_t *node = (head); node != NULL; node = node->next)

// do not need to free pointer taken care of by AP_free
struct arg_t* AP_get(struct arg_t *head, size_t element);

int AP_has_flag(struct arg_t *arg, char *flag_short, char *flag_long);

#endif
