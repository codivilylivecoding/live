#include "Python.h"
#include <stdio.h>
#include <unistd.h>

void print_it(PyObject *op)
{
    PyObject_Print(op, stdout, 1);
}
