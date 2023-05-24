#include "S_SHell.h"
/**
 * main - Entry point
 *
 *@environ: takes environment character
 *@Valarg: takes argument vector
 *@argNum: takes argument count
 *
 * Return: Always 0 (success)
 */
int main(int argNum, char **valarg, char **environ)
{
        if (argNum == 1)
        {
                output( valarg, environ);
        }
        return (0);
}

