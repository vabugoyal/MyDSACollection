#include <arpa/inet.h>
#include <cstring>
#include <iostream>
#include <unistd.h>

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in server_addr{};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);

    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    connect(sock, (sockaddr*)&server_addr, sizeof(server_addr));

    const char* msg = "Hello from client";
    send(sock, msg, strlen(msg), 0);

    char buffer[1024] = {0};
    recv(sock, buffer, sizeof(buffer), 0);

    std::cout << "Server says: " << buffer << "\n";

    close(sock);
    return 0;
}

