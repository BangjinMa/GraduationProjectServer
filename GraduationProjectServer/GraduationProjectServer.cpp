// GraduationProjectServer.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Test/ProtocolTest.h"
#include <uv.h>
int main(){
	uv_loop_t * loop = uv_default_loop();
	uv_run(loop, UV_RUN_DEFAULT);
    return 0;
}

