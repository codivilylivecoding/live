#include "main.h"


int update_product_price(product_t *list, char *name, int new_price)
{

    product_t *prod = search_product_by_name(list, name);

    if (prod)
    {
        prod->price = new_price;
        return (1);
    }

    return (0);
}