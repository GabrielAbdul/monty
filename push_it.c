#include "monty.h"

#define USAGE_INT ("L%ui: usage: push integer")

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
	stack_t *searcher;

	if (!stack || !data)
		dprintf(STDERR_FILENO, USAGE_INT, line_number), exit(EXIT_FAILURE);

	if (!node)
		exit(EXIT_FAILURE);

	node->n = atoi(data);
	
	if (!*stack)
	{
		*stack = node;
		(*stack)->prev = NULL;
		(*stack)->next = NULL;

	}
	searcher = *stack;

	while (searcher)
		searcher = searcher->next;

	searcher->next = node;
	node->prev = searcher;
	node->next = NULL;

}
