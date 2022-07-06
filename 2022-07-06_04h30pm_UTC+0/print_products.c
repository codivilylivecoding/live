#include "main.h"
#include <stdio.h>



void print_products(product_t *list)
{
    product_t *cursor = list;

    while(cursor)
    {
        printf("- name: %s, price: %d\n", cursor->name, cursor->price);
        cursor = cursor->_next;
    }
}