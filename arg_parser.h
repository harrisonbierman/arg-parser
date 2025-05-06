#ifndef ARG_PARSER_H
#define ARG_PARSER_H

typedef struct arg {
	char *arg;
	int optc;
	char **opt;

}arg_t;

struct arg_parse_t {
	int argc;
	arg_t **argv;
};

struct arg_parse_t AP_new(int argc, char *argv[]);

#endif
