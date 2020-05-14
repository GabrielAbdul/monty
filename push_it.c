#include "monty.h"
#include <string.h>

#define USAGE_INT ("L%u: usage: push integer\n")
#define NOMEM ("Error: malloc failed\n")
/**
 * push_it - pushes an element to the syack
 *
 * @stack: double pointer to head node of doubly linked list (the stack)
 * @line_number: line_number to print for errorws
 * @data: Data to insert in new node
 *
 * Return: Void
 */


void push_it(stack_t **stack, unsigned int line_number, char *data)
{
	stack_t *node = malloc(sizeof(stack_t));
/*	stack_t *searcher;*/
	int num, flag = 0, i, j;
	char *buff;

	if (!stack || !data || data[0] == '\0')
		dprintf(STDERR_FILENO, USAGE_INT, line_number),
			exit(EXIT_FAILURE);
	buff = malloc(strlen(data) + 1);
	for (i = 0; i < (int)strlen(data) + 1; i++)
		buff[i] = '\0';
	if (!node || !buff)
		dprintf(STDERR_FILENO, NOMEM), exit(EXIT_FAILURE);
	for (i = 0, j = 0; data[i]; i++)
	{
		if (!(data[i] >= '0' && data[i] <= '9') && data[i] != ' ')
			break;
		else if (data[i] >= '0' && data[i] <= '9')
		{
			flag = 1;
			buff[j] = data[i];
			j++;
		}
		else if (flag == 1)
			break;
	}
	if (flag == 0)
	{
		free(buff);
		dprintf(STDERR_FILENO, USAGE_INT, line_number),
			exit(EXIT_FAILURE);
	}
	num = atoi(buff);
	node->n = num;
	free(buff);
	if (!*stack)
	{
		*stack = node;
		(*stack)->prev = NULL;
		(*stack)->next = NULL;
		return;
	}

	(*stack)->prev = node;
	node->next = *stack;
	node->prev = NULL;
	*stack = node;
}
