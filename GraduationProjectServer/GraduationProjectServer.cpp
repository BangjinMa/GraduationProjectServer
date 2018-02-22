// GraduationProjectServer.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <WinSock2.h>  
#include <iostream>
#include <stdio.h>  
#pragma comment (lib,"ws2_32.lib")
//服务器入口
//WinSock 版本号
#define VERSIONBLOW 1
#define VERSIONBHIGH 1

#define SERVERERROR -1
#define SERVERSUCCESS 0

///
//加载Windows SOCKET动态库
///
int  LoadingWinSockDll(int bLow, int bHigh) {
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;

	wVersionRequested = MAKEWORD(bLow, bHigh);

	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0) {
		return SERVERERROR;
	}
	if (LOBYTE(wsaData.wVersion) != 1 ||
		HIBYTE(wsaData.wVersion) != 1) {
		WSACleanup();
		return SERVERERROR;
	}
}


int main()
{

	std::cout << "name" << std::endl;

	if (LoadingWinSockDll(VERSIONBLOW, VERSIONBHIGH) == -1)
		return SERVERERROR;

	SOCKET sockSrv = socket(AF_INET, SOCK_STREAM, 0);

	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000);

	int i = bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));
	if (i)
		return SERVERERROR;
	listen(sockSrv, 5);

	SOCKADDR_IN addrClient;
	int len = sizeof(SOCKADDR);
	while (1)
	{
		SOCKET sockConn = accept(sockSrv, (SOCKADDR*)&addrClient, &len);
		char sendBuf[50];
		send(sockConn, sendBuf, strlen(sendBuf) + 1, 0);
		char recvBuf[50];
		recv(sockConn, recvBuf, 50, 0);
		printf("%s\n", recvBuf);
		closesocket(sockConn);
	}
	return SERVERSUCCESS;
}


