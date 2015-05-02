// Dgkrh.cpp : implementation file
//

#include "stdafx.h"
#include "bysj.h"
#include "Dgkrh.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Dgkrh dialog


Dgkrh::Dgkrh(CWnd* pParent /*=NULL*/)
	: CDialog(Dgkrh::IDD, pParent)
{
	//{{AFX_DATA_INIT(Dgkrh)
	m_kc_rh = 0;
	//}}AFX_DATA_INIT
	CRH=0;//0 in  1 out
}


void Dgkrh::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Dgkrh)
	DDX_Text(pDX, IDC_EDIT1, m_kc_rh);
	DDV_MinMaxLong(pDX, m_kc_rh, 0, 99999);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Dgkrh, CDialog)
	//{{AFX_MSG_MAP(Dgkrh)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Dgkrh message handlers

void Dgkrh::OnOK() 
{
	// TODO: Add extra validation here
		UpdateData(true);
//UpdateData(false);
	CString str;
	str.Format("%ld",m_kc_rh);
//	

	CComboBox* combo= ( CComboBox*)GetDlgItem(IDC_COMBO_KGRH);
	index = combo->GetCurSel();
	combo->GetLBText(index,selStr);
	str+=" "+index;
	str+="_"+selStr;
	MessageBox(""+str);	
	CDialog::OnOK();
}

BOOL Dgkrh::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
CString sqlstr;
	sqlstr.Format("select * from rep ");
	if(!m_record.Open(AFX_DB_USE_DEFAULT_TYPE,sqlstr))
	{
		MessageBox("�����ݿ�ʧ��!","���ݿ����",MB_OK);
		return 4;
	}

//////�����б�
CComboBox* combo= ( CComboBox*)GetDlgItem(IDC_COMBO_KGRH);	

	int i=0;
	CString str;
	while(!m_record.IsEOF())
	{
		str.Format("%ld",m_record.m_ic);
		combo->AddString(str);

	//	m_ctrList.InsertItem(i,str);
		i++;
		m_record.MoveNext();
	}
	m_record.Close();	

combo->SetCurSel(0);
///////


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

int Dgkrh::DoModal() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	if(CRH)
	{
		GetDlgItem(IDC_STATIC_CRH_ID)->SetWindowText("�����Ϣ�ı���");
		GetDlgItem(IDC_STATIC_CRH_NUM)->SetWindowText("�������");
	}
	else{
		GetDlgItem(IDC_STATIC_CRH_ID)->SetWindowText("������Ϣ�ı���");
		GetDlgItem(IDC_STATIC_CRH_NUM)->SetWindowText("��������");
	}
	return CDialog::DoModal();
}
