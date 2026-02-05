void kmain() {
    // 1. Initialize Vista-style Graphics Hardware
    install_shiny_driver(&vga_driver_info);

    // 2. Draw the XP Desktop Background
    // Using the Win2000 GDI engine for the solid color
    Win2000_FillRect(0, 0, WIDTH, HEIGHT, 0x245EDB);

    // 3. Render the Taskbar (XP Style)
    render_xp_taskbar();

    // 4. Create and Draw a Glossy "Mashup" Window
    // This uses XP Logic + Vista Gloss (Aero)
    HWND myComputer = CreateWindowXP("My Computer", 150, 150, 450, 350);
    DrawXPVistaWindow(myComputer);

    // 5. System Execution Loop
    while(1) {
        // In a real OS, we would save the background before drawing the mouse
        // so the cursor doesn't 'trail' or smear.
        
        // Draw the Windows 95 Classic Black & White Cursor
        // This is drawn LAST so it stays on top of the Vista Gloss
        draw_mouse_cursor(current_mouse.x, current_mouse.y);

        // Tell the CPU to wait for the next interrupt
        __asm__ volatile("hlt");
    }
}