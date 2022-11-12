#ifndef MAIN_H
#define MAIN_H

/**
 * struct path - a struct item for linked list of paths
 * @path: the node path as a string
 * @next: pointer to next list node
 *
 * Description: this is used for iterating all the paths in the sys
 */
typedef struct path
{
	char *path;
	struct path *next;
} path_t;

/**
 * struct env - a struct attaching each shell builtin to a callable name
 * @name: the callable name of the builtin
 * @cmd: a pointer to the builtin function
 *
 * Description: gives every builtin function a name for search purposes
 */
typedef struct env
{
	char *name;
	void (*cmd)(void);
} env_builtin;

int run_command(const char *, const char *);
char **str_tok(char *, char *);
int _setenv(const char *name, const char *value, int overwrite);
path_t *build_path_list(void);
void free_path_list(path_t *);
char *_which(char *);

/* builtins.h */
void *get_builtin(char *);


/* utils */
int startswith(char *, char *);
int _strcmp(char *s1, char *s2);
int is_equal(char *s1, char *s2);
char *malloc_str(char *);
#endif
