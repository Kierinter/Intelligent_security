//
// Created by kierin on 2023/12/21.
//
#include <stdio.h>
#include <stdlib.h>
#include <ptheard.h>

#include "../inc/touch.h"
#include "../inc/uart.h"
#include "../inc/lcd.h"

struct share_mem {
    int x;
    int y;
};

void *touch_theard(void *arg) {
    struct share_mem *share = (struct share_mem *) malloc(sizeof(struct share_mem));
    while (1) {
        get_coordinate(&share->x, &share->y);
        printf("x = %d, y = %d\n", share->x, share->y);
    }
}

int main() {
    sturct
    share_mem *share = (struct share_mem *) malloc(sizeof(struct share_mem));


    lcd_init();
    lcd_show_bmp("1.bmp");//picture should be added by yourself
    int smoke = 0;
    get_MQ2(&smoke);
    printf("smoke = %d\n", smoke);
    if (smoke > 100) {
        led_beep_ctrl("/dev/led", 1);
        led_beep_ctrl("/dev/beep", 1);
    } else {
        led_beep_ctrl("/dev/led", 0);
        led_beep_ctrl("/dev/beep", 0);
    }

    p_thread_t tid;
    pthread_create(&tid, NULL, touch_theard, *share);
    pthread_join(tid, NULL);

    int x = share->x;
    int y = share->y;
    if (x > 0 && x < 200 && y > 0 && y < 200) {
        lcd_show_bmp("1.bmp");

        lcd_close();

    }