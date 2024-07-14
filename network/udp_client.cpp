#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main() {
    int sockfd;
    char buffer[1024];
    struct sockaddr_in servaddr;

    // 创建 socket 文件描述符
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    // 填充服务器信息
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    const char *hello = "Hello from client";
    
    // 发送消息到服务器
    sendto(sockfd, hello, strlen(hello), 0, (const struct sockaddr *)&servaddr, sizeof(servaddr));
    std::cout << "Hello message sent." << std::endl;

    int n;
    socklen_t len = sizeof(servaddr);

    // 接收服务器响应
    n = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&servaddr, &len);
    buffer[n] = '\0';
    std::cout << "Server: " << buffer << std::endl;

    // 关闭 socket
    close(sockfd);

    return 0;
}
