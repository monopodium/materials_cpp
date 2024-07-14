g++ tcp_server.cpp -o tcp_server
g++ tcp_client.cpp -o tcp_client

服务端：

创建一个 socket：socket(AF_INET, SOCK_STREAM, 0)
绑定 socket 到一个特定的端口：bind()
监听连接：listen()
接受连接：accept()
读取数据：read()
发送数据：send()
关闭 socket：close()
客户端：

创建一个 socket：socket(AF_INET, SOCK_STREAM, 0)
将地址转换为二进制形式：inet_pton()
连接服务器：connect()
发送数据：send()
读取数据：read()
关闭 socket：close()


g++ udp_server.cpp -o udp_server
g++ udp_client.cpp -o udp_client


代码解释
服务器端：

创建一个 UDP socket：socket(AF_INET, SOCK_DGRAM, 0)
填充服务器信息（地址、端口等）：servaddr
绑定 socket 到端口：bind()
接收客户端消息：recvfrom()
发送响应消息到客户端：sendto()
关闭 socket：close()
客户端：

创建一个 UDP socket：socket(AF_INET, SOCK_DGRAM, 0)
填充服务器信息（地址、端口等）：servaddr
发送消息到服务器：sendto()
接收服务器响应：recvfrom()
关闭 socket：close()
TCP 和 UDP 的区别
TCP（传输控制协议）：

面向连接：在数据传输前需要建立连接（三次握手）。
可靠传输：确保数据包按顺序到达且不丢失。
流控制和拥塞控制：管理数据流的速率，防止网络拥塞。
UDP（用户数据报协议）：

无连接：数据传输前不需要建立连接。
不可靠传输：不保证数据包的顺序和完整性。
低开销：没有流控制和拥塞控制，适用于对速度和效率要求高而对可靠性要求不高的应用，如视频流、游戏等。
