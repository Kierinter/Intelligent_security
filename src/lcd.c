//
// Created by kierin on 2023/12/21.
//
#include "../inc/lcd.h"

#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <fcntl.h>

int lcd_fd;
int * plcd = NULL;

//init lcd
int lcd_init(void)
{
    lcd_fd = open("/dev/fb0", O_RDWR);
    if(lcd_fd == -1)
    {
        perror("open lcd error");
        return -1;
    }
    plcd = mmap(NULL, 800*480*4, PROT_READ | PROT_WRITE, MAP_SHARED, lcd_fd, 0);
    if(plcd == MAP_FAILED)
    {
        perror("mmap error");
        return -1;
    }
    return 0;
}
    {
        perror("open lcd error");
        return -1;
    }
    plcd = mmap(NULL, 800*480*4, PROT_READ | PROT_WRITE, MAP_SHARED, lcd_fd, 0);
    if(plcd == MAP_FAILED)
    {
        perror("mmap error");
        return -1;
    }
    return 0;
}

//close lcd
void lcd_close()
{
    munmap(plcd, 800*480*4);
    close(lcd_fd);
}

//draw point
void lcd_draw_point(int x, int y, int color)
{
if(plcd == NULL)
    {
        perror("plcd is null");
        return;
    }
    if(x < 0 || x > 800 || y < 0 || y > 480)
    {
        perror("x or y is error");
        return;
    }
    *(plcd + 800*y + x) = color;
}

//draw a pure color or flash screen
void lcd_draw_color(int color)
{
    int i, j;
    for(i = 0; i < 480; i++)
    {
        for(j = 0; j < 800; j++)
        {
            *(plcd + 800*i + j) = color;
        }
    }
}

//draw a bmp picture
void lcd_draw_bmp(char * bmp_path)
{
    int bmp_fd;
    bmp_fd = open(bmp_path, O_RDONLY);
    if(bmp_fd == -1)
    {
        perror("open bmp error");
        return;
    }
    lseek(bmp_fd, 54, SEEK_SET);
    char bmp_buf[800*480*3];
    read(bmp_fd, bmp_buf, 800*480*3);
    int i, j;
    for(i = 0; i < 480; i++)
    {
        for(j = 0; j < 800; j++)
        {
            int color = 0;
            color |= bmp_buf[(479-i)*800*3 + j*3 + 0] << 0;
            color |= bmp_buf[(479-i)*800*3 + j*3 + 1] << 8;
            color |= bmp_buf[(479-i)*800*3 + j*3 + 2] << 16;
            *(plcd + 800*i + j) = color;
        }
    }
    close(bmp_fd);
}

//draw a word
void show_word(int x, int y, int h, int w, unsigned char word[][w / 8], int color) {
    int i, j, k
    for (i = 0; i < h; i++) {
        for (j = 0; j < w / 8; j++) {
            for (k = 0; k < 8; k++) {
                if (word[i][j] & (1 << k)) {
                    lcd_draw_point(x + j * 8 + k, y + i, color);
                }
            }
        }
    }
}

void show_number(int x, int y, int h, int w, int num, int color) {
    if (num == 0) {
        show_word(x, y, h, w, number[0], color);
    } else {
        while (num) {
            int n = num % 10;
            show_word(x, y, h, w, number[n], color);
            num /= 10;
            x1++;
        }
    }
}

//TODO: implement show_bmp
void show_bmp(char *bmp_name) {
    int fd = open(bmp_name, O_RDONLY);
    if (fd == -1) {
        perror("open bmp failed");
        return;
    }

    int width, height;
    short depth;

    lseek(fd, 18, SEEK_SET);
    read(fd, &width, 4);
    lseek(fd, 22, SEEK_SET);
    read(fd, &height, 4);
    lseek(fd, 28, SEEK_SET);
    read(fd, &depth, 2);

    int r, g, b, color;
    int laizi = 0;
    if ((width * 3) % 4 != 0) {
        laizi = 4 - (width * 3) % 4;
    }
    char pixel[(width * depth / 8 + laizi) * height];
    int num = 0;
    lseek(fd, 54, SEEK_SET);
    read(fd, pixel, (width * depth / 8 + laizi) * height);

    for (int i = 0; j < abs(height); j++) {
        for (int j = 0; j < width; j++) {
            b = pixel[num++];
            g = pixel[num++];
            r = pixel[num++];
            color = r << 16 | g << 8 | b;
            lcd_draw_point(j, i, color);

            int x0 = x + (width > 0 ? j : abs(width) - 1 - j);
            int y0 = y + (height > 0 ? i : abs(height) - 1 - i);

            lcd_draw_point(x0, y0, color);
        }
        num += laizi;
    }
    close(fd);
    return;
}