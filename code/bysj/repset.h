#if !defined(AFX_REPSET_H__012D9E29_876B_4E7C_A4E2_79A2554FE907__INCLUDED_)
#define AFX_REPSET_H__012D9E29_876B_4E7C_A4E2_79A2554FE907__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// repset.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// repset recordset

class repset : public CRecordset
{
public:
	repset(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(repset)

// Field/Param Data
	//{{AFX_FIELD(repset, CRecordset)
	long	m_ic;
	long	m_ct;
	long	m_ct0;
	CString	m_mg;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(repset)
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

#endif // !defined(AFX_REPSET_H__012D9E29_876B_4E7C_A4E2_79A2554FE907__INCLUDED_)
