#include "monty.h"
#include <stddef.h>
#include <stdlib.h>

void free_stack(stack_t **stack)
{
    stack_t *freed_item = NULL;

    while (*stack)
    {
        freed_item = *stack;
        *stack = (*stack)->next;
        free(freed_item);
    }
}