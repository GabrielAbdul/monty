#include "monty.h"

#define USAGE_INT ("L%u: usage: push integer\n")

/**
 * push_it - pushes an element to the syack
 *
 * @stack: double pointer to head node of doubly linked list (the stack)
 * @line_number: line_number to print for errorws
 *
 * Return: Void
 */


void push_it(stack_t **stack, unsigned int line_number, char *data)
{
	stack_t *node = malloc(sizeof(stack_t));
/*	stack_t *searcher;*/
	int num, flag = 0, i;

	if (!stack || !data)
		dprintf(STDERR_FILENO, USAGE_INT, line_number),
			exit(EXIT_FAILURE);

	if (!node)
		exit(EXIT_FAILURE);
	for (i = 0; data[i]; i++)
	{
		if (data[i] >= '0' && data[i] <= '9' && flag != 2)
			flag = 1;
		else if (data[i] != ' ' && data[i] != '\n')
			flag = 2;
	}
	if (flag == 0 || flag == 2)
		dprintf(STDERR_FILENO, USAGE_INT, line_number),
			exit(EXIT_FAILURE);
	num = atoi(data);
	printf("data: %d\n", num);
	node->n = num;

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
