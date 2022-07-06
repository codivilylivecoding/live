#include "main.h"
#include <stddef.h>


product_t *add_product(product_t **plist, char *name, int price)
{
    product_t *new_prod = new_product(name, price);
    product_t *cursor = NULL;

    if (!new_prod)
        return (NULL);

    cursor = *plist;

    if (cursor)
        new_prod->_next = cursor;

    *plist = new_prod;

    return (new_prod);
}