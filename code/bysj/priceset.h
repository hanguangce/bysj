#if !defined(AFX_PRICESET_H__4E682979_2C55_426D_BE1E_31808E374A08__INCLUDED_)
#define AFX_PRICESET_H__4E682979_2C55_426D_BE1E_31808E374A08__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// priceset.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// priceset recordset

class priceset : public CRecordset
{
public:
	priceset(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(priceset)

// Field/Param Data
	//{{AFX_FIELD(priceset, CRecordset)
	long	m_ic;
	long	m_jp;
	long	m_bp;
	long	m_lr;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(priceset)
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

#endif // !defined(AFX_PRICESET_H__4E682979_2C55_426D_BE1E_31808E374A08__INCLUDED_)
