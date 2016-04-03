#!/bin/sh

echo "compile test prog"
gcc a.c
echo "run test prog"
./a.out
printf "return value = 0x%x\n" $?
echo "run gdb with set-write-on"
gdb --write -q ./a.out -x ./patch_ret.gdb
echo "run patched prog"
./a.out
printf "return value = 0x%x\n" $?

