#include "monty.h"
#include <stddef.h>


stack_t *push(stack_t **stack, int n)
{
    stack_t *new_top_item = new_stack_t(n);

    if (new_top_item == NULL)
        return (NULL);
    
    new_top_item->next = *stack;
    if (*stack)
        (*stack)->prev = new_top_item;
    
    *stack = new_top_item;

    return (new_top_item);
}