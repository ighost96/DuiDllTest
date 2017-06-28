// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "stdafx.h"
#include "DuiShadowTest.h"


extern "C" _declspec(dllexport)void CreateDui();
void InitResourse();


BOOL APIENTRY DllMain( HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
	)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}


extern "C" _declspec(dllexport)void CreateDui()
{
	HRESULT hrslt=::CoInitialize(NULL);
	if(FAILED(hrslt))			return;

	//HINSTANCE hInstance;
	//CPaintManagerUI::SetInstance(hInstance);
	InitResourse();

	CDuiShadowTest *pShadow=new CDuiShadowTest();
	if (pShadow==NULL)
	{
		return;
	}
	HWND hwd=pShadow->Create(NULL,_T("DUI"),UI_WNDSTYLE_FRAME,0L,0,0,900,600);
	//HWND hwd=pShadow->Create(NULL,_T("DUI"),WS_POPUP |WS_VISIBLE ,WS_EX_TOOLWINDOW,0,0,700,450);
	if(hwd==NULL)    return;
	pShadow->CenterWindow();
	//::ShowWindow(hwd,SW_SHOW);
	pShadow->ShowModal();
	//CPaintManagerUI::MessageLoop();

	delete pShadow;
	pShadow=NULL;

	::CoUninitialize();

	return;
}


void InitResourse()
{
	// 资源类型
	CPaintManagerUI::SetResourceType(UILIB_FILE);
	// 资源路径
	CDuiString strResourcePath = CPaintManagerUI::GetInstancePath();
	// 加载资源
	switch(CPaintManagerUI::GetResourceType())
	{
	case UILIB_FILE:
		{
			strResourcePath += _T("Skin\\");
			CPaintManagerUI::SetResourcePath(strResourcePath.GetData());
			// 加载资源管理器
			CResourceManager::GetInstance()->LoadResource(_T("res.xml"), NULL);
			break;
		}
	case UILIB_RESOURCE:
		{
			strResourcePath += _T("Skin\\");
			CPaintManagerUI::SetResourcePath(strResourcePath.GetData());
			// 加载资源管理器
			CResourceManager::GetInstance()->LoadResource(_T("IDR_RES"), _T("xml"));
			break;
		}
	case UILIB_ZIP:
		{
			strResourcePath += _T("Skin\\");
			CPaintManagerUI::SetResourcePath(strResourcePath.GetData());
			CPaintManagerUI::SetResourceZip(_T("ADMonSetup.zip"), true);
			// 加载资源管理器
			CResourceManager::GetInstance()->LoadResource(_T("res.xml"), NULL);
			break;
		}
	case UILIB_ZIPRESOURCE:
		{
			strResourcePath += _T("Skin\\");
			CPaintManagerUI::SetResourcePath(strResourcePath.GetData());

			HRSRC hResource = ::FindResource(CPaintManagerUI::GetResourceDll(), _T("IDR_ZIPRES"), _T("ZIPRES"));
			if( hResource != NULL ) {
				DWORD dwSize = 0;
				HGLOBAL hGlobal = ::LoadResource(CPaintManagerUI::GetResourceDll(), hResource);
				if( hGlobal != NULL ) {
					dwSize = ::SizeofResource(CPaintManagerUI::GetResourceDll(), hResource);
					if( dwSize > 0 ) {
						CPaintManagerUI::SetResourceZip((LPBYTE)::LockResource(hGlobal), dwSize);
						// 加载资源管理器
						CResourceManager::GetInstance()->LoadResource(_T("res.xml"), NULL);
					}
				}
				::FreeResource(hResource);
			}
		}
		break;
	}
}