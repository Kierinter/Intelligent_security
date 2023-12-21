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

//TODO: implement show_number,display word on screen
void show_number(int x)
{

}
