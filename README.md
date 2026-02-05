# WinMashup OS

A custom x86 operating system built to mash up the best (and most iconic) visual eras of Windows history.

## 🚀 The Mashup Timeline
* **Input:** Windows 95 (Classic Black & White Mouse Cursor)
* **Graphics Engine:** Windows 2000 (GDI32 Logic)
* **UI/Shell:** Windows XP (Luna Blue Taskbar & Start Button)
* **Visual Effects:** Windows Vista (Aero-style Gloss & Alpha Blending)

## 📁 Project Structure
* `/Kernel`: The core bootloader (ASM) and C kernel entry.
* `/Windows/System32`: The heart of the OS logic, including GDI, User32, and the Taskbar.
* `/Windows/System32/drivers`: Hardware drivers for VGA and Mouse input.

## 🛠️ How to Build
1. Ensure you have `nasm`, `gcc` (i386-elf), and `ld` installed.
2. Run `build.bat`.
3. Boot the resulting `kernel.bin` using QEMU:
   ```bash
   qemu-system-i386 -kernel kernel.bin
   
   