#include "main.h"
#include <stdlib.h>
#include <string.h>


product_t *new_product(char *name, int price)
{
    product_t *p = malloc(sizeof(product_t));

    if (p == NULL)
        return (NULL);
    
    p->name = strdup(name);
    p->price = price;

    p->_next = NULL;

    p->_g_next = NULL;
    p->_g_prev = NULL;
}