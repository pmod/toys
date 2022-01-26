#
# import module from hello_ext.so which
# exposes method greet() with the help of
# BOOST_PYTHON_MODULE
#
import hello_ext
print(hello_ext.greet())
