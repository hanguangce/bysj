// Yfbh.cpp : implementation file
//

#include "stdafx.h"
#include "bysj.h"
#include "Yfbh.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Yfbh dialog


Yfbh::Yfbh(CWnd* pParent /*=NULL*/)
	: CDialog(Yfbh::IDD, pParent)
{
	//{{AFX_DATA_INIT(Yfbh)
	m_ctrlist = _T("");
	//}}AFX_DATA_INIT
	nIndex=0;
	id=0;
}


void Yfbh::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Yfbh)
	DDX_CBString(pDX, IDC_COMBO_YFBH, m_ctrlist);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Yfbh, CDialog)
	//{{AFX_MSG_MAP(Yfbh)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Yfbh message handlers

BOOL Yfbh::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here



CString sqlstr;
	sqlstr.Format("select * from product");
	if(!pset.Open(AFX_DB_USE_DEFAULT_TYPE,sqlstr))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return 4;
	}

//////下拉列表
CComboBox* combo= ( CComboBox*)GetDlgItem(IDC_COMBO_YFBH);	

	int i=0;
	CString str;
	while(!pset.IsEOF())
	{
		str.Format("%ld",pset.m_ic);
		combo->AddString(str);

	//	m_ctrList.InsertItem(i,str);
		i++;
		pset.MoveNext();
	}
//	count=i;
	pset.Close();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void Yfbh::OnOK() 
{
	// TODO: Add extra validation here

	CComboBox* combo= ( CComboBox*)GetDlgItem(IDC_COMBO_YFBH);
	nIndex = combo->GetCurSel();
	combo->GetLBText(nIndex,s0);
	id=atol(s0);
	CDialog::OnOK();
}
