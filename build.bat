@echo off
:: WinMashup Build Script for GitHub
:: Ensure NASM and GCC (MinGW/Cross-compiler) are in your PATH

echo [WinMashup] Cleaning previous builds...
if exist kernel.bin del kernel.bin
if exist Kernel\*.o del Kernel\*.o

echo [WinMashup] Assembling Bootloader...
nasm -f elf32 Kernel\boot.asm -o Kernel\boot.o

echo [WinMashup] Compiling Kernel...
:: We use -I. so the compiler can resolve includes relative to the root
gcc -m32 -c Kernel\kernel.c -o Kernel\kernel.o -ffreestanding -fno-stack-protector -nostdlib -fno-builtin -I.

echo [WinMashup] Linking...
ld -m elf_i386 -T linker.ld -o kernel.bin Kernel\boot.o Kernel\kernel.o

if exist kernel.bin (
    echo [WinMashup] Build Successful: kernel.bin is ready.
) else (
    echo [WinMashup] Build Failed.
)

pause