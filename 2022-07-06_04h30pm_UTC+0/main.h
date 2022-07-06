#ifndef MAIN_H
#define MAIN_H

typedef struct product
{
    char *name;
    int price;

    /* field members for singly linked list */
    struct product *_next;

    struct product *_g_next;
    struct product *_g_prev;
} product_t;

product_t *new_product(char *name, int price);

void delete_product(product_t *p);

product_t *add_product(product_t **plist, char *name, int price);

product_t *search_product_by_name(product_t *list, char *name);

int update_product_price(product_t *list, char *name, int new_price);

void print_products(product_t *list);

void delete_products(product_t **plist);

product_t *add_or_update_product(product_t **plist, char *name, int price);

unsigned long compute_index(char *name, unsigned long size);

unsigned long hash(char *name);

/********************************/
typedef struct catalogue
{
    int num_of_products;

    /* fields for hash table */
    int _array_size;
    product_t **_array_of_lists;

    /* fields for global list */
    product_t *_g_list; /* head */
    product_t *_g_list_reversed; /* tail */
} catalogue_t;

catalogue_t *new_catalogue(unsigned long arr_size);

void delete_catalogue(catalogue_t **cat);

void catalogue_add_product(catalogue_t *cat, char *name, int price);

product_t *catalogue_search_product_by_name(catalogue_t *cat, char *name);

void print_catalogue(catalogue_t *cat);

void print_catalogue_rev(catalogue_t *cat);


#endif /* MAIN_H */