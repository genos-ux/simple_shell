#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
/**
 * main - Entry point
 *
 * @valarg: takes value
 * @numArg: Takes value
 * @environ: takes value
 *
 * Return: Always void (success)
 */
int main(int numArg, char **valarg, char **environ)
{
	if (numArg== 1)
	{
		output(valarg, environ);
	}
	return (0);
}
