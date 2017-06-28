#include "StdAfx.h"
#include "DuiShadowTest.h"


CDuiShadowTest::CDuiShadowTest()
{
}


CDuiShadowTest::~CDuiShadowTest()
{
}


CDuiString CDuiShadowTest::GetSkinFile()
{
	return _T("MainWindow.xml");
}

LPCTSTR CDuiShadowTest::GetWindowClassName() const
{
	return _T("±ﬂøÚ“ı”∞≤‚ ‘");
}

void CDuiShadowTest::Notify(TNotifyUI& msg)
{
	if (msg.sType.CompareNoCase(DUI_MSGTYPE_CLICK)==0)
	{
		if (msg.pSender==m_pBtnClose)
		{
			PostQuitMessage(0);
			//Close(0);
			return;
		}
		else if (msg.pSender==m_pBtnMin)
		{
			SendMessage(WM_SYSCOMMAND,SC_MINIMIZE,0);
			return;
		}
	}
}

void CDuiShadowTest::InitWindow()
{
	m_pBtnClose=static_cast<CButtonUI*>(m_pm.FindControl(_T("closebtn")));
	m_pBtnMin=static_cast<CButtonUI*>(m_pm.FindControl(_T("minbtn")));
}

void CDuiShadowTest::OnFinalMessage( HWND hWnd )
{
	__super::OnFinalMessage(hWnd);
	PostQuitMessage(0);
	delete this;
}