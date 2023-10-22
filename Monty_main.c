#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **op_tokns = NULL;

/**
 * main - the entry point for Monty Interp
 *
 * @argc: the count of arguments passed to the program
 * @argv: pointer to an array of char pointers to arguments
 *
 * Return: (EXIT_SUCCESS) on success (EXIT_FAILURE) on error
 */
int main(int argc, char **argv)
{
    int exitcode = EXIT_SUCCESS;
    FILE *scriptFd = NULL;

    if (argc < 2 || argc >2)
        return (usage_error());

    scriptFd = fopen(argv[1], "r");

    if (!scriptFd)
        return (f_open_error(argv[1]));

    exitcode = exec_monty(scriptFd);

    fclose(scriptFd);
    return (exitcode);
}
