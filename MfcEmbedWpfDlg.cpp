
// MfcEmbedWpfDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MfcEmbedWpf.h"
#include "MfcEmbedWpfDlg.h"
#include "afxdialogex.h"
#include "WpfContainer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMfcEmbedWpfDlg dialog



CMfcEmbedWpfDlg::CMfcEmbedWpfDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCEMBEDWPF_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMfcEmbedWpfDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TABTest, m_tab);
}

BEGIN_MESSAGE_MAP(CMfcEmbedWpfDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TABTest, &CMfcEmbedWpfDlg::OnSelchangeTabtest)
END_MESSAGE_MAP()


// CMfcEmbedWpfDlg message handlers

BOOL CMfcEmbedWpfDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	CRect rs;
	m_tab.GetClientRect(&rs);
	ShowWpfView();
	return TRUE;  
	//rs.top += 1;
	//rs.bottom -= 60;
	//rs.left += 1;
	//rs.right -= 2;
	//m_tab1.MoveWindow(&rs);
	//m_tab2.MoveWindow(&rs);
	//m_tab1.ShowWindow(TRUE);
	//m_tab2.ShowWindow(FALSE);
	//m_tab.SetCurSel(0);
}

void CMfcEmbedWpfDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMfcEmbedWpfDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMfcEmbedWpfDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMfcEmbedWpfDlg::OnSelchangeTabtest(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: Add your control notification handler code here
	int nIndex = m_tab.GetCurSel();
}

void CMfcEmbedWpfDlg::ShowWpfView()
{
	WpfContainer* wpfContainer = new WpfContainer;
	wpfContainer->Create(this);

	CRect rc(0, 0, 0, 0);
	GetWindowRect(&rc);
	ScreenToClient(&rc);
	CRect rc2(0, 0, 0, 0);
	wpfContainer->GetWindowRect(&rc2);
	ScreenToClient(&rc2);

	rc2.top  = rc.top + 53;
	rc2.left = rc.left + 22;

	int width, height;

	wpfContainer->GetWndHeightWidth(&height,&width);
	wpfContainer->SetWindowPos(NULL, rc2.TopLeft().x, rc2.TopLeft().y, width, height, SWP_NOZORDER);

	CString szTitle = _T("T1");

	TC_ITEM TItem;
	TItem.mask = TCIF_TEXT;
	//TItem.mask |= TCIF_IMAGE;

	TItem.pszText = (LPTSTR)(LPCTSTR)szTitle;
	//TItem.iImage = m_TabImageList.Add(pDlg->GetIcon(TRUE));
	m_tab.InsertItem(0, &TItem);
	wpfContainer->ShowWindow(SW_SHOW);
}
