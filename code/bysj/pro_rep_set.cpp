// pro_rep_set.cpp : implementation file
//

#include "stdafx.h"
#include "bysj.h"
#include "pro_rep_set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// pro_rep_set

IMPLEMENT_DYNAMIC(pro_rep_set, CRecordset)

pro_rep_set::pro_rep_set(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(pro_rep_set)
	m_id = 0;
	m_ic = 0;
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
	m_ic2 = 0;
	m_ct = 0;
	m_ct0 = 0;
	m_mg = _T("");
	m_nFields = 17;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString pro_rep_set::GetDefaultConnect()
{
	return _T("ODBC;DSN=bysj_db");
}

CString pro_rep_set::GetDefaultSQL()
{
	return _T("[product],[rep]");
}

void pro_rep_set::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(pro_rep_set)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[id]"), m_id);
	RFX_Long(pFX, _T("[product].[ic]"), m_ic);
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
	RFX_Long(pFX, _T("[rep].[ic]"), m_ic2);
	RFX_Long(pFX, _T("[ct]"), m_ct);
	RFX_Long(pFX, _T("[ct0]"), m_ct0);
	RFX_Text(pFX, _T("[mg]"), m_mg);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// pro_rep_set diagnostics

#ifdef _DEBUG
void pro_rep_set::AssertValid() const
{
	CRecordset::AssertValid();
}

void pro_rep_set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
