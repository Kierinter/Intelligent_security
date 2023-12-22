//
// Created by kierin on 2023/12/21.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>


int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0); // create socket
    if (sockfd == -1) {
        perror("create socket failed");
        return -1;
    }

    //connect
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8888); // port:8888
    addr.sin_addr.s_addr = inet_addr("192.168.137.1"); // ip:127.0.0.1
    if (connect(sockfd, (struct sockaddr *) &addr, sizeof(addr)) == -1) {
        perror("connect failed");
        return -1;
    } else {
        printf("connect success\n");
        printf("server ip: %s, port: %d\n", inet_ntoa(addr.sin_addr), ntohs(addr.sin_port));
    }



    //communicate
    while (1) {
        char buf[128] = {0};
        printf("please input: ");
        fgets(buf, sizeof(buf), stdin);
        ssize_t write_byte = write(sockfd, buf, sizeof(buf));
        if (write_byte == -1) {
            perror("connected but sent failed");
            return -1;
            break;
        }
        bzero(&buf, sizeof(buf));
        ssize_t read_byte = read(sockfd, buf, sizeof(buf));
        if (read_byte > 0) {
            printf("server: %s\n", buf);
        } else if (read_byte == 0) {
            printf("server closed\n");
            break;
        } else {
            perror("read failed");

            close(sockfd);
            return -1;
            break;
        }
    }
    //close
    close(sockfd);
    return 0;
}
