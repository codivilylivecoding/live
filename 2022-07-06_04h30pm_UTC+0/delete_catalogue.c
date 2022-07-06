#include "main.h"
#include <stdlib.h>


void delete_catalogue(catalogue_t **cat)
{
    unsigned long i = 0;
    
    while (i < (*cat)->_array_size)
    {
        delete_products(&((*cat)->_array_of_lists[i]));
        i++;
    }

    free((*cat)->_array_of_lists);
    free(*cat);
    
    *cat = NULL;
}