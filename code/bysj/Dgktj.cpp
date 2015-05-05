// Dgktj.cpp : implementation file
//

#include "stdafx.h"
#include "bysj.h"
#include "Dgktj.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Dgktj dialog


Dgktj::Dgktj(CWnd* pParent /*=NULL*/)
	: CDialog(Dgktj::IDD, pParent)
{
	//{{AFX_DATA_INIT(Dgktj)
	m_gktj_num = 0;
	//}}AFX_DATA_INIT
	isok=0;
	count=0;
}


void Dgktj::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Dgktj)
	DDX_Text(pDX, IDC_EDIT1, m_gktj_num);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Dgktj, CDialog)
	//{{AFX_MSG_MAP(Dgktj)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Dgktj message handlers

BOOL Dgktj::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
CString sqlstr;
	sqlstr.Format("select * from product where ic not in (select ic from rep)");
	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,sqlstr))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return 4;
	}

//////下拉列表
CComboBox* combo= ( CComboBox*)GetDlgItem(IDC_COMBO_KGRH0);	

	int i=0;
	CString str;
	while(!m_recordset.IsEOF())
	{
		str.Format("%ld",m_recordset.m_ic);
		combo->AddString(str);

	//	m_ctrList.InsertItem(i,str);
		i++;
		m_recordset.MoveNext();
	}
	count=i;
	m_recordset.Close();	
//	CString str;
	str.Format("%ld",count);
//	MessageBox(str);
	combo->SetCurSel(0);
	if(count==0){
		MessageBox("没有发现可添加数据");		
		OnOK();
	}
///////
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void Dgktj::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(true);
//UpdateData(false);

//	str.Format("%ld",m_kc_rh);
//	
	if(count>0){AfxMessageBox("123456789"); 
	CComboBox* combo= ( CComboBox*)GetDlgItem(IDC_COMBO_KGRH0);
	index = combo->GetCurSel();
	combo->GetLBText(index,selStr);
//	str+=" "+index;
	isok=1;	
	}
	else
		isok=0;

	CDialog::OnOK();
}
