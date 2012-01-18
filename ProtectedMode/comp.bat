nasm prot.s -o asm.bin
C:\\Dev-Cpp\\bin\\gcc.exe -c func.c -o temp.obj
ld --script ldscript temp.obj -o cpp.obj
objcopy -O binary cpp.obj cpp.bin
copy /b asm.bin + cpp.bin final.bin