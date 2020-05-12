#include "monty.h"

#define NO_PINT ("L<line_number>: can't pint, stack empty\n")

/**
 * p_all - print all values on the stack
 *
 * @stack: double pointer to the head of a doubly linked list (the stack)
 * @line_number: unused
 *
 * Return: void
 */

void p_all(stack_t **stack, unsigned int line_number)
{
 	stack_t *node;

	(void)line_number;
 	if (!(stack) || (!(*stack)))
	{
		exit(EXIT_FAILURE);
	}

 	node = *stack;

 	for(; node; node = node->next)
 		printf("%d\n", node->n);

}

void p_int(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (!*stack || !stack)
		dprintf(STDERR_FILENO, NO_PINT);

	printf("%d\n", (*stack)->n);
}
