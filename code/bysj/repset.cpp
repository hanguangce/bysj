// repset.cpp : implementation file
//

#include "stdafx.h"
#include "bysj.h"
#include "repset.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// repset

IMPLEMENT_DYNAMIC(repset, CRecordset)

repset::repset(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(repset)
	m_ic = 0;
	m_ct = 0;
	m_ct0 = 0;
	m_mg = _T("");
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString repset::GetDefaultConnect()
{
	return _T("ODBC;DSN=bysj_db");
}

CString repset::GetDefaultSQL()
{
	return _T("[rep]");
}

void repset::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(repset)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ic]"), m_ic);
	RFX_Long(pFX, _T("[ct]"), m_ct);
	RFX_Long(pFX, _T("[ct0]"), m_ct0);
	RFX_Text(pFX, _T("[mg]"), m_mg);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// repset diagnostics

#ifdef _DEBUG
void repset::AssertValid() const
{
	CRecordset::AssertValid();
}

void repset::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
