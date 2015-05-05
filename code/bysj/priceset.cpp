// priceset.cpp : implementation file
//

#include "stdafx.h"
#include "bysj.h"
#include "priceset.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// priceset

IMPLEMENT_DYNAMIC(priceset, CRecordset)

priceset::priceset(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(priceset)
	m_ic = 0;
	m_jp = 0;
	m_bp = 0;
	m_lr = 0;
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString priceset::GetDefaultConnect()
{
	return _T("ODBC;DSN=bysj_db");
}

CString priceset::GetDefaultSQL()
{
	return _T("[price]");
}

void priceset::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(priceset)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ic]"), m_ic);
	RFX_Long(pFX, _T("[jp]"), m_jp);
	RFX_Long(pFX, _T("[bp]"), m_bp);
	RFX_Long(pFX, _T("[lr]"), m_lr);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// priceset diagnostics

#ifdef _DEBUG
void priceset::AssertValid() const
{
	CRecordset::AssertValid();
}

void priceset::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
