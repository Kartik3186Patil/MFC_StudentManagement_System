
// MFC_StudentManage.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMFCStudentManageApp:
// See MFC_StudentManage.cpp for the implementation of this class
//

class CMFCStudentManageApp : public CWinApp
{
public:
	CMFCStudentManageApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMFCStudentManageApp theApp;
