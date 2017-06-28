#pragma once



class CDuiShadowTest :	public WindowImplBase
{
public:
	CDuiShadowTest();
	~CDuiShadowTest();

public:
	virtual CDuiString GetSkinFile();
	virtual LPCTSTR GetWindowClassName() const;
	virtual void Notify(TNotifyUI& msg);
	virtual void InitWindow();
	virtual void OnFinalMessage( HWND hWnd );
private:
	CButtonUI *m_pBtnClose;
	CButtonUI *m_pBtnMin;
};

