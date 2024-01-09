#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <sys/wait.h>
#include <limits.h>

extern char **environ;

void execute_command(char **commands, char **envp, int *status);
int find_path(char *command, char **full_path);
void wait_child_process(int *status);
char *getenv(const char *path);
void print_env_variable(void);
void handle_getline_error(char *line);

/* exit_shell */
void handle_exit_status(int my_status, char **single_command,
char **token, int *status);
void handle_custom_exit(int my_status, char **commands,
char *line, int *status);


/* shell.c */
void begin_shell(void);
ssize_t read_command(char **line, size_t *size_line);
void write_exit_error(char *number);
void write_error(char *command);
void free_array(char **array);

/* main */
int main(void);
void non_interactive_mode(char *token, int *status);
char **tokenize_string(char *str, char *delimiters);

/* strings */
char *_strdup(const char *src);
int _strlen(char *str);
int _strcmp(char *s1, char *s2);
int _atoi(char *s);
void str_reverse(char *string);

#endif
