C:\Dev-Cpp\bin\g++ -c c.cpp -o c.o
nasm asm.s -f win32 -o asm.o
C:\Dev-Cpp\bin\g++ asm.o c.o -o out.exe