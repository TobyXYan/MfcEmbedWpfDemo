#pragma once


// WpfContainer dialog
#include "WpfWndWrap.h"
class WpfContainer : public CDialogEx
{
	DECLARE_DYNAMIC(WpfContainer)

public:
	WpfContainer(CWnd* pParent = nullptr);   // standard constructor
	virtual ~WpfContainer();
	virtual BOOL OnInitDialog();
	LRESULT OnSetModified(WPARAM wParam, LPARAM lParam);
	virtual void GetWndHeightWidth(int* height, int* width);
	virtual BOOL Create(CWnd* pParentWnd);
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONTAINER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	MWpfWndControl* m_pMWpfWndControl;
	DECLARE_MESSAGE_MAP()
};
