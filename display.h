#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "display.c"

void display_time(int hours, int minutes, int seconds);
void display_colons(void);
void display_hours(int hours);
void display_minutes(int minutes);
void display_seconds (int seconds);

int open_display(void);
void close_display();
void draw_grid(uint16_t pixels[8][8]);
void fill_pixels(uint16_t pixels[8][8], uint16_t color);


