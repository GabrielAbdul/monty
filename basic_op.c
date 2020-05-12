#include "monty.h"

#define USAGE ("L<line_+number>: usage: push integer")
/**
 * push_it - pushes an element to the syack
 *
 * @stack: double pointer to head node of doubly linked list (the stack)
 * @line_number: 
 *
 * Return: Void
 */

 
void push_it(stack_t **stack, int data)
{
	stack_t *node = malloc(sizeof(stack_t));
	stack_t *searcher;

	if ((!*stack) || (!stack) || (!node))
		dprintf(STDERR_FILENO, USAGE), exit(EXIT_FAILURE);

	searcher = *stack

	while (searcher)
		searcher = searcher->next;

	searcher->next = node;
	node->prev = searcher;
	node->next = NULL;
	node->n = data;

}
