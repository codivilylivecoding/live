#include "main.h"


product_t *catalogue_search_product_by_name(catalogue_t *cat, char *name)
{
    unsigned long target_list_index;
    product_t *target_list;

    target_list_index = compute_index(name, cat->_array_size);

    target_list = cat->_array_of_lists[target_list_index];

    return (search_product_by_name(target_list, name));
}