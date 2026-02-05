#ifndef KERNEL_H
#define KERNEL_H

typedef unsigned int   uint32_t;
typedef unsigned short uint16_t;
typedef unsigned char  uint8_t;

/* Hardware Constants */
#define XP_DESKTOP_BLUE 0x245EDB
#define VIDEO_RAM       0xFD000000

/* Global Video Variables */
extern uint32_t* LFB;
extern int WIDTH;
extern int HEIGHT;

/* System Initialization */
void kmain();

#endif