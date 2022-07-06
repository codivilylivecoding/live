#include "main.h"
#include <stdio.h>

void print_catalogue(catalogue_t *cat)
{
    
    product_t *cursor = cat->_g_list;

    while (cursor)
    {
        printf("- name: %s, price: %d\n", cursor->name, cursor->price);
        cursor = cursor->_g_next;
    }
}