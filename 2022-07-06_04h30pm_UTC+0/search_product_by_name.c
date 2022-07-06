#include "main.h"
#include <stddef.h>
#include <string.h>

product_t *search_product_by_name(product_t *list, char *name)
{
    product_t *cursor = NULL;

    cursor = list;

    while (cursor && strcmp(cursor->name, name) != 0)
        cursor = cursor->_next;

    return (cursor);
}