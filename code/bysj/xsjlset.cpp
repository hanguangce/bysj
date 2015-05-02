// xsjlset.cpp : implementation file
//

#include "stdafx.h"
#include "bysj.h"
#include "xsjlset.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// xsjlset

IMPLEMENT_DYNAMIC(xsjlset, CRecordset)

xsjlset::xsjlset(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(xsjlset)
	m_jylsh = 0;
	m_syy = 0;
	m_xsyg = 0;
	m_jysl = 0;
	m_jyje = 0;
	m_lr = 0;
	m_p1 = _T("");
	m_p2 = _T("");
	m_p3 = _T("");
	m_p4 = _T("");
	m_p5 = _T("");
	m_p6 = _T("");
	m_p7 = _T("");
	m_p8 = _T("");
	m_p9 = _T("");
	m_p10 = _T("");
	m_nFields = 17;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString xsjlset::GetDefaultConnect()
{
	return _T("ODBC;DSN=bysj_db");
}

CString xsjlset::GetDefaultSQL()
{
	return _T("[xsjl]");
}

void xsjlset::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(xsjlset)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[jylsh]"), m_jylsh);
	RFX_Long(pFX, _T("[syy]"), m_syy);
	RFX_Long(pFX, _T("[xsyg]"), m_xsyg);
	RFX_Date(pFX, _T("[jysj]"), m_jysj);
	RFX_Long(pFX, _T("[jysl]"), m_jysl);
	RFX_Long(pFX, _T("[jyje]"), m_jyje);
	RFX_Long(pFX, _T("[lr]"), m_lr);
	RFX_Text(pFX, _T("[p1]"), m_p1);
	RFX_Text(pFX, _T("[p2]"), m_p2);
	RFX_Text(pFX, _T("[p3]"), m_p3);
	RFX_Text(pFX, _T("[p4]"), m_p4);
	RFX_Text(pFX, _T("[p5]"), m_p5);
	RFX_Text(pFX, _T("[p6]"), m_p6);
	RFX_Text(pFX, _T("[p7]"), m_p7);
	RFX_Text(pFX, _T("[p8]"), m_p8);
	RFX_Text(pFX, _T("[p9]"), m_p9);
	RFX_Text(pFX, _T("[p10]"), m_p10);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// xsjlset diagnostics

#ifdef _DEBUG
void xsjlset::AssertValid() const
{
	CRecordset::AssertValid();
}

void xsjlset::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
