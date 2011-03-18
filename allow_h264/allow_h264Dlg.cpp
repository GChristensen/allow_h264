// allow_h264Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "allow_h264.h"
#include "allow_h264Dlg.h"

#include <process.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Callow_h264Dlg dialog




Callow_h264Dlg::Callow_h264Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(Callow_h264Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Callow_h264Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Callow_h264Dlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDCANCEL, &Callow_h264Dlg::OnBnClickedCancel)
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()


// Callow_h264Dlg message handlers

BOOL Callow_h264Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void Callow_h264Dlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR Callow_h264Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void Callow_h264Dlg::close()
{
	OnCancel();
}

bool resume = true;

void watcher_thread(void * dialog)
{
	while (resume)
	{
		HWND confirmation = ::FindWindow(_T("QWidget"), _T("Confirmation"));

		if (confirmation)
			::SendMessage(confirmation, WM_CLOSE, 0, 0);

		Sleep(500);
	}

	((Callow_h264Dlg *)dialog)->close();
}

void Callow_h264Dlg::OnBnClickedCancel()
{
	resume = false;
}

void Callow_h264Dlg::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialog::OnShowWindow(bShow, nStatus);

	_beginthread(watcher_thread, 0, this);
}
