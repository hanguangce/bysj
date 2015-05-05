// databaseset.cpp : implementation file
//

#include "stdafx.h"
#include "bysj.h"
#include "databaseset.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// databaseset

IMPLEMENT_DYNAMIC(databaseset, CRecordset)

databaseset::databaseset(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(databaseset)
	m_eid = 0;
	m_ename = _T("");
	m_esex = _T("");
	m_eage = _T("");
	m_emon = 0;
	m_eages = _T("");
	m_ecot1 = _T("");
	m_ecot2 = _T("");
	m_ecp = _T("");
	m_ecpn = _T("");
	m_ic = 0;
	m_jp = 0;
	m_bp = 0;
	m_lr = 0;
	m_id = 0;
	m_ic2 = 0;
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
	m_ic3 = 0;
	m_ct = 0;
	m_ct0 = 0;
	m_mg = _T("");
	m_jylsh = 0;
	m_syy = 0;
	m_xsyg = 0;
	m_jysl = 0;
	m_jyje = 0;
	m_lr2 = 0;
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
	m_nFields = 48;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
	Sql.Format("select product.ic from emtpys,price,product,rep,xsjl");
}


CString databaseset::GetDefaultConnect()
{
	return _T("ODBC;DSN=bysj_db");
}

CString databaseset::GetDefaultSQL()
{
	return _T("[emtpys],[price],[product],[rep],[xsjl]");
}

void databaseset::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(databaseset)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[eid]"), m_eid);
	RFX_Text(pFX, _T("[ename]"), m_ename);
	RFX_Text(pFX, _T("[esex]"), m_esex);
	RFX_Text(pFX, _T("[eage]"), m_eage);
	RFX_Long(pFX, _T("[emon]"), m_emon);
	RFX_Text(pFX, _T("[eages]"), m_eages);
	RFX_Text(pFX, _T("[ecot1]"), m_ecot1);
	RFX_Text(pFX, _T("[ecot2]"), m_ecot2);
	RFX_Text(pFX, _T("[ecp]"), m_ecp);
	RFX_Text(pFX, _T("[ecpn]"), m_ecpn);
	RFX_Long(pFX, _T("[price].[ic]"), m_ic);
	RFX_Long(pFX, _T("[jp]"), m_jp);
	RFX_Long(pFX, _T("[bp]"), m_bp);
	RFX_Long(pFX, _T("[price].[lr]"), m_lr);
	RFX_Long(pFX, _T("[id]"), m_id);
	RFX_Long(pFX, _T("[product].[ic]"), m_ic2);
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
	RFX_Long(pFX, _T("[rep].[ic]"), m_ic3);
	RFX_Long(pFX, _T("[ct]"), m_ct);
	RFX_Long(pFX, _T("[ct0]"), m_ct0);
	RFX_Text(pFX, _T("[mg]"), m_mg);
	RFX_Long(pFX, _T("[jylsh]"), m_jylsh);
	RFX_Long(pFX, _T("[syy]"), m_syy);
	RFX_Long(pFX, _T("[xsyg]"), m_xsyg);
	RFX_Date(pFX, _T("[jysj]"), m_jysj);
	RFX_Long(pFX, _T("[jysl]"), m_jysl);
	RFX_Long(pFX, _T("[jyje]"), m_jyje);
	RFX_Long(pFX, _T("[xsjl].[lr]"), m_lr2);
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
// databaseset diagnostics

#ifdef _DEBUG
void databaseset::AssertValid() const
{
	CRecordset::AssertValid();
}

void databaseset::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
