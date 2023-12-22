//
// Created by kierin on 2023/12/21.
//

#include "../inc/touch.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <linux/input.h>
#include <unistd.h>
#include <fcntl.h>

//TODO: implement get_coordinate and direction
void get_coordinate(int *x, int *y) {
    // int *x = 0;
    // int *y = 0;

    int ts_fd = open("/dev/input/event0", O_RDONLY);
    if (ts_fd == -1) {
        perror("open ts error");
        return -1;
    }

    struct input_event ts_event;
    while (1) {
        read(ts_fd, &ts_event, sizeof(ts_event));
        if (ts_event.type == EV_ABS) {
            if (ts_event.code == ABS_X) {
                *x = ts_event.value;
            } else if (ts_event.code == ABS_Y) {
                *y = ts_event.value;

            }
        } else if (ts_event.type == EV_KEY) {
            if (ts_event.code == BTN_TOUCH && ts_event.value == 0) {
                break;
            }
        }
        close(ts_fd);
        printf("x = %d, y = %d\n", x, y);
    }
}

