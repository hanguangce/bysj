// KuGuan.cpp : implementation file
//

#include "stdafx.h"
#include "bysj.h"
#include "KuGuan.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// KuGuan dialog


KuGuan::KuGuan(CWnd* pParent /*=NULL*/)
	: CDialog(KuGuan::IDD, pParent)
{
	//{{AFX_DATA_INIT(KuGuan)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void KuGuan::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(KuGuan)
	DDX_Control(pDX, IDC_LIST1, m_ctrList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(KuGuan, CDialog)
	//{{AFX_MSG_MAP(KuGuan)
	ON_WM_PAINT()
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////

int KuGuan::DoModal() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDialog::DoModal();
}

void KuGuan::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	
	// Do not call CDialog::OnPaint() for painting messages
}

int KuGuan::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	
	return 0;
}

BOOL KuGuan::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here	
	m_ctrList.InsertColumn(0,"读者编号");
	m_ctrList.InsertColumn(1,"读者姓名");
	m_ctrList.InsertColumn(2,"读者性别");
	m_ctrList.InsertColumn(3,"读者类别");
	m_ctrList.InsertColumn(4,"登记日期");
	m_ctrList.InsertColumn(5,"所属部门");
	m_ctrList.InsertColumn(6,"联系电话");
	m_ctrList.InsertColumn(7,"地址");
	m_ctrList.InsertColumn(8,"备注说明");

	m_ctrList.SetColumnWidth(0,60);
	m_ctrList.SetColumnWidth(1,120);
	m_ctrList.SetColumnWidth(2,80);
	m_ctrList.SetColumnWidth(3,80);
	m_ctrList.SetColumnWidth(4,80);
	m_ctrList.SetColumnWidth(5,80);
	m_ctrList.SetColumnWidth(6,80);
	m_ctrList.SetColumnWidth(7,100);
	m_ctrList.SetColumnWidth(8,100);
	m_ctrList.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void KuGuan::OnOK() 
{
	// TODO: Add extra validation here
	
//	CDialog::OnOK();


UpdateData();
	CString strSQL;
	if(1)
	{
		strSQL.Format("select * from product");
	}

	else 
	{
		strSQL="select * from product";
	}
	m_ctrList.DeleteAllItems();
	m_ctrList.SetRedraw(FALSE);

	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}
	
	int i=0;
	CString strTime;
	while(!m_recordset.IsEOF())
	{
		m_ctrList.InsertItem(i,"12");
		strTime.Format("%ld",m_recordset.m_ic);
		m_ctrList.SetItemText(i,1,strTime);
		m_ctrList.SetItemText(i,2,m_recordset.m_pm);
	//	m_ctrList.SetItemText(i,3,m_recordset.m_jx);
	//	m_ctrList.SetItemText(i,4,m_recordset.m_oc);
		i++;
		m_recordset.MoveNext();
	}
	m_recordset.Close();
	m_ctrList.SetRedraw(TRUE);	

}
