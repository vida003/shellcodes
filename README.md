# Requirements: old kernel, gcc, gcc-multillib, nasm, ld

### Shellcode 25 bytes - execve("/bin/sh", NULL, NULL); from linux x86_64
![image](https://user-images.githubusercontent.com/77762068/129826615-7670fa60-91d2-4dbf-a8f3-3feab7ffcacd.png)

### Shellcode 33 bytes - execve(xor("/bin/sh", 0x41414141), NULL, NULL); from linux x86_64
![image](https://user-images.githubusercontent.com/77762068/129826090-3b20c8fa-dee7-48c2-afdc-1a017ab82a2e.png)

### Shellcode 21 bytes - execve("/bin/sh", NULL, NULL); from linux x86
![image](https://user-images.githubusercontent.com/77762068/129827033-255ddbda-9a20-489c-a196-8da784ae1014.png)

### Shellcode 26 bytes - jmp execve("/bin/sh", NULL, NULL); from linux x86
![image](https://user-images.githubusercontent.com/77762068/129828351-642d3867-da90-491e-81c0-d95fd0f70c5c.png)

### Shellcode 42 bytes - execve("/bin/cat", "/bin/cat /etc/passwd", NULL); from linux x86
![image](https://user-images.githubusercontent.com/77762068/129829358-70ebcbbf-841c-4e70-9aaf-3a59214f56df.png)
