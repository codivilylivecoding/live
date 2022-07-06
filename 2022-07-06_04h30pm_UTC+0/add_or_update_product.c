#include "main.h"
#include <stddef.h>

product_t *add_or_update_product(product_t **plist, char *name, int price)
{
    product_t *prod = NULL;

    prod = search_product_by_name(*plist, name);

    if (prod)
    {
        prod->price = price;
        return (prod);
    }
    
    return add_product(plist, name, price);
}