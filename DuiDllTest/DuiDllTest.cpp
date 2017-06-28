// DuiDllTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


extern "C" _declspec(dllexport)void CreateDui();
#pragma comment(lib,"DLLTest.lib")


int _tmain(int argc, _TCHAR* argv[])
{
	CreateDui();
	return 0;
}

