// bysj.h : main header file for the BYSJ application
//

#if !defined(AFX_BYSJ_H__0F581C26_40B0_46E3_84E9_0EC5ECFD9686__INCLUDED_)
#define AFX_BYSJ_H__0F581C26_40B0_46E3_84E9_0EC5ECFD9686__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBysjApp:
// See bysj.cpp for the implementation of this class
//

class CBysjApp : public CWinApp
{
public:
	CBysjApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBysjApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBysjApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

//	CDiolag m_recordset;
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BYSJ_H__0F581C26_40B0_46E3_84E9_0EC5ECFD9686__INCLUDED_)
