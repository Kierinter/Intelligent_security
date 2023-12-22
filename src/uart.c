//
// Created by kierin on 2023/12/21.
//

#include "../inc/uart.h"
#include "../inc/lcd.h"

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/file.h>
#include <sys/stat.h>

void init_serial() {
    int se_fd = open(file, O_RDWR);
    if (se_fd == -1) {
        perror("open device error\n");
        return -1;
    }

    struct termios myserial;

    memset(&myserial, 0, sizeof(myserial));

    myserial.c_cflag |= (CLOCAL | CREAD);
    // 设置控制模式状态，本地连接，接受使能
    // 设置 数据位
    myserial.c_cflag &= ~CSIZE; // 清空数据位
    // myserial.c_cflag &= ~CRTSCTS; // 无硬件流控制
    myserial.c_cflag |= CS8; // 数据位:8

    myserial.c_cflag &= ~CSTOPB; //   //1位停止位
    myserial.c_cflag &= ~PARENB; // 不要校验
    // myserial.c_iflag |= IGNPAR;   //不要校验
    // myserial.c_oflag = 0;  //输入模式
    // myserial.c_lflag = 0;  //不激活终端模式

    switch (baudrate) {
        case 9600:
            cfsetospeed(&myserial, B9600);
            cfsetispeed(&myserial, B9600);
            break;
        case 115200:
            cfsetospeed(&myserial, B115200);
            cfsetispeed(&myserial, B115200);
            break;
        case 19200:
            cfsetospeed(&myserial, B19200);
            cfsetispeed(&myserial, B19200);
            break;
    }

    tcflush(fd, TCIFLUSH); // 清空输入缓冲区
    // tcflush(fd,TCOFLUSH); //清空输出缓冲区j
    if ((tcsetattr(fd, TCSANOW, &myserial)) != 0) {
        perror("tcsetattr error\n");
        return -1;
    }
    return 0;
}

void get_MQ2(

* data)
{
printf("get_MQ2\n");
int fd = init_serial(com2, 9600);
if (fd == -1)
{
perror("open device error\n");
return;
}
unsigned char cmd[9] = {0xff, 0x01, 0x86, 0x00, 0x00, 0x00, 0x00, 0x00, 0x79};
unsigned char buf[9] = {0};
int smoke = 0;
while (1)
{
write(fd, cmd,
9);
read(fd, buf,
9);
smoke = buf[2] << 8 | buf[3];
printf("smoke = %d\n", smoke);
show_number(100, 100, 32, 16, smoke, 0xffffff);
}
close(fd);
return;
}