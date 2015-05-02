#if !defined(AFX_PRO_REP_SET_H__A6E82599_0213_43A1_B4F3_EE633FD19070__INCLUDED_)
#define AFX_PRO_REP_SET_H__A6E82599_0213_43A1_B4F3_EE633FD19070__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// pro_rep_set.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// pro_rep_set recordset

class pro_rep_set : public CRecordset
{
public:
	pro_rep_set(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(pro_rep_set)

// Field/Param Data
	//{{AFX_FIELD(pro_rep_set, CRecordset)
	long	m_id;
	long	m_ic;
	long	m_oc;
	long	m_pp;
	CString	m_pm;
	CString	m_kh;
	CString	m_ty;
	CString	m_jx;
	CString	m_pn0;
	CString	m_p0;
	CString	m_prod;
	CString	m_pn1;
	CString	m_ph1;
	long	m_ic2;
	long	m_ct;
	long	m_ct0;
	CString	m_mg;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(pro_rep_set)
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

#endif // !defined(AFX_PRO_REP_SET_H__A6E82599_0213_43A1_B4F3_EE633FD19070__INCLUDED_)
