#include <iostream>
#include <string>
#include "TcpLibuv/TcpServer.h"
#include "TcpLibuv/ClientManager.h"
#include "log4z.h"
using namespace std;
//using namespace uv;

TcpServer tserver;



int main(int argc, char** argv)
{
	//TCPServer::StartLog("log/");
	//tserver.setnewconnectcb(NewConnect);
	UVSERVER::ClientManager*clientM = UVSERVER::ClientManager::getInstance();
	clientM->addClient(0, nullptr);
	clientM->addClient(0, nullptr);
	tserver.startLog("tserverLog");
	if(!tserver.start("0.0.0.0", 12345, SEVERIPTYPE::IPV4)) {
		LOGI("Start Server error:%s\n");
	}
	return 0;
}