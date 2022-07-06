#include "main.h"
#include <stddef.h>


void delete_products(product_t **plist)
{
    product_t *cursor  = NULL, *deleted = NULL;

    cursor = *plist;

    while (cursor)
    {
        deleted = cursor;   
        cursor = cursor->_next;

        delete_product(deleted);
    }

    *plist = NULL;
}