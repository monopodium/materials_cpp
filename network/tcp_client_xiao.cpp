#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8081

int main() {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};
    const char *hello = "Hello from client,xiao!";

    // 创建 socket 文件描述符
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cout << "\n Socket creation error \n";
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // 将地址转换为二进制形式
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        std::cout << "\nInvalid address/ Address not supported \n";
        return -1;
    }

    // 连接服务器
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cout << "\nConnection Failed \n";
        return -1;
    }

    std::cout << "请输入想发给server的消息:,以#结束程序" << std::endl;
    while (true)
    {
        std::string input_from_user;
        std::cin >> input_from_user;
        if(input_from_user=="#"){
            break;
        }
        send(sock, input_from_user.c_str(), input_from_user.size(), 0);
        valread = read(sock, buffer, 1024);
        std::cout << "Message from server: " << buffer << std::endl;
    }

    close(sock);
    close(sock);
        // while (true)
        // {
        //     // 发送数据到服务器
        //     send(sock, hello, strlen(hello), 0);
        //     std::cout << "Hello xiao !" << std::endl;

        //     // 读取服务器响应的数据
        //     valread = read(sock, buffer, 1024);
        //     std::cout << "Message from server: " << buffer << std::endl;

        //     // 关闭 socket
        //     close(sock);
        // }

    return 0;
}