#include <shell.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
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
