#!/bin/sh
rm test
nasm -f elf64 test.s -o test.o
ld test.o -o test -dynamic-linker /lib64/ld-linux-x86-64.so.2 -lc
./test
echo $?