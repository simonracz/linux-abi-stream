# Linux ABI
Code created during recording the [Linux ABI - Syscalls in Assembly and Calling Assembly from C](https://youtu.be/s9IZ9QT5yhw) video

# Compiling the Assembly Library
```
nasm -felf64 call_me.asm -o call_me.o
gcc -c -std=gnu17 -g ./call_me_c.c -o ./call_me_c.o
ld -o call_me ./call_me.o ./call_me_c.o -e begin
```
