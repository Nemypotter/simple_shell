#include "shell.h"

/**
 * begin_shell - Starts the shell's main loop
 *
 * Description: Initializes the shell, handles user input,
 * tokenizes cmds and executes them.
 * Return: Void
 */
void begin_shell(void)
{
	char *line = NULL, **commands, *envp[] = {NULL};
	size_t size_line = 0;
	ssize_t nread;
	int status = 0;

	while (1)
	{
		nread = read_command(&line, &size_line);
		if (nread == -1)
			handle_getline_error(line);
		commands = tokenize_string(line, " \n\t");
		if (commands[0])
		{
			if (!_strcmp(commands[0], "exit"))
			{
				if (commands[1])
				{
					int my_status = _atoi(commands[1]);

					handle_custom_exit(my_status, commands, line, &status);
				}
				else
				{
					free(line);
					free_array(commands);
					exit(status);
				}
			}
			else if (!_strcmp(commands[0], "env"))
			{
				print_env_variable();
				status = 0;
			}
			else
				execute_command(commands, envp, &status);
		}
		free_array(commands);
		free(line);
		line = NULL;
	}
}


/**
 * read_command - Reads a line of command from the user
 * @line: Line buffer to be stored command
 * @size_line: Size of line buffer
 *
 * Return: The size of the line
 */
ssize_t read_command(char **line, size_t *size_line)
{
	write(STDOUT_FILENO, "#cisfun$ ", 9);
	return (getline(line, size_line, stdin));
}

/**
 * write_exit_error - Writes an error message to STDERR
 *
 * @number: The number
 * Description: Writes an error message
 */
void write_exit_error(char *number)
{
	write(STDERR_FILENO, "./hsh: 1: exit: Illegal number: ", 32);
	write(STDERR_FILENO, number, _strlen(number));
	write(STDERR_FILENO, "\n", 1);
}

/**
 * write_error - Writes an error message to STDERR
 *
 * @command: The command
 * Description: Writes an error message
 */
void write_error(char *command)
{
	write(STDERR_FILENO, "./hsh: 1: ", 10);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, ": not found\n", 12);
}

/**
 * free_array - Frees memory allocated for an array of strings.
 * @array: A pointer to the allocated array of strings.
 *
 * This function frees the memory allocated for an array of strings.
 */
void free_array(char **array)
{
	int i;

	if (!array)
		return;
	for (i = 0; array[i] != NULL; i++)
	{
		free(array[i]);
	}
	free(array);
}
