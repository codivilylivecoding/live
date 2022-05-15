#include "main.h"
#include <stdlib.h>

char *join_paths(const char sep, const char *path1, const char *path2)
{
    size_t i = 0, k = 0;
    size_t len = 0;
    char *joined = NULL;

    while(path1[i++] != '\0')
        ;
    len += i;

    i = 0;
    while (path2[i++] != '\0')
        ;
    len += i;
    len += 1;

    joined = malloc(sizeof(*joined) * (len + 1));

    i = 0;
    while(path1[k])
    {
        joined[i] = path1[k];
        i++;
        k++;
    }

    joined[i++] = sep;
    k = 0;
    while(path2[k])
    {
        joined[i] = path2[k];
        i++;
        k++;
    }
    joined[i] = '\0';
    return (joined);
}
