#include "monty.h"
#include <stdio.h>

void op_pall(stack_t **stack, unsigned int line_number)
{
    stack_t *cursor = *stack;

    (void) line_number;
    
    while(cursor)
    {
        printf("%d\n", cursor->n);
        cursor = cursor->next;
    }
}