; Multiboot header for GRUB
MBOOT_PAGE_ALIGN    equ 1<<0
MBOOT_MEM_INFO      equ 1<<1
MBOOT_HEADER_MAGIC  equ 0x1BADB002
MBOOT_HEADER_FLAGS  equ MBOOT_PAGE_ALIGN | MBOOT_MEM_INFO
MBOOT_CHECKSUM      equ -(MBOOT_HEADER_MAGIC + MBOOT_HEADER_FLAGS)

[BITS 32]
[GLOBAL mboot]
[EXTERN code]
[EXTERN bss]
[EXTERN end]

mboot:
    dd  MBOOT_HEADER_MAGIC
    dd  MBOOT_HEADER_FLAGS
    dd  MBOOT_CHECKSUM

[GLOBAL _start]
[EXTERN kmain] ; This is our C function!

_start:
    ; Set up the stack
    mov esp, stack_space
    
    ; Push magic numbers for Multiboot (Optional)
    push eax
    push ebx

    ; JUMP TO C CODE
    call kmain

    ; If kmain ever returns, halt the CPU
    jmp $

section .bss
resb 8192 ; 8KB of stack space
stack_space: