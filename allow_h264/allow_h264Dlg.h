// allow_h264Dlg.h : header file
//

#pragma once


// Callow_h264Dlg dialog
class Callow_h264Dlg : public CDialog
{
// Construction
public:
	Callow_h264Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_ALLOW_H264_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
public:
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	void close();
};
