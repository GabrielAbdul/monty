#include "monty.h"

#define NO_ADD (":L%d: can't add, stack too short\n")
#define NO_SUB (":%d: can't sub, stack too short\n")
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

	stack_t *node;
	int count = 0;

	if (!stack || !*stack)
		dprintf(STDERR_FILENO, NO_ADD, line_number), exit(EXIT_FAILURE);

	node = *stack;

	while (node)
	{
		node = node->next;
		count++;
	}

	if (count < 1)
		dprintf(STDERR_FILENO, NO_ADD, line_number), exit(EXIT_FAILURE);

	(*stack)->n += (*stack)->next->n;

	(*stack)->next->next->prev = *stack;
	(*stack)->next = (*stack)->next->next;

}
/*
void sub_top(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (!stack || !*stack)
		dprintf(STDERR_FILENO, NO_SUB, line_number);


	node = *stack;

	while (node)
	{
		node = node->next;
		count++
	}

	if (count < 1)
		dprintf(STDERR_FILENO, NO_ADD, line_number), exit(EXIT_FAILURE);

	(*stack)->next->n -= (*stack)->n;

	(*stack)
}

}*/
