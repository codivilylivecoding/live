#include "main.h"
#include <stdlib.h>

catalogue_t *new_catalogue(unsigned long array_size)
{
    catalogue_t *new_cat = malloc(sizeof(catalogue_t));
    unsigned long i = 0;

    if (new_cat == NULL)
        return (NULL);

    new_cat->num_of_products = 0;
    
    new_cat->_g_list = NULL;
    new_cat->_g_list_reversed = NULL;

    new_cat->_array_size = array_size;
    
    new_cat->_array_of_lists = malloc(sizeof(product_t *) * array_size);

    if (new_cat->_array_of_lists == NULL)
    {
        free(new_cat);
        return (NULL);
    }

    while (i < array_size)
    {
        new_cat->_array_of_lists[i] = NULL;
        i++;
    }

    return (new_cat);

}