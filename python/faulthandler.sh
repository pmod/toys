#!/bin/sh

PYTHONFAULTHANDLER=1 python3 -c "import ctypes; ctypes.string_at(0)"

