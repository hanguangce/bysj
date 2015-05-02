#if !defined(AFX_RES_H__EF73ECBE_6974_49B3_B6F0_380095F04E1B__INCLUDED_)
#define AFX_RES_H__EF73ECBE_6974_49B3_B6F0_380095F04E1B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// res.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// res recordset

class res : public CRecordset
{
public:
	res(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(res)

// Field/Param Data
	//{{AFX_FIELD(res, CRecordset)
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(res)
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

#endif // !defined(AFX_RES_H__EF73ECBE_6974_49B3_B6F0_380095F04E1B__INCLUDED_)
