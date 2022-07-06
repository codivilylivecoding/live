#include "main.h"



unsigned long compute_index(char *name, unsigned long size)
{
    return hash(name) % size;
}