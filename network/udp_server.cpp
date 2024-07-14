#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080

int main() {
    int sockfd;
    char buffer[1024];
    struct sockaddr_in servaddr, cliaddr;

    // 创建 socket 文件描述符
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    // 填充服务器信息
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    // 绑定 socket 到端口
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    int n;
    socklen_t len = sizeof(cliaddr);

    // 接收客户端消息
    n = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&cliaddr, &len);
    buffer[n] = '\0';
    std::cout << "Client: " << buffer << std::endl;

    const char *hello = "Hello from server";
    
    // 发送响应到客户端
    sendto(sockfd, hello, strlen(hello), 0, (const struct sockaddr *)&cliaddr, len);
    std::cout << "Hello message sent." << std::endl;

    // 关闭 socket
    close(sockfd);

    return 0;
}
