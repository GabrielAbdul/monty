#include "monty.h"

#define USAGE ("USAGE: monty file\n")
#define FAILOPEN ("Error: Can't open file %s\n")
int _strcmp(char *s1, char *s2);
instruction_t get_func(char *func);
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
	size_t n = 1, linecount = 1;
	char *buff = malloc(1);

	if (argc != 2)
		dprintf(STDERR_FILENO, USAGE), exit(EXIT_FAILURE);
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	  dprintf(STDERR_FILENO, FAILOPEN, argv[1]), exit(EXIT_FAILURE);
	while (1)
	{
		printf("Before getline\n");
		if (getline(&buff, &n, fd) == EOF)
		{
			printf("Somehow in getline");
			return(EXIT_SUCCESS);
		}
		printf("linecount: %d, buff: %s", (int)linecount, buff);
		printf("After getline\n");
		linecount++;
	}
	return (0);
}

/**
 * get_func - returns a pointer to a requested function
 * @func:  char * containing the requested opcode
 *
 * Return: Pointer to requested function
 */
instruction_t get_func(char *func)
{
	int i;

	instruction_t op[] = {
		{"pall", p_all},
		{"pint", p_int},
		{NULL, NULL}
	};

	for (i = 0; op[i].opcode != NULL; i++)
	{
		if (!_strcmp(op[i].opcode, func))
			return (op[i]);
	}
	return (op[i]);
}
/**
 * _strcmp - compares two strings
 *@s1: string 1 to be compared
 *@s2: string 2 to be compared
 * Return: a positive, negative, or 0 number based on the first different char
 */
int _strcmp(char *s1, char *s2)
{
	while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 - *s2);
}
