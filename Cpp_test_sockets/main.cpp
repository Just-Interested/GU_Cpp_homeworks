#include <iostream>
#include "socket_headers.h"
#include <vector>

int main(int argc, char** argv) {
    std::cout << "Hello, world!\n";

    int sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    struct addrinfo hints {0};
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    struct addrinfo* res;
    int status;

    status = getaddrinfo("ya.ru", NULL, &hints, &res);
    if (status != 0){
        std::cout << "Error" << std::endl;
        return 1;
    }

    std::vector<sockaddr_in*> server_addr_list4;
    std::vector<sockaddr_in6*> server_addr_list6;

    char ip6[INET6_ADDRSTRLEN];
    for (addrinfo* ptr = res; ptr != NULL; ptr = ptr->ai_next){
        std::cout << "Flags: " << std::hex << ptr->ai_flags << std::endl;
        std::cout << "Family: ";
        switch (ptr->ai_family)
        {
        case AF_INET:
            std::cout << "AF_INET (IPv4)\n";
            std::cout << "IP address: " << inet_ntoa((reinterpret_cast<sockaddr_in*>(ptr->ai_addr))->sin_addr) << std::endl;
            server_addr_list4.push_back(reinterpret_cast<sockaddr_in*>(ptr->ai_addr));
            break;
        case AF_INET6:
            {
                std::cout << "AF_INET (IPv6)\n";
                server_addr_list6.push_back(reinterpret_cast<sockaddr_in6*>(ptr->ai_addr));
                std::cout << "IP address: " << inet_ntop(AF_INET6, &server_addr_list6.back()->sin6_addr, ip6, INET6_ADDRSTRLEN) << std::endl;
                break;
            }
        default:
            std::cout << "unk\n" << ptr->ai_family << std::endl;
            break;
        }
    }

    char buffer[1024] = {0};
    sockaddr_storage server_addr = {0};
    reinterpret_cast<sockaddr_in*>(&server_addr)->sin_family = AF_INET;
    reinterpret_cast<sockaddr_in*>(&server_addr)->sin_port = htons(443);
	if (!server_addr_list4.empty())
		reinterpret_cast<sockaddr_in*>(&server_addr)->sin_addr = server_addr_list4.back()->sin_addr;
	else if(!server_addr_list6.empty())
		reinterpret_cast<sockaddr_in6*>(&server_addr)->sin6_addr = server_addr_list6.back()->sin6_addr;
	else 
        std::cout << "Error 1.5" << std::endl;
    if (0 == connect(sock_fd, reinterpret_cast<const sockaddr*>(&server_addr), sizeof(server_addr))){
        std::string request = { "GET / HTTP/1.1\nHost: ya.ru\n\n" };
        send(sock_fd, request.c_str(), request.length(), 0);
        auto recv_bytes = recv(sock_fd, buffer, sizeof(buffer), 0);
        buffer[recv_bytes] = '\0';
        std::cout << buffer << std::endl;
    }
    else {
        std::cout << "Error 2" << std::endl;
    }
    
}
