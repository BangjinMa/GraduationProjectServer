#include <iostream>
#include <string>
#include "TcpLibuv/TcpServer.h"
using namespace std;
//using namespace uv;

TcpServer tserver;

void acceptConnection(uv_stream_t* server, int status) {}
int main(int argc, char** argv)
{
	//TCPServer::StartLog("log/");
	//tserver.setnewconnectcb(NewConnect);
	tserver.startLog("tserverLog");
	if(!tserver.start("0.0.0.0", 12345, SEVERIPTYPE::IPV4, acceptConnection)) {
	//	fprintf(stdout, "Start Server error:%s\n", tserver.GetLastErrMsg());
	}

	return 0;
}