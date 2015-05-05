#if !defined(AFX_DATABASESET_H__0AA40B81_214C_4978_B7C8_1478A59D20EF__INCLUDED_)
#define AFX_DATABASESET_H__0AA40B81_214C_4978_B7C8_1478A59D20EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// databaseset.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// databaseset recordset

class databaseset : public CRecordset
{
public:
	databaseset(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(databaseset)

// Field/Param Data
	//{{AFX_FIELD(databaseset, CRecordset)
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
	long	m_ic;
	long	m_jp;
	long	m_bp;
	long	m_lr;
	long	m_id;
	long	m_ic2;
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
	long	m_ic3;
	long	m_ct;
	long	m_ct0;
	CString	m_mg;
	long	m_jylsh;
	long	m_syy;
	long	m_xsyg;
	CTime	m_jysj;
	long	m_jysl;
	long	m_jyje;
	long	m_lr2;
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
	//{{AFX_VIRTUAL(databaseset)
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

public:
	CString Sql;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATABASESET_H__0AA40B81_214C_4978_B7C8_1478A59D20EF__INCLUDED_)
