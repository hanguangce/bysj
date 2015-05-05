#if !defined(AFX_EMPTY_H__923AA2F4_98E9_41F7_A6C3_D30D83F322C3__INCLUDED_)
#define AFX_EMPTY_H__923AA2F4_98E9_41F7_A6C3_D30D83F322C3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// empty.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// empty recordset

class empty : public CRecordset
{
public:
	empty(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(empty)

// Field/Param Data
	//{{AFX_FIELD(empty, CRecordset)
	long	m_eid;
	CString	m_ename;
	CString	m_esex;
	CString	m_eage;
	long	m_emon;
	CString	m_eages;
	CString	m_ecot1;
	CString	m_ecot2;
	CString	m_ecp;
	CString	m_ecpn;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(empty)
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

#endif // !defined(AFX_EMPTY_H__923AA2F4_98E9_41F7_A6C3_D30D83F322C3__INCLUDED_)
