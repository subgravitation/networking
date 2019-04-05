#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <cstring>
#include <cstdlib>

#include "common/assertion.h"
#include "common/socket_guard.h"

using namespace std;

namespace
{
    static const size_t buff_size = 1024;
    static char buff[buff_size];
}

int main(int argc, char* argv[])
{
    utils::assert(argc >= 4, "started", "not enough args");

    socket_guard guard(socket(AF_INET, SOCK_DGRAM, 0));

    auto udp_socket = guard.descr;

    sockaddr_in udp_client;
    udp_client.sin_family = AF_INET;
    udp_client.sin_addr.s_addr = INADDR_ANY;
    udp_client.sin_port = 0;

    auto bind_result = bind(udp_socket, (sockaddr*)(&udp_client), sizeof(udp_client));
    utils::assert(bind_result != -1, "binded", "failed to bind");
    
    sockaddr_in udp_server;
    udp_server.sin_family = AF_INET;
    udp_server.sin_addr.s_addr = inet_addr(argv[1]);
    udp_server.sin_port = htons(atoi(argv[2]));

    auto send_result = sendto(udp_socket, argv[3], strlen(argv[3]), 0, (sockaddr*)(&udp_server), sizeof(udp_server));
    utils::assert(bind_result != -1, "sent", "failed to send");
    utils::outgoing_message(string(argv[3], argv[3] + strlen(argv[3])));

    socklen_t addr_length;
    auto recv_result = recvfrom(udp_socket, buff, buff_size, 0, (sockaddr*)(&udp_server), &addr_length);
    utils::assert(recv_result != -1, "received", "failed to receive");

    string message(buff);
    utils::assert(!message.empty(), "", "empty message");

    utils::incoming_message(message);

    return 0;
}