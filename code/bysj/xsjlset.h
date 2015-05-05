#if !defined(AFX_XSJLSET_H__691E44CB_C4EE_4387_8967_05827F724C73__INCLUDED_)
#define AFX_XSJLSET_H__691E44CB_C4EE_4387_8967_05827F724C73__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// xsjlset.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// xsjlset recordset

class xsjlset : public CRecordset
{
public:
	xsjlset(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(xsjlset)

// Field/Param Data
	//{{AFX_FIELD(xsjlset, CRecordset)
	long	m_jylsh;
	long	m_syy;
	long	m_xsyg;
	CTime	m_jysj;
	long	m_jysl;
	long	m_jyje;
	long	m_lr;
	CString	m_p1;
	CString	m_p2;
	CString	m_p3;
	CString	m_p4;
	CString	m_p5;
	CString	m_p6;
	CString	m_p7;
	CString	m_p8;
	CString	m_p9;
	CString	m_p10;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(xsjlset)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XSJLSET_H__691E44CB_C4EE_4387_8967_05827F724C73__INCLUDED_)
