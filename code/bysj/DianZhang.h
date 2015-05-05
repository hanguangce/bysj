#if !defined(AFX_DIANZHANG_H__62B39E87_5541_424E_9E70_68E2F7547A10__INCLUDED_)
#define AFX_DIANZHANG_H__62B39E87_5541_424E_9E70_68E2F7547A10__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DianZhang.h : header file
//

#include"productset.h"
#include"repset.h"
#include"empty.h"
#include"priceset.h"
#include"xsjlset.h"

/////////////////////////////////////////////////////////////////////////////
// CDianZhang dialog

class CDianZhang : public CDialog
{
// Construction
public:
	CDianZhang(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDianZhang)
	enum { IDD = IDD_DianZhang };
	CListCtrl	m_ctrList;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDianZhang)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDianZhang)
	virtual BOOL OnInitDialog();
	afx_msg void OnOk2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	productset set0;
	repset		set1;
	empty		set2;
	priceset	set3;
	xsjlset		set4;
	int 	mode;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIANZHANG_H__62B39E87_5541_424E_9E70_68E2F7547A10__INCLUDED_)
