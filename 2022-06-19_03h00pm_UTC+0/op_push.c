#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

void op_push(stack_t **stack, unsigned int line_number, char *arg)
{

    /* check if arg is an int */
    if (!is_numeric(arg))
    {
        free_stack(stack);
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    push(stack, atoi(arg));
}