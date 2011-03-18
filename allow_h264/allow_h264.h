// allow_h264.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Callow_h264App:
// See allow_h264.cpp for the implementation of this class
//

class Callow_h264App : public CWinApp
{
public:
	Callow_h264App();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern Callow_h264App theApp;