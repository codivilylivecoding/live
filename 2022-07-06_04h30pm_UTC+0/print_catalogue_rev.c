#include "main.h"
#include <stdio.h>

void print_catalogue_rev(catalogue_t *cat)
{
    product_t *cursor = cat->_g_list_reversed;

    while (cursor)
    {
        printf("- name: %s, price: %d\n", cursor->name, cursor->price);
        cursor = cursor->_g_prev;
    }
}