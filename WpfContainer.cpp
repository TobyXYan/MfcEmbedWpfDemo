// WpfContainer.cpp : implementation file
//

#include "pch.h"
#include "MfcEmbedWpf.h"
#include "WpfContainer.h"
#include "afxdialogex.h"
#include "WpfWndWrap.h"


// WpfContainer dialog

IMPLEMENT_DYNAMIC(WpfContainer, CDialogEx)

WpfContainer::WpfContainer(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CONTAINER, pParent)
{
	m_pMWpfWndControl = NULL;
}

WpfContainer::~WpfContainer()
{
}

void WpfContainer::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}



BOOL WpfContainer::OnInitDialog()
{
	CoInitialize(NULL);
	CDialog::OnInitDialog();
	if (NULL == m_pMWpfWndControl)
		m_pMWpfWndControl = new MWpfWndControl(this->GetSafeHwnd());
	std::string text = "Data Already Set";
	m_pMWpfWndControl->SetData(text);
	m_pMWpfWndControl->ShowAsChild(this->GetSafeHwnd(), 0, 0);
	// TODO: Add your control notification handler code here
	//CoUninitialize();
	return TRUE;

}

LRESULT WpfContainer::OnSetModified(WPARAM wParam, LPARAM lParam)
{
	std::string text;
	m_pMWpfWndControl->GetData(text);
	CString csText(text.data());
	MessageBoxW(csText, _T("CallBack"));
	return TRUE;

}


BOOL WpfContainer::Create(CWnd* pParentWnd)
{
	BOOL bRet = FALSE;
	bRet = CDialog::Create(IDD_CONTAINER, pParentWnd);
	return bRet;
}

void WpfContainer::GetWndHeightWidth(int* height, int* width)
{
	m_pMWpfWndControl->GetWndHeightWidth(height, width);
}

BEGIN_MESSAGE_MAP(WpfContainer, CDialogEx)
	ON_MESSAGE(WM_SET_MODIFIED_WPF_VIEW, &WpfContainer::OnSetModified)
END_MESSAGE_MAP()


// WpfContainer message handlers
