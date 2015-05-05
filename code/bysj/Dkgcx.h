#if !defined(AFX_DKGCX_H__CE479308_7C51_4E55_89CD_5899C701C3B5__INCLUDED_)
#define AFX_DKGCX_H__CE479308_7C51_4E55_89CD_5899C701C3B5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dkgcx.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Dkgcx dialog

class Dkgcx : public CDialog
{
// Construction
public:
	Dkgcx(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Dkgcx)
	enum { IDD = IDD_KGCX };
	long	m_edit0;
	long	m_edit1;
	long	m_edit2;
	long	m_edit3;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Dkgcx)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Dkgcx)
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	int button;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DKGCX_H__CE479308_7C51_4E55_89CD_5899C701C3B5__INCLUDED_)
