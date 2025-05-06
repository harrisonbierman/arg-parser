#ifndef ARG_PARSER_H
#define ARG_PARSER_H


struct arg_t{

	char *arg;
	struct arg_t *next;

	int flagc;
	char *flagv[512];

};

struct arg_t* AP_new(int tokc, char *tokv[]);

#endif
