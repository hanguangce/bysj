// empty.cpp : implementation file
//

#include "stdafx.h"
#include "bysj.h"
#include "empty.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// empty

IMPLEMENT_DYNAMIC(empty, CRecordset)

empty::empty(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(empty)
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
	m_nFields = 10;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString empty::GetDefaultConnect()
{
	return _T("ODBC;DSN=bysj_db");
}

CString empty::GetDefaultSQL()
{
	return _T("[emtpys]");
}

void empty::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(empty)
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
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// empty diagnostics

#ifdef _DEBUG
void empty::AssertValid() const
{
	CRecordset::AssertValid();
}

void empty::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
