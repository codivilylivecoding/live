#include <stddef.h>

int is_numeric(char *str)
{
    size_t i = 0;

    if (str == NULL)
        return (0);

    if (str[0] == '-')
        i++;

    if (str[i] == '\0')
        return (0);

    while (str[i] >= '0' && str[i] <= '9')
        i++;

    if (str[i] != '\0')
        return (0);

    return (1);
}