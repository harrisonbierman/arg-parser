#ifndef ARG_PARSER_H
#define ARG_PARSER_H


#define MAX_FLAGS 16

struct arg_t{

	char *arg;
	struct arg_t *next;

	int flagc;
	char *flagv[MAX_FLAGS + 1]; // room for NULL terminate
};

struct arg_t* AP_new(int tokc, char *tokv[]); // use AP_free()

void AP_free(struct arg_t *a);

#endif
