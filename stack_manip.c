#include "monty.h"

/**
 * rotl - rotates the stack to the top
 *
 * Return: void
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	int count = 0;
	stack_t *tmp, *head;

	/*No error check because instructions say this never fails*/
	(void)line_number;/*Unused due to no errors*/
	tmp = *stack;
	for (; tmp->next != NULL; tmp = tmp->next)
		count++;
	if (count <= 1)
		return;
	tmp = *stack;
	(*stack)->next->prev = NULL;
	head = (*stack)->next;
	for (; (*stack)->next != NULL; *stack = (*stack)->next)
		;
	(*stack)->next = tmp;
	tmp->prev = (*stack);
	tmp->next = NULL;
	*stack = head;
}
