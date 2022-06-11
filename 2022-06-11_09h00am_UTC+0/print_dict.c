#include "Python.h"
#include <stdio.h>

void print_dict(PyObject *dictionary)
{
    PyObject *keys = PyDict_Keys(dictionary);
    Py_ssize_t length = PyDict_Size(dictionary);
    Py_ssize_t key_index;
    PyObject *key;

    for (key_index = 0; key_index < length; key_index++)
    {
        key = PyList_GetItem(keys, key_index);
        PyObject_Print(key, stdout, 1);

        fwrite(": ", 1, 2, stdout);
        PyObject_Print(
            PyDict_GetItem(dictionary, key),
            stdout,
            1
        );
        fwrite("\n", 1, 1, stdout);
    }
}
