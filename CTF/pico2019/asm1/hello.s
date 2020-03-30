/* hello.s 64bit */

.intel_syntax noprefix
.globl _start

_start:
// write(1, "hello, world!!!\n", 16)
   xor rax, rax
   xor rdi, rdi
   xor rdx, rdx

   inc rax
   inc rdi

   mov rsi, 0x0a212121646c726f
   push rsi
   mov rsi, 0x77202c6f6c6c6568
   push rsi
   mov rsi, rsp

   push 0x10
   pop rdx
   syscall

// exit(1)
   push 0x3c
   pop rax
   syscall
