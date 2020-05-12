#include "monty.h"


/**
 * add_top - adds the top two elements of the stack
 *
 * @stack: double pointer to the head of the stack
 * @line_number: line number for error codes
 *
 * Return: void
 */
void add_top(stack_t **stack, unsigned int line_number)
{

	if (!stack || !*stack)
		dprintf(STDERR_FILENO, NO_ADD, line_number), exit(EXIT_FAILURE);

	(*stack)->n += (*stack)->next->n;

	(*stack)->next->next->prev = *stack;
	(*stack)->next = (*stack)->next->next;

}
