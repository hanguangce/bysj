// productset.cpp : implementation file
//

#include "stdafx.h"
#include "bysj.h"
#include "productset.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// productset

IMPLEMENT_DYNAMIC(productset, CRecordset)

productset::productset(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(productset)
	m_ic = 0;
	m_id = 0;
	m_oc = 0;
	m_pp = 0;
	m_pm = _T("");
	m_kh = _T("");
	m_ty = _T("");
	m_jx = _T("");
	m_pn0 = _T("");
	m_p0 = _T("");
	m_prod = _T("");
	m_pn1 = _T("");
	m_ph1 = _T("");
	m_nFields = 13;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString productset::GetDefaultConnect()
{
	return _T("ODBC;DSN=bysj_db");
}

CString productset::GetDefaultSQL()
{
	return _T("[product]");
}

void productset::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(productset)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[id]"), m_id);
	RFX_Long(pFX, _T("[ic]"), m_ic);
	RFX_Long(pFX, _T("[oc]"), m_oc);
	RFX_Long(pFX, _T("[pp]"), m_pp);
	RFX_Text(pFX, _T("[pm]"), m_pm);
	RFX_Text(pFX, _T("[kh]"), m_kh);
	RFX_Text(pFX, _T("[ty]"), m_ty);
	RFX_Text(pFX, _T("[jx]"), m_jx);
	RFX_Text(pFX, _T("[pn0]"), m_pn0);
	RFX_Text(pFX, _T("[p0]"), m_p0);
	RFX_Text(pFX, _T("[prod]"), m_prod);
	RFX_Text(pFX, _T("[pn1]"), m_pn1);
	RFX_Text(pFX, _T("[ph1]"), m_ph1);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// productset diagnostics

#ifdef _DEBUG
void productset::AssertValid() const
{
	CRecordset::AssertValid();
}

void productset::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
