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



	<+0>:	push   ebp
	<+1>:	mov    ebp,esp
	<+3>:	cmp    DWORD PTR [ebp+0x8],0x45d
	<+10>:	jg     0x512 <asm1+37>
	<+12>:	cmp    DWORD PTR [ebp+0x8],0x430
	<+19>:	jne    0x50a <asm1+29>
	<+21>:	mov    eax,DWORD PTR [ebp+0x8]
	<+24>:	add    eax,0x17
	<+27>:	jmp    0x529 <asm1+60>
	<+29>:	mov    eax,DWORD PTR [ebp+0x8]
	<+32>:	sub    eax,0x17
	<+35>:	jmp    0x529 <asm1+60>
	<+37>:	cmp    DWORD PTR [ebp+0x8],0x7cd
	<+44>:	jne    0x523 <asm1+54>
	<+46>:	mov    eax,DWORD PTR [ebp+0x8]
	<+49>:	sub    eax,0x17
	<+52>:	jmp    0x529 <asm1+60>
	<+54>:	mov    eax,DWORD PTR [ebp+0x8]
	<+57>:	add    eax,0x17
	<+60>:	pop    ebp
	<+61>:	ret