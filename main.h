#ifndef HEAD_H
#define HEAD_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <dirent.h>
#include <fcntl.h>

extern char **environ;
extern int EXIT_STATUS;

/**
 * struct aliases - aliases structure
 * @name: alias name
 * @value: alias value
 */
typedef struct aliases
{
	char *name;
	char *value;
} aliases;
/**
 * struct cmd_executer - command structure
 * @cmd: cmd
 * @exe_func: func to ptr
 */
typedef struct cmd_executer
{
	char *cmd;
	int (*exe_func)(int, char **, char *, aliases *, int *, char **, char *);
} cmd_executer;
int _fork(char *, char **);
void check_fork_error(char *, char **, char *);
char **_strtok(char *s, char *delim);
int split_line(char *, char *, aliases *, int *);
int _getline(char **);
char *_getenv(char *);
int env(int, char **, char *, aliases *, int *, char **, char *);
int unset(int, char **, char *, aliases *, int *, char **, char *);
void get_cmds(char ***, char *);
int execmd(char **, char *, char *);
void *_calloc(unsigned int, unsigned int);
int args_count(char **);
char *is_valid(char *, char *, char **);
int args_count(char **);
char *check_ops(char **);
int _getalias(aliases *, char *, int);
int echo(char **);
int print_string(int, char *);
int cmd_selector(const char *,
		char **, char *, aliases *, int *, char **, char *);
int change_dir(int, char **, char *, aliases *, int *, char **, char *);
int exit_function(int, char **, char *, aliases *, int *, char **, char *);
int export(int, char **, char *, aliases *, int *, char **, char *);
int _alias(int, char **, char *, aliases *, int *, char **, char *);
void check_alias(char ***arr, aliases *alias, int idx);
int and_handling(char *line, char *name, aliases *alias, int *idx);
int semi_column_handling(char *line, char *name, aliases *alias, int *idx);
char *_memcpy(char *, char *, unsigned int);
void replace_substring(char *, char *, char *);
char *_strcpy(char *, char *);
int _strncmp(const char *, char *, int);
int _strcmp(const char *, char *);
int _read(char **line, char **args);
int exists_within(char c, char *s);
char *_strcat(char *, char *);
char *_strstr(char *, char *);
size_t _strlen(char *);
int to_string(int, unsigned int);
int _atoi(char *);
char *_strpbrk(char *, char *);
void del(char **);
void _free(char **);
int error(char *, char **, char *, int);
void error2(char **args, char *path, int n);
#endif
