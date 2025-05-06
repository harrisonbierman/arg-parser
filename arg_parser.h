#ifndef ARG_PARSER_H
#define ARG_PARSER_H
#include <stdlib.h> //size_t


#define MAX_FLAGS 16

struct arg_t{

	char *arg;
	struct arg_t *next;

	int flagc;
	char *flagv[MAX_FLAGS + 1]; // room for NULL terminate
};

struct arg_t* AP_new(int tokc, char *tokv[]); // use AP_free()

void AP_free(struct arg_t *a);

#define AP_FOREACH(node, head) \
	for (struct arg_t *node = (head); node != NULL; node = node->next)

// do not need to free pointer taken care of by AP_free
struct arg_t* AP_get(size_t element, struct arg_t *head);

int AP_has_flag(char *flag_short, char *flag_long, struct arg_t *arg);

#endif
