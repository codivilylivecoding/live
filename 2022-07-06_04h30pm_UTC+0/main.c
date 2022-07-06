#include "main.h"
#include <stdio.h>
#include <stddef.h>

int main(void)
{

    catalogue_t *cat = new_catalogue(1024);
    product_t *prod = NULL;

    catalogue_add_product(cat, "Cow Milk", 32);
    catalogue_add_product(cat, "Orange Juice", 45);
    catalogue_add_product(cat, "Peanut butter", 100);
    catalogue_add_product(cat, "Banana", 10);
    catalogue_add_product(cat, "Mango", 5);
    catalogue_add_product(cat, "Strawberry", 150);
    catalogue_add_product(cat, "Orange", 105);
    catalogue_add_product(cat, "Pineapple", 200);

    print_catalogue_rev(cat);

    delete_catalogue(&cat);

    return (0);
}