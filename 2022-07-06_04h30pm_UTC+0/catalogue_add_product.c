#include "main.h"

void catalogue_add_product(catalogue_t *cat, char *name, int price)
{
    unsigned long target_list_index;
    product_t **ptarget_list;
    product_t *new_prod, *cursor;

    target_list_index = compute_index(name, cat->_array_size);

    ptarget_list = &(cat->_array_of_lists[target_list_index]);

    new_prod = add_or_update_product(ptarget_list, name, price);

    if (new_prod)
    {
        cat->num_of_products += 1;

        cursor = cat->_g_list;
        
        if (cursor)
        {
            while (cursor->_g_next)
            {
                if (cursor == new_prod)
                    return;
                cursor = cursor->_g_next;
            }
        }

        if (cursor)
        {
            cursor->_g_next = new_prod;
            new_prod->_g_prev = cursor;
        }
        else
            cat->_g_list = new_prod;
            
        cat->_g_list_reversed = new_prod;
    }
}