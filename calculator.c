#include "monty.h"

#define NO_ADD (":L%d: can't add, stack too short\n")
#define NO_SUB (":%d: can't sub, stack too short\n")
#define NO_DIV (":%d: can't div, stack too short\n")
#define NO_MUL (":%d: can't mul, stack too short\n")
#define NO_MOD (":%d: can't mod, stack too short\n")

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

	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
	
}
/**
 * sub_top - subs the top two elements of the stack
 *
 * @stack: double pointer to the head of the stack
 * @line_number: line number for error codes
 *
 * Return: void
 */

void sub_top(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	int count = 0;

	if (!stack || !*stack)
		dprintf(STDERR_FILENO, NO_SUB, line_number);


	node = *stack;

	while (node)
	{
		node = node->next;
		count++;
	}

	if (count < 1)
		dprintf(STDERR_FILENO, NO_SUB, line_number), exit(EXIT_FAILURE);

	(*stack)->next->n -= (*stack)->n;

	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
	
}

/**
 * add_top - adds the top two elements of the stack
 *
 * @stack: double pointer to the head of the stack
 * @line_number: line number for error codes
 *
 * Return: void
 */

void div_top(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	int count = 0;

	if (!stack || !*stack)
		dprintf(STDERR_FILENO, NO_DIV, line_number);


	node = *stack;

	while (node)
	{
		node = node->next;
		count++;
	}

	if (count < 1)
		dprintf(STDERR_FILENO, NO_DIV, line_number), exit(EXIT_FAILURE);

	(*stack)->next->n /= (*stack)->n;

	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mul_top - adds the top two elements of the stack
 *
 * @stack: double pointer to the head of the stack
 * @line_number: line number for error codes
 *
 * Return: void
 */

void mul_top(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	int count = 0;

	if (!stack || !*stack)
		dprintf(STDERR_FILENO, NO_MUL, line_number);


	node = *stack;

	while (node)
	{
		node = node->next;
		count++;
	}

	if (count < 1)
		dprintf(STDERR_FILENO, NO_MUL, line_number), exit(EXIT_FAILURE);

	(*stack)->next->n *= (*stack)->n;

	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
