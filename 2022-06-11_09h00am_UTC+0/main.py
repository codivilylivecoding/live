#!/usr/bin/python3.9
import ctypes
my_custom_lib = ctypes.PyDLL("./libFunny.so")

zip_it = my_custom_lib.zip_it
zip_it.restype = ctypes.py_object
zip_it.argtypes = [ctypes.py_object, ctypes.py_object]

print_dict = my_custom_lib.print_dict
print_dict.argtypes = [ctypes.py_object]


zipped = zip_it(["name", "age", "height"], ["Crocodile", 45, 15])
print_dict(zipped)
