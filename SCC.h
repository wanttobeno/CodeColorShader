// SCC.h : main header file for the SCC application
//

#if !defined(AFX_SCC_H__11D3B85C_AAF9_4583_A84F_E3FDF0DBED49__INCLUDED_)
#define AFX_SCC_H__11D3B85C_AAF9_4583_A84F_E3FDF0DBED49__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSCCApp:
// See SCC.cpp for the implementation of this class
//

class CSCCApp : public CWinApp
{
public:
	CSCCApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSCCApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSCCApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCC_H__11D3B85C_AAF9_4583_A84F_E3FDF0DBED49__INCLUDED_)
