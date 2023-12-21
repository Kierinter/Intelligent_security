//
// Created by kierin on 2023/12/21.
//

#ifndef INTELLIGENT_SECURITY_LCD_H
#define INTELLIGENT_SECURITY_LCD_H

void lcd_init(void);
void lcd_close(void);
void lcd_draw_point(int x, int y, int color);
void lcd_draw_color(int color);
#endif //INTELLIGENT_SECURITY_LCD_H
