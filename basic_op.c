#include "monty.h"

#define NO_PINT ("L%d: can't pint, stack empty\n")
#define NO_POP ("L%d: can't pop, an empty stack\n")

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
/**
 * p_int - prints the value at the top of the stack
 *
 * @stack: double pointer to the head of a doublky linked list (the stack)
 * @line_number: unused
 *
 * Return: void
 */
void p_int(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (!*stack || !stack)
		dprintf(STDERR_FILENO, NO_PINT, line_number);

	printf("%d\n", (*stack)->n);
}
/**
 * pop_it - removes the top element of the stack
 *
 * @stack: double pointer to the head of a doubly linked list (the stack)
 * @line_number: line number error
 *
 * Return: void
 */

 void pop_it(stack_t **stack, unsigned int line_number)
 {
 	stack_t *node;

 	if (!stack || (!*stack))
 		dprintf(STDERR_FILENO, NO_POP, line_number);

 	node = (*stack)->next;

 	(*stack)->next = NULL;
 	(*stack)->prev = NULL;

 	*stack = node;
 }
