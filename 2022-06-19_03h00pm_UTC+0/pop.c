#include "monty.h"
#include <stddef.h>

stack_t *pop(stack_t **stack)
{
    stack_t *old_top_item  = *stack;

    if (old_top_item != NULL)
    {
        *stack = old_top_item->next;
        old_top_item->next = NULL;
        if (*stack)
            (*stack)->prev = NULL;
    }

    return (old_top_item);
}