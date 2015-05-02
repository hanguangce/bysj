#if !defined(AFX_DIANZHANG_H__62B39E87_5541_424E_9E70_68E2F7547A10__INCLUDED_)
#define AFX_DIANZHANG_H__62B39E87_5541_424E_9E70_68E2F7547A10__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DianZhang.h : header file
//

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
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDianZhang)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDianZhang)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIANZHANG_H__62B39E87_5541_424E_9E70_68E2F7547A10__INCLUDED_)
