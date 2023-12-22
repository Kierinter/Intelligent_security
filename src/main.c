//
// Created by kierin on 2023/12/21.
//
#include <stdio.h>
#include <stdlib.h>
#include <ptheard.h>

#include "../inc/touch.h"
#include "../inc/uart.h"
#include "../inc/lcd.h"

int main (int argc, char *argv[])
{

    lcd_init();
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

}