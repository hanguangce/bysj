#if !defined(AFX_PRODUCTSET_H__49E49144_E1A0_48B5_A94D_864A1B2749FE__INCLUDED_)
#define AFX_PRODUCTSET_H__49E49144_E1A0_48B5_A94D_864A1B2749FE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// productset.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// productset recordset

class productset : public CRecordset
{
public:
	productset(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(productset)

// Field/Param Data
	//{{AFX_FIELD(productset, CRecordset)
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
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(productset)
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

#endif // !defined(AFX_PRODUCTSET_H__49E49144_E1A0_48B5_A94D_864A1B2749FE__INCLUDED_)
