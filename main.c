#include "monty.h"

#define USAGE ("USAGE: monty file\n")
#define FAILOPEN ("Error: Can't open file %s\n")
/**
 * main - Entrypoint for the monty interpreter function
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	FILE *fd;
	ssize_t n, linecount = 1;
	char *buff;

	if (argc != 2)
		dprintf(STDERR_FILENO, USAGE), exit(EXIT_FAILURE);
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	  dprintf(STDERR_FILENO, FAILOPEN, argv[1]), exit(EXIT_FAILURE);
	while (1)
	{
		printf("Before getline\n");
		if (getline(&buff, &n, fd) == EOF)
			exit(EXIT_SUCCESS);
		printf("buff: %s\n", buff);
		printf("After getline\n");
		linecount++;
	}
}

/**
 * get_func - returns a pointer to a requested function
 * @func:  char * containing the requested opcode
 *
 * Return: Pointer to requested function
 */
instruction_t *get_func(char *func)
{
	
}

