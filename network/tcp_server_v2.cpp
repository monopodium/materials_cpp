#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

    //要求一：在tcp_server_xiao.cpp的程序里面打开一个.txt文件，把从client端收到的所有消息都存起来
    //要求二：server端要能实现判断是否为回文串的能力，
    //例如：client端发送一个1223221这样子的字符串，server端收到之后，就判断它是不是回文串，如果是的话，
    //就给client发“this is a xxxx", 不是的话就发“this is not a.."
    // client端要求不断的从user处读取需要判断的回文串。
#define PORT 8081
//client端的功能:从我们的命令行里面不断user读取消息，发送给server
//server：不断的去接收client的消息，存到文件里面。  
    int check_huiwen(std::string str)
    {
        int left = 0;
        int right = str.size() -1;
        while(left<right)
        {
            if(str[left] != str[right])
            {
                return -1;
            }
            left++;
            right--;
        }
        return 0;
    }
int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    const char *hello = "Hello from server";


    // 创建 socket 文件描述符
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // 绑定 socket 到端口
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);     //绑定port

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // 监听连接
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    // 接受客户端连接
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    int counter = 0;

    while(read(new_socket, buffer, 1024))
    {
            // // 读取客户端发送的数据
        std::cout << "Message from client: " << buffer << std::endl;
        std::string new_string(buffer);
        
        int result = check_huiwen(new_string);
        if(result == -1)
        {
            std::cout<<"该单词不是回文串！！！"<<std::endl;
        }
        else
        {
            std::cout<<"该单词是回文！！！！"<<std::endl;
        }
        new_string += "   (from xiao_server ) ";
            // // 发送数据到客户端
        send(new_socket, new_string.c_str(), new_string.size(), 0);
    }


    // while(true)
    // {
    // // 读取客户端发送的数据
    // int return_number = read(new_socket, buffer, 1024);
    // std::cout<<"return numbers"<<return_number<<std::endl;
    // std::cout << "Message from client: " << buffer << std::endl;

    // // 发送数据到客户端
    // send(new_socket, hello, strlen(hello), 0);
    // std::cout << "Hello message sent" << std::endl;

    // }
    // 关闭 socket
    close(new_socket);
    close(server_fd);

    return 0;
}