// KuguanSet.cpp : implementation file
//

#include "stdafx.h"
#include "bysj.h"
#include "KuguanSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKuguanSet

IMPLEMENT_DYNAMIC(CKuguanSet, CRecordset)

CKuguanSet::CKuguanSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CKuguanSet)
	m_id = 0;
	m_name = _T("");
	m_type = _T("");
	m_subtype = _T("");
	m_pinpai = _T("");
	m_nFields = 5;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CKuguanSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=a");
}

CString CKuguanSet::GetDefaultSQL()
{
	return _T("[dbo].[product]");
}

void CKuguanSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CKuguanSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[id]"), m_id);
	RFX_Text(pFX, _T("[name]"), m_name);
	RFX_Text(pFX, _T("[type]"), m_type);
	RFX_Text(pFX, _T("[subtype]"), m_subtype);
	RFX_Text(pFX, _T("[pinpai]"), m_pinpai);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CKuguanSet diagnostics

#ifdef _DEBUG
void CKuguanSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CKuguanSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
