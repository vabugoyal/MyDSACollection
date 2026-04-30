#include <arpa/inet.h>
#include <cstring>
#include <iostream>
#include <unistd.h>

int main() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in address{};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;  // 0.0.0.0
    address.sin_port = htons(8080);

    bind(server_fd, (sockaddr*)&address, sizeof(address));
    listen(server_fd, 5);

    std::cout << "Server listening on port 8080...\n";

    sockaddr_in client_addr{};
    socklen_t client_len = sizeof(client_addr);

    int client_fd = accept(server_fd, (sockaddr*)&client_addr, &client_len);

    std::cout << "Client connected\n";

    char buffer[1024] = {0};
    recv(client_fd, buffer, sizeof(buffer), 0);

    std::cout << "Received: " << buffer << "\n";

    const char* response = "Hello from server";
    send(client_fd, response, strlen(response), 0);

    close(client_fd);
    close(server_fd);

    return 0;
}
