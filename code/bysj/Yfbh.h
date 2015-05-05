#if !defined(AFX_YFBH_H__2A1309CF_5427_4385_8499_67B5C6E6D8A7__INCLUDED_)
#define AFX_YFBH_H__2A1309CF_5427_4385_8499_67B5C6E6D8A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Yfbh.h : header file
//
#include "productset.h"
/////////////////////////////////////////////////////////////////////////////
// Yfbh dialog

class Yfbh : public CDialog
{
// Construction
public:
	Yfbh(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Yfbh)
	enum { IDD = IDD_SYY_YFBH };
	CString	m_ctrlist;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Yfbh)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Yfbh)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	productset pset;
	int nIndex;
	long id;
	CString s0;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_YFBH_H__2A1309CF_5427_4385_8499_67B5C6E6D8A7__INCLUDED_)
