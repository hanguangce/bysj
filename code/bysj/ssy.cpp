// ssy.cpp : implementation file
//

#include "stdafx.h"
#include "bysj.h"
#include "ssy.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include "Yfbh.h"

/////////////////////////////////////////////////////////////////////////////
// Cssy dialog


Cssy::Cssy(CWnd* pParent /*=NULL*/)
	: CDialog(Cssy::IDD, pParent)
{
	//{{AFX_DATA_INIT(Cssy)
	//}}AFX_DATA_INIT

	syyid=0;
	shyid=0;
	Nnum=0;
}


void Cssy::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Cssy)
	DDX_Control(pDX, IDC_LIST1, m_ctrList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Cssy, CDialog)
	//{{AFX_MSG_MAP(Cssy)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(ID_TIJIAO, OnTijiao)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Cssy message handlers

void Cssy::OnAdd() 
{
	// TODO: Add your control notification handler code here

	if(Nnum<0||Nnum>10){
		MessageBox("每次交易衣服< 10  !","数据异常",MB_OK);
		return ;
	}
	Yfbh yfbh;
	yfbh.DoModal();
//	yfbh.id;

	UpdateData();	
	m_ctrList.DeleteAllItems();
	m_ctrList.SetRedraw(FALSE);	
	CString sqlstr;
	sqlstr.Format("select * from product where ic ="+yfbh.s0);
	if(!pset.Open(AFX_DB_USE_DEFAULT_TYPE,sqlstr))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}
	int i=0;
	CString str;
	while(!pset.IsEOF())
	{
			str.Format("%ld",i);
			m_ctrList.InsertItem(i,str);
			str.Format("%ld",pset.m_ic);
			m_ctrList.SetItemText(i,1,str);
			str.Format("%ld",pset.m_oc);
			m_ctrList.SetItemText(i,2,str);
	//		str.Format("%ld",m_record.m_pp);
	//		m_ctrList.SetItemText(i,3,str);
	//		m_ctrList.SetItemText(i,4,m_record.m_pm);
	//		m_ctrList.SetItemText(i,5,m_record.m_ty);

			i++;
			pset.MoveNext();
	}
	pset.Close();
	m_ctrList.SetRedraw(TRUE);
	UpdateData(true);
	CString Temp;
	Temp.Format("%d",pset.m_ic);
	if(i>0){
		jyjl[Nnum]=Temp;
		Nnum++;
	}
}

void Cssy::OnTijiao() 
{
	// TODO: Add your control notification handler code here
	int nIndex;
CString  s0;	
	CComboBox* combo= ( CComboBox*)GetDlgItem(IDC_COMBO_SYY);
	nIndex = combo->GetCurSel();
	combo->GetLBText(nIndex,s0);
	syyid=atol(s0);

CComboBox* combo0= ( CComboBox*)GetDlgItem(IDC_COMBO_SHY);
	nIndex = combo0->GetCurSel();
	combo0->GetLBText(nIndex,s0);
	shyid=atol(s0);

	CString strSQL;
	strSQL.Format("select * from xsjl ");


	if(!xset.Open())
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}
//	CString strSQL;
//
//	strSQL.Format("select * from rep where ic =13");
//
	if( !xset.CanAppend( ) )
	    return ;                      // no field values were set
	xset.AddNew();
	xset.m_syy	= syyid ;
	xset.m_xsyg =shyid;
	xset.m_jysl =Nnum;
	xset.m_p1 = jyjl[0];
	xset.m_p2= jyjl[1];
	xset.m_p3= jyjl[2];
	xset.m_p4 = jyjl[3];
	xset.m_p5 = jyjl[4];
	xset.m_p6 = jyjl[5];
	xset.m_p7 = jyjl[6];
	xset.m_p8 = jyjl[7];
	xset.m_p9 = jyjl[8];
	xset.m_p10 = jyjl[9];
	if( !xset.Update())
	{
	   AfxMessageBox( "Record not added; no field values were set." );
	    return ;
	}
	xset.Close();	
 
	
}

BOOL Cssy::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here	
	m_ctrList.InsertColumn(0,"排序");
	m_ctrList.InsertColumn(1,"衣服店内编码");
	m_ctrList.InsertColumn(2,"衣服二维码");
	m_ctrList.SetColumnWidth(0,60);
	m_ctrList.SetColumnWidth(1,80);
	m_ctrList.SetColumnWidth(2,80);
	m_ctrList.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);

CString sqlstr;
	sqlstr.Format("select * from emtpys");
	if(!emp.Open(AFX_DB_USE_DEFAULT_TYPE,sqlstr))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return 4;
	}

//////下拉列表
CComboBox* combo0= ( CComboBox*)GetDlgItem(IDC_COMBO_SYY);	

	int i=0;
	CString str;
	while(!emp.IsEOF())
	{
		str.Format("%ld",emp.m_eid);
		combo0->AddString(str);

	//	m_ctrList.InsertItem(i,str);
		i++;
		emp.MoveNext();
	}
//	count=i;
	emp.Close();


	sqlstr.Format("select * from emtpys");
	if(!emp.Open(AFX_DB_USE_DEFAULT_TYPE,sqlstr))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return 4;
	}

//////下拉列表
CComboBox* combo= ( CComboBox*)GetDlgItem(IDC_COMBO_SHY);	

	 i=0;

	while(!emp.IsEOF())
	{
		str.Format("%ld",emp.m_eid);
		combo->AddString(str);

	//	m_ctrList.InsertItem(i,str);
		i++;
		emp.MoveNext();
	}
//	count=i;
	emp.Close();


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
