#if !defined(AFX_KUGUANSET_H__7F7B98D5_85CD_4331_B751_65CEC019C7DC__INCLUDED_)
#define AFX_KUGUANSET_H__7F7B98D5_85CD_4331_B751_65CEC019C7DC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// KuguanSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CKuguanSet recordset

class CKuguanSet : public CRecordset
{
public:
	CKuguanSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CKuguanSet)

// Field/Param Data
	//{{AFX_FIELD(CKuguanSet, CRecordset)
	long	m_id;
	CString	m_name;
	CString	m_type;
	CString	m_subtype;
	CString	m_pinpai;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKuguanSet)
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

#endif // !defined(AFX_KUGUANSET_H__7F7B98D5_85CD_4331_B751_65CEC019C7DC__INCLUDED_)
