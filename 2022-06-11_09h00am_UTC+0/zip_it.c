#include "Python.h"

PyObject *zip_it(PyObject *keys, PyObject *values)
{
    Py_ssize_t length = PyList_Size(keys);
    Py_ssize_t index = 0;
    PyObject *zipped = PyDict_New();

    for (index = 0; index < length; index++)
    {
        PyDict_SetItem(
            zipped,
            PyList_GetItem(keys, index),
            PyList_GetItem(values, index)
        );
    }
    
    return (zipped);
}
