
// Project 1.h : main header file for the Project 1 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CProject1App:
// See Project 1.cpp for the implementation of this class
//

class CProject1App : public CWinAppEx
{
public:
	CProject1App();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CProject1App theApp;
