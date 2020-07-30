
// MfcEmbedWpfDlg.h : header file
//

#pragma once

// CMfcEmbedWpfDlg dialog
class CMfcEmbedWpfDlg : public CDialogEx
{
// Construction
public:
	CMfcEmbedWpfDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCEMBEDWPF_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tab;
	afx_msg void OnSelchangeTabtest(NMHDR* pNMHDR, LRESULT* pResult);

protected:
	void ShowWpfView();
};
