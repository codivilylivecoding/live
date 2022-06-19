#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

stack_t *new_stack_t(int n)
{
    stack_t *new_item = malloc(sizeof(stack_t));

    if (new_item == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_item->n = n;
    new_item->prev = NULL;
    new_item->next = NULL;

    return (new_item);
}