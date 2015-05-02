#if !defined(AFX_DGKTJ_H__55FD9966_672C_48A9_950D_D520ED8C15DF__INCLUDED_)
#define AFX_DGKTJ_H__55FD9966_672C_48A9_950D_D520ED8C15DF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dgktj.h : header file
//
#include"productset.h"
/////////////////////////////////////////////////////////////////////////////
// Dgktj dialog

class Dgktj : public CDialog
{
// Construction
public:
	Dgktj(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Dgktj)
	enum { IDD = IDD_GKRH1 };
	long	m_gktj_num;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Dgktj)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Dgktj)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	productset m_recordset;
	int index;
	CString selStr;
	int CRH;
	int isok;
	long count;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DGKTJ_H__55FD9966_672C_48A9_950D_D520ED8C15DF__INCLUDED_)
