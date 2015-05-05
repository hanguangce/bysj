#if !defined(AFX_SSY_H__03BF2E26_B040_4646_845B_9474435A9077__INCLUDED_)
#define AFX_SSY_H__03BF2E26_B040_4646_845B_9474435A9077__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ssy.h : header file
//

#include "empty.h"
#include "productset.h"
#include "xsjlset.h"

/////////////////////////////////////////////////////////////////////////////
// Cssy dialog

class Cssy : public CDialog
{
// Construction
public:
	Cssy(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Cssy)
	enum { IDD = IDD_ShouYinYuan };
	CListCtrl	m_ctrList;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Cssy)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Cssy)
	afx_msg void OnAdd();
	afx_msg void OnTijiao();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	empty  emp;
	productset pset;
	xsjlset  xset;
	int Nnum;
	long syyid;
	long shyid;
	CString jyjl[20];

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SSY_H__03BF2E26_B040_4646_845B_9474435A9077__INCLUDED_)
