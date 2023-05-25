#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
/**
 * output - This function creates a simple shell with
 * basic commands running
 *
 * @environ: environment variables
 *
 * Return: Always void (success)
 */
void output(char **environ)
{

	char *ptr = NULL;
	ssize_t buffer;
	size_t ptrSize = 0;
	pid_t minPID;

	while (1)
	{
		printf("#cisfun$ ");

	buffer = getline(&ptr, &ptrSize, stdin);
	if (buffer == -1)
	{
		free(ptr);
		exit(EXIT_FAILURE);
	}

	size_t length = strlen(ptr);
	if (length > 0 && ptr[length - 1] == '\n')
		ptr[length - 1] = '\0';

	char *cmd = strtok(ptr, " ");
	char **args = malloc(sizeof(char *) * (length / 2 + 1));
	int argCount = 0;
	while (cmd != NULL)
	{
		args[argCount++] = cmd;
		cmd = strtok(NULL, " ");
	}
	args[argCount] = NULL;

	minPID = fork();
	if (minPID == -1)
	{
		free(ptr);
		free(args);
		exit(EXIT_FAILURE);
	}
	else if (minPID == 0)
	{
		if (execve(args[0], args, environ) == -1)
			printf("%s: No such file or directory\n", args[0]);
		free(ptr);
		free(args);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
		free(args);
	}
	}
}
/**
 * output - Entry Point
 *
 * @environ: environment variables
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	char *environ[] = {NULL}; 
	output(environ);
	return 0;
}

