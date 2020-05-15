#include "monty.h"
#include <string.h>

#define USAGE ("USAGE: monty file\n")
#define FAILOPEN ("Error: Can't open file %s\n")
#define NOMEM ("Error: malloc failed\n")
#define UNKNOWN ("L%d: unknown instruction %s")
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
	FILE *fp;
	int fd, flag = 0;
	size_t n = 0, linecount = 1, i = 0;
	char *buff = NULL;
	stack_t *head = NULL;
	instruction_t code;

	if (argc != 2)
		dprintf(STDERR_FILENO, USAGE), EXIT_F;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		dprintf(STDERR_FILENO, FAILOPEN, argv[1]), EXIT_F;

	fp = fdopen(fd, "r");
	if (fp == NULL)
		dprintf(STDERR_FILENO, NOMEM), EXIT_F;

	while (getline(&buff, &n, fp) != EOF)
	{
		if (!buff)
		{
			dprintf(STDERR_FILENO, NOMEM);
			break;
		}
		while (buff[i] == ' ')
			i++;
		if (*(buff + i) != '\n' && *(buff + i) && strlen(buff) >= 4)
		{
			if (!strncmp(buff + i, "push", 4) && (!strncmp(buff + i,
				"push", 5) || !strncmp(buff + i, "push ", 5)))
				push_it(&head, linecount, buff + 5 + i);
			else
			{
				code = get_func(buff + i);
				if (code.opcode == NULL)
				{
					dprintf(STDERR_FILENO, UNKNOWN,
						(int)linecount, buff + i);
					flag = -1;
					break;
				}
				code.f(&head, linecount);
			}
		}
		linecount++;
		i = 0;
		free(buff);
		buff = NULL;
	}
	free_stack(head);
	if (buff)
		free(buff);
	fclose(fp);
	if (flag == -1)
		return (EXIT_FAILURE);
	else
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
		{"mod", mod_top},
		{"nop", no_op},
		{"#", no_op},
		{"pchar", p_char},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", nop},/*default program, just to prevent errors*/
		{NULL, NULL}
	};

	for (i = 0; op[i].opcode != NULL; i++)
	{
		if (!strncmp(op[i].opcode, func, strlen(op[i].opcode)))
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
