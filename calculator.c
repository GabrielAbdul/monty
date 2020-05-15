#include "monty.h"

#define NO_ADD (":L%d: can't add, stack too short\n")
#define NO_SUB ("L:%d: can't sub, stack too short\n")
#define NO_DIV ("L:%d: can't div, stack too short\n")
#define NO_MUL ("L:%d: can't mul, stack too short\n")
#define NO_MOD ("L:%d: can't mod, stack too short\n")
#define DIV_0 ("L:%d division by zero\n")

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
	{
		dprintf(STDERR_FILENO, NO_ADD, line_number), free_stack(*stack), EXIT_F;
		free((FILE *)to_free[0]);
		free((char *)to_free[1]);
	}

	node = *stack;

	while (node)
	{
		node = node->next;
		count++;
	}

	if (count < 1)
	{
		dprintf(STDERR_FILENO, NO_ADD, line_number), free_stack(*stack), EXIT_F;
		free((FILE *)to_free[0]);
		free((char *)to_free[1]);
	}

	(*stack)->next->n += (*stack)->n;

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
	{
		dprintf(STDERR_FILENO, NO_SUB, line_number), free_stack(*stack), EXIT_F;
		free((FILE *)to_free[0]);
		free((char *)to_free[1]);

	}

	node = *stack;

	while (node)
	{
		node = node->next;
		count++;
	}

	if (count < 1)
	{
		dprintf(STDERR_FILENO, NO_SUB, line_number), free_stack(*stack), EXIT_F;
		free((FILE *)to_free[0]);
		free((char *)to_free[1]);
	}
	(*stack)->next->n -= (*stack)->n;

	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * div_top - adds the top two elements of the stack
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
	{
		dprintf(STDERR_FILENO, NO_DIV, line_number), free_stack(*stack), EXIT_F;
		free((FILE *)to_free[0]);
		free((char *)to_free[1]);
	}


	node = *stack;

	while (node)
	{
		node = node->next;
		count++;
	}

	if (count < 1)
	{
		dprintf(STDERR_FILENO, NO_DIV, line_number), free_stack(*stack), EXIT_F;
		free((FILE *)to_free[0]);
		free((char *)to_free[1]);

	}

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
	{
		dprintf(STDERR_FILENO, NO_MUL, line_number), free_stack(*stack), EXIT_F;
		free((FILE *)to_free[0]);
		free((char *)to_free[1]);

	}


	node = *stack;

	while (node)
	{
		node = node->next;
		count++;
	}

	if (count < 1)
	{
		dprintf(STDERR_FILENO, NO_MUL, line_number), free_stack(*stack), EXIT_F;
		free((FILE *)to_free[0]);
		free((char *)to_free[1]);
	}

	(*stack)->next->n *= (*stack)->n;

	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * mod_top - Mods top element with second element of stack
 *
 * @stack: double pointer to head of the stack
 * @line_number: line number to output for errors
 *
 * Return: void
 */
void mod_top(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	int count = 0;

	if (!stack || !*stack)
	{
		dprintf(STDERR_FILENO, NO_MOD, line_number), free_stack(*stack), EXIT_F;
		free((FILE *)to_free[0]);
		free((char *)to_free[1]);

	}

	if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO, DIV_0, line_number), free_stack(*stack), EXIT_F;
		free((FILE *)to_free[0]);
		free((char *)to_free[1]);

	}

	node = *stack;

	while (node)
	{
		node = node->next;
		count++;
	}

	if (count < 1)
	{
		dprintf(STDERR_FILENO, NO_MOD, line_number), free_stack(*stack), EXIT_F;
		free((FILE *)to_free[0]);
		free((char *)to_free[1]);

	}
	(*stack)->next->n %= (*stack)->n;
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
