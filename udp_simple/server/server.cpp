#include <iostream>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#include <cstring>

#include <common/assertion.h>
#include <common/socket_guard.h>

using namespace std;

namespace
{
	static const size_t buff_size = 1024;
	static char buff[buff_size];
	static string ok = "ok";
}

int main(int argc, char* argv[])
{
	utils::assert(argc >= 2, "started", "failed to start");

	socket_guard guard(socket(AF_INET, SOCK_DGRAM, 0));

	auto udp_socket = guard.descr;

	sockaddr_in udp_server;
	udp_server.sin_family = AF_INET;
	udp_server.sin_addr.s_addr = htonl(INADDR_ANY);
	udp_server.sin_port = htons(atoi(argv[1]));

	auto bind_result = bind(udp_socket, (sockaddr*)(&udp_server), sizeof(udp_server));
	utils::assert(bind_result != -1, "binded", "failed to bind");

	sockaddr_in udp_client;
	socklen_t addrlen;
	while (true)
	{
		auto recv_result = recvfrom(udp_socket, buff, buff_size, 0, (sockaddr*)(&udp_client), &addrlen);
		try
		{
			utils::assert(recv_result != -1, "received", "failed to receive");
			utils::incoming_message(string(buff, buff + strlen(buff)));
		}
		catch(const runtime_error& err)
		{
			// ignore error
		}

		string message(buff, buff + strlen(buff));
		utils::assert(!message.empty(), "", "empty message");

		auto send_result = sendto(udp_socket, ok.data(), ok.length(), 0, (sockaddr*)(&udp_client), sizeof(udp_client));
		try
		{
			utils::assert(send_result != -1, "sent", "failed to send");
			utils::outgoing_message(ok);
		}
		catch(const runtime_error& err)
		{
			// ignore error
		}
	}

	return 0;
}
