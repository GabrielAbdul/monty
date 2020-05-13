#include "monty.h"
#include <string.h>

#define USAGE ("USAGE: monty file\n")
#define FAILOPEN ("Error: Can't open file %s\n")
int _strcmp(char *s1, char *s2);
instruction_t get_func(char *func);
void free_stack(stack_t *stack);
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
	stack_t *head = NULL;
	instruction_t code;

	if (argc != 2)
		dprintf(STDERR_FILENO, USAGE), exit(EXIT_FAILURE);
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	  dprintf(STDERR_FILENO, FAILOPEN, argv[1]), exit(EXIT_FAILURE);
	while (1)
	{
		if (getline(&buff, &n, fd) == EOF)
		{
			break;
		}
		while(*buff == ' ')
			buff++;
		if (!strncmp(buff, "push", 4))
			push_it(&head, linecount, buff + 5);
		else
		{
			code = get_func(buff);
			if (code.opcode == NULL)
			{
				printf("FAILURE\n");
				exit(EXIT_FAILURE);
			}
			printf("\nOpcode: %s\n", code.opcode);
			code.f(&head, linecount);
		}
		/*printf("linecount: %d, buff: %s", (int)linecount, buff);*/
		linecount++;
	}
	free_stack(head);
	free(buff);
	fclose(fd);
	return (EXIT_SUCCESS);
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
		{"swap", swap_it},
		{"pop", pop_it},
		{"add", add_top},
		{"sub", sub_top},
		{"div", div_top},
		{"mul", mul_top},
		{"nop", no_op},
		{"#", no_op},
		{NULL, NULL}
	};

	for (i = 0; op[i].opcode != NULL; i++)
	{
		if (!strncmp(op[i].opcode, func, strlen(op[i].opcode) - 1))
			return (op[i]);
	}
	return (op[i]);
}
/**
 * free_stack - frees a stack
 * @stack: stack to be freed
 *
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
