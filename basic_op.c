#include "monty.h"

#define NO_PINT ("L%d: can't pint, stack empty\n")
#define NO_POP ("L%d: can't pop, an empty stack\n")
#define NO_MALLOC ("Error: malloc failed\n")
#define NO_SWAP ("L%d: cant swap, stack too short\n")

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
		dprintf(STDERR_FILENO, NO_MALLOC);

	node = *stack;

	for (; node; node = node->next)
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
		dprintf(STDERR_FILENO, NO_PINT, line_number), free_stack(*stack), EXIT_F;

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
		dprintf(STDERR_FILENO, NO_POP, line_number), free_stack(*stack), EXIT_F;
	node = (*stack)->next;

	(*stack)->next = NULL;
	(*stack)->prev = NULL;
	free(*stack);
	*stack = node;
}

/**
  * swap_it - swaps the top two elemets of the stack
  *
  * @stack: double pointer to the head of a doubly linked list (the stack)
  * @line_number: line number error
  *
  * Return: void
  */
void swap_it(stack_t **stack, unsigned int line_number)
{
	stack_t *node, *nother_node, *tmp;
	int count = 0;

	if (!stack || !*stack)
	{
		dprintf(STDERR_FILENO, NO_SWAP, line_number);
		free_stack(*stack);
	}

	node = *stack;
	nother_node = (*stack)->next;

	while (node)
	{
		node = node->next;
		count++;
	}
	node = *stack;
	if (count < 1)
		dprintf(STDERR_FILENO, NO_SWAP, line_number), free_stack(*stack), EXIT_F;

	tmp = nother_node->next;
	nother_node->next = node;
	nother_node->prev = NULL;
	node->prev = nother_node;
	node->next = tmp;
	tmp->prev = node;
	*stack = nother_node;
}

/**
 * no_op - Does nothing
 *
 * @stack: unused
 * @line_number: unused
 *
 * Return: void
 */
void no_op(__attribute__ ((unused)) stack_t **stack, unsigned int line_number)
{
	(void)line_number;
}
