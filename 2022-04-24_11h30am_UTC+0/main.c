#include <stdio.h>
#include <stdlib.h>

struct  data_item
{
    int value;
    struct data_item *next_data_item;
};
typedef struct data_item data_item_type;

data_item_type *createItem(int value)
{
    data_item_type *new_item = malloc(sizeof(data_item_type));
    if (new_item == NULL)
        return (NULL);

    new_item->value = value;
    new_item->next_data_item = NULL;
    return (new_item);
}

void print_items(data_item_type *item)
{
    while (item != NULL)
    {
        printf("%d\n", item->value);
        item = item->next_data_item;
    }
}


int item_count(data_item_type *item)
{
    int count = 0;
    while (item != NULL)
    {   
        count++;
        item = item->next_data_item;
    }

    return (count);
}

void append(data_item_type **p_first_item, int value)
{
    data_item_type *new_item = createItem(value);
    data_item_type *last_item;

    if (new_item == NULL)
        return;
    /* first->second->third->fourth->new_item->(NULL) */

    if (*p_first_item == NULL)
        *p_first_item = new_item;
    else
    {
        last_item = *p_first_item;
        while (last_item->next_data_item != NULL)
            last_item = last_item->next_data_item;

        last_item->next_data_item = new_item;
    } 
}


void shift(data_item_type **p_first_item, int value)
{
    data_item_type *new_item = createItem(value);

    if (new_item == NULL)
        return;
    /* new_item->first->second->third->fourth-> */

    new_item->next_data_item = *p_first_item;
    *p_first_item = new_item;
}

int main(void)
{
    data_item_type *first_item = NULL;

    // append(&first_item, 56);
   
    shift(&first_item, 1); /* 1 */
    shift(&first_item, 2); /* 2 -> 1 */
    shift(&first_item, 3); /* 3 -> 2 -> 1 */
    shift(&first_item, 4); /* 4 -> 3 -> 2 -> 1 */
    shift(&first_item, 5); /* 5 -> 4 -> 3 -> 2 -> 1 */

    print_items(first_item);

    printf("count: %d\n", item_count(first_item));

    return (0);
}
