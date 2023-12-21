//
// Created by kierin on 2023/12/21.
//

#ifndef INTELLIGENT_SECURITY_LCD_H
#define INTELLIGENT_SECURITY_LCD_H

static unsigned char number[10][16][32 / 8] =
        {
                {
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x0C, 0x00, 0x3A, 0x00, 0x33, 0x00, 0x21, 0x00, 0x21, 0x00, 0x61, 0x00, 0x41, 0x00, 0x41, 0x00,
                        0x41, 0x00, 0x41, 0x00, 0x41, 0x00, 0x41, 0x00, 0x61, 0x00, 0x21, 0x00, 0x23, 0x00, 0x32, 0x00,
                        0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 /* "0",0*/
                },
                {
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x0C, 0x00, 0x0C, 0x00, 0x3C, 0x00, 0x0C, 0x00, 0x0C, 0x00, 0x0C, 0x00, 0x0C, 0x00, 0x0C, 0x00,
                        0x0C, 0x00, 0x0C, 0x00, 0x0C, 0x00, 0x0C, 0x00, 0x0C, 0x00, 0x0C, 0x00, 0x0C, 0x00, 0x0C, 0x00,
                        0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 /*"1",1*/
                },
                {
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x1E, 0x00, 0x3B, 0x00, 0x21, 0x00, 0x21, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x02, 0x00,
                        0x06, 0x00, 0x0C, 0x00, 0x08, 0x00, 0x18, 0x00, 0x10, 0x00, 0x20, 0x00, 0x60, 0x00, 0x7F, 0x00,
                        0x7F, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 /*"2",2*/
                },
                {
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x1E, 0x00, 0x33, 0x00, 0x21, 0x00, 0x41, 0x00, 0x01, 0x00, 0x03, 0x00, 0x06, 0x00, 0x1C, 0x00,
                        0x1F, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x80, 0x01, 0x80, 0x01, 0x00, 0x41, 0x00, 0x63, 0x00,
                        0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 /*"3",3*/
                },
                {
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x04, 0x00, 0x06, 0x00, 0x04, 0x00, 0x04, 0x00, 0x0A, 0x00, 0x0A, 0x00, 0x1A, 0x00, 0x12, 0x00,
                        0x12, 0x00, 0x22, 0x00, 0x22, 0x00, 0x42, 0x00, 0x7F, 0x80, 0x42, 0x00, 0x02, 0x00, 0x02, 0x00,
                        0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 /*"4",4*/
                },
                {
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x27, 0x00, 0x3F, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x2C, 0x00, 0x3E, 0x00,
                        0x63, 0x00, 0x41, 0x00, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x41, 0x00, 0x41, 0x00, 0x63, 0x00,
                        0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 /*"5",5*/
                },
                {
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x04, 0x00, 0x0C, 0x00, 0x08, 0x00, 0x18, 0x00, 0x10, 0x00, 0x10, 0x00, 0x20, 0x00, 0x3E, 0x00,
                        0x33, 0x00, 0x61, 0x00, 0x41, 0x80, 0x40, 0x80, 0x41, 0x80, 0x41, 0x00, 0x61, 0x00, 0x23, 0x00,
                        0x1E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 /*"6",6*/
                },
                {
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x07, 0x00, 0x7F, 0x00, 0x01, 0x00, 0x01, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x04, 0x00,
                        0x04, 0x00, 0x04, 0x00, 0x0C, 0x00, 0x08, 0x00, 0x08, 0x00, 0x08, 0x00, 0x18, 0x00, 0x10, 0x00,
                        0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 /*"7",7*/
                },
                {
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x1E, 0x00, 0x32, 0x00, 0x21, 0x00, 0x61, 0x80, 0x61, 0x00, 0x22, 0x00, 0x34, 0x00, 0x1C, 0x00,
                        0x16, 0x00, 0x33, 0x00, 0x61, 0x00, 0x41, 0x00, 0x41, 0x00, 0x41, 0x00, 0x41, 0x00, 0x23, 0x00,
                        0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 /*"8",8*/
                },
                {
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x1E, 0x00, 0x3A, 0x80, 0x21, 0x80, 0x61, 0x00, 0x41, 0x00, 0x41, 0x00, 0x41, 0x00, 0x43, 0x00,
                        0x47, 0x00, 0x3D, 0x00, 0x1A, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00,
                        0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 /*"9",9*/
                }};

void lcd_init(void);
void lcd_close(void);
void lcd_draw_point(int x, int y, int color);
void lcd_draw_color(int color);

//void show_word(int x, int y, int h, int w, unsigned char word[][w / 8], int color);
void show_number(int x, int y, int h, int w, int num, int color);

#endif //INTELLIGENT_SECURITY_LCD_H
