#include "main.h"
#include <stdlib.h>


void delete_product(product_t *p)
{
    free(p->name);
    free(p);
}