#ifndef MONTY_H
#define MONTY_H

/* GLOBAL DEFINITIONS */
#define EXIT_F (exit(EXIT_FAILURE))

/*INCLUDES GO HERE*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
/*MANDATORY STRUCTS*/
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*Global Var(s)*/
extern void *to_free[2];

/*PROTOTYPES*/
void push_it(stack_t **stack, unsigned int line_number, char *data);
void p_int(stack_t **stack, unsigned int line_number);
void p_all(stack_t **stack, unsigned int line_number);
void pop_it(stack_t **stack, unsigned int line_number);
void swap_it(stack_t **stack, unsigned int line_number);
void add_top(stack_t **stack, unsigned int line_number);
void sub_top(stack_t **stack, unsigned int line_number);
void mul_top(stack_t **stack, unsigned int line_number);
void div_top(stack_t **stack, unsigned int line_number);
void mod_top(stack_t **stack, unsigned int line_number);
void p_char(stack_t **stack, unsigned int line_number);
void no_op(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
#endif
