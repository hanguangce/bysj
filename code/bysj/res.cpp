// res.cpp : implementation file
//

#include "stdafx.h"
#include "bysj.h"
#include "res.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// res

IMPLEMENT_DYNAMIC(res, CRecordset)

res::res(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(res)
	//}}AFX_FIELD_INIT
	m_nDefaultType = dynaset;
}


CString res::GetDefaultConnect()
{
	return _T("ODBC;DSN=");
}

CString res::GetDefaultSQL()
{
	return _T("");
}

void res::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(res)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// res diagnostics

#ifdef _DEBUG
void res::AssertValid() const
{
	CRecordset::AssertValid();
}

void res::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
