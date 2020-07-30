#pragma once
#include <wtypes.h>
#include <iostream>
#define WM_SET_MODIFIED_WPF_VIEW    WM_USER + 10086

#ifdef _WPF_WND_WRAP_
#define _WPF_WND_WRAP_IMEXPORT_ _declspec(dllexport)
#else
#define _WPF_WND_WRAP_IMEXPORT_ _declspec(dllimport)
#endif

struct SWpfWndControlMediator;  // just forward declartion to make its included C++ projects to compile error free (implementation in .cpp file)

class _WPF_WND_WRAP_IMEXPORT_ MWpfWndControl
{
public:
	MWpfWndControl(HWND hwndParent);
	virtual ~MWpfWndControl();
	virtual void ShowAsChild(HWND parent, int x, int y); // Attach the WPF control as child to its parent MFC window
	virtual void SetData(std::string text );
	virtual void GetData(std::string& text);
	virtual void GetWndHeightWidth(int* height, int* width);
protected:
	HWND m_hwndParent;
	SWpfWndControlMediator* m_pWpfWndControlMediator;
};