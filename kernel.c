#include "kernel.h"
#include "kmain.h"

/* --- WINDOWS 2000 CORE (The Skeleton) --- */
#include "../Windows/System32/win_types.h"
#include "../Windows/System32/gdi32.c"

/* --- WINDOWS XP / VISTA HYBRID (The UI) --- */
#include "../Windows/System32/user32.c"
#include "../Windows/System32/taskbar.h"

/* --- HARDWARE DRIVERS --- */
#include "../Windows/System32/drivers/vga_shiny.h"
#include "../Windows/System32/drivers/shiny_driver.h"
#include "../Windows/System32/drivers/mouse.c"   // Windows 95 Mouse

/* GLOBAL HARDWARE VARIABLES */
uint32_t* LFB = (uint32_t*)VIDEO_RAM; // Linear Frame Buffer
int WIDTH     = 1024;
int HEIGHT    = 768;

/* THE HEART (Include the logic at the very end) */
#include "kmain.c"