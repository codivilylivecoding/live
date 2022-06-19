#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

void op_pop(stack_t **stack, unsigned int line_number)
{
    stack_t *popped = pop(stack);
    if (popped == NULL)
    {
        free_stack(stack);
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    free_stack_t(popped);
}