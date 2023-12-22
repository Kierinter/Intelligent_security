//
// Created by kierin on 2023/12/21.
//


#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0); // create socket
    if (sockfd == -1) {
        perror("create socket failed");
        return -1;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8888); // port:8888
    addr.sin_addr.s_addr = inet_addr("192.168.137.1"); // ip:127.0.0.1
    //bind
    int ret = bind(sockfd, (struct sockaddr *) &addr, sizeof(addr)); // bind
    if (ret == -1) {
        perror("bind failed");
        return -1;
    } else {
        printf("bind success\n");
    }

    //listen
    ret = listen(sockfd, SOMAXCONN); // listen
    if (ret == -1) {
        perror("listen failed");
        return -1;
    } else {
        printf("listen success\n");
    }

    // accept
    struct sockaddr_in client_addr;
    socklen_t len = sizeof(client_addr);
    bzero(&client_addr, sizeof(client_addr));

    int client_fd = accept(sockfd, (struct sockaddr *) &client_addr, &len);
    if (client_fd == -1) {
        perror("accept failed");
        return -1;
    } else {
        printf("accept success\n");
    }

    //communicate
    printf("client ip: %s, port: %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    while (1) {

        char buf[1024] = {0};
        ssize_t read_bytes = read(client_fd, buf, sizeof(buf));
        if (read_bytes == -1) {
            perror("read failed");
            close(client_fd);
            return -1;
        } else if (read_bytes == 0) {
            printf("client close\n");
            close(client_fd);
            return 0;
            break;
        } else {
            printf("recv buf: %s\n", buf);
            write(client_fd, buf, sizeof(buf));
        }
    }
}






