#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
/**
 * output - This function creates a simple shell with
 * basic commands running
 *
 * @valarg: command arguments
 * @environ: environment variables
 *
 * Return: Always void (success)
 */
void output(char **valarg, char **environ)
{
	char *ptr = NULL;
	ssize_t buffer;
	int state;
	size_t length, ptrSize = 0;
	char *numArg[] = {NULL, NULL};
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

		length = strlen(ptr);
		if (length > 0 && ptr[length - 1] == '\n')
			ptr[length - 1] = '\0';

		numArg[0] = ptr;
		minPID = fork();
		if (minPID == -1)
		{
			free(ptr);
			exit(EXIT_FAILURE);
		}
		else if (minPID == 0)
		{
			if (execve(numArg[0], valarg, environ) == -1)
				printf("%s: No such file or directory\n", valarg[0]);
			free(ptr);
			exit(EXIT_FAILURE);
		}
		else
			wait(&state);
	}
}
