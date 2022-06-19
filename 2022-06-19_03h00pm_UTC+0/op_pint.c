#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

void op_pint(stack_t **stack, unsigned int line_number)
{

    if ((*stack) == NULL)
    {
        free_stack(stack);
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);   
}