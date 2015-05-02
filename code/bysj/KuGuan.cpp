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
	sqlstr="";
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
	ON_UPDATE_COMMAND_UI(ID_hwidfo, OnUpdatehwidfo)
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
//	m_ctrList.InsertColumn(0,"序号");
	m_ctrList.InsertColumn(1,"内码");
	m_ctrList.InsertColumn(2,"原厂条形码");
	m_ctrList.InsertColumn(3,"品牌");
	m_ctrList.InsertColumn(4,"品名");
	m_ctrList.InsertColumn(5,"款号");
	m_ctrList.InsertColumn(6,"类别");
	m_ctrList.InsertColumn(7,"库存数量");
	m_ctrList.InsertColumn(8,"已销售数量");
	m_ctrList.InsertColumn(9,"经办人");

	m_ctrList.SetColumnWidth(0,60);
	m_ctrList.SetColumnWidth(1,80);
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
		strSQL.Format("select * from rep where ic =13");
	}

	else 
	{
//		strSQL=m_recordset.Sql;
	}
	m_ctrList.DeleteAllItems();
	m_ctrList.SetRedraw(FALSE);

	if(!m_recordset0.Open(AFX_DB_USE_DEFAULT_TYPE,strSQL))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}


	if( !m_recordset0.CanUpdate() )
{
    AfxMessageBox( "Unable to update the Student recordset." );
    return;
}

/*
if( !m_recordset0.CanAppend( ) )
    return ;                      // no field values were set
m_recordset0.AddNew( );
m_recordset0.m_ic = 13 ;

if( !m_recordset0.Update( ) )
{
    AfxMessageBox( "Record not added; no field values were set." );
    return ;
}

*/
	int i=0;
	CString str;
	while(!m_recordset0.IsEOF())
	{
	m_recordset0.Edit();
	m_recordset0.m_ct=25;
	if(!m_recordset0.Update())
{
    AfxMessageBox( "Record not updated; no field values were set." );
    return ;
}

//		m_recordset0.m_ct=22;
		i++;
		m_recordset0.MoveNext();
	}

	
	m_recordset0.Close();

	m_ctrList.SetRedraw(TRUE);	

}

void KuGuan::OnUpdatehwidfo(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

BOOL KuGuan::OnCommand(WPARAM wParam, LPARAM lParam) 
{
	// TODO: Add your specialized code here and/or call the base class
	int menuID = LOWORD(wParam); 
	switch(menuID) { 
		case ID_KUGUAN0: 
			OnCX0(); 
			break;
		case ID_KUGUAN1:
			OnCX1();
	//		AfxMessageBox("222"); 
			break; 
		case ID_KUGUAN2:
			OnCX2();
	//		AfxMessageBox("333"); 
			break; 
		case ID_KUGUAN3:
			OnCX3();
	//		AfxMessageBox("444");
			break; 
		default: break; 
	}
	return CDialog::OnCommand(wParam, lParam);
}

void KuGuan::OnCX0()
{
//	AfxMessageBox("222");
	dkucx.DoModal();
	int type=0;	
	switch(dkucx.button) { 
		case 1: 
			type=1;
			sqlstr.Format("select * from product where ic=%d",dkucx.m_edit0);
			break;
		case 2:
			type=2;
			sqlstr.Format("select * from product right join rep  on product.ic =  rep.ic  where rep.ic > %ld",dkucx.m_edit1);
			break; 
		case 3:
			type=2;
			sqlstr.Format("select * from product right join rep  on product.ic =  rep.ic  where rep.ic = %ld",dkucx.m_edit2);
			break; 
		case 4:
			type=2;
			sqlstr.Format("select * from product right join rep  on product.ic =  rep.ic  where rep.ic < %ld",dkucx.m_edit3);
			break; 
		default: break; 
	}

	UpdateData();
	m_ctrList.DeleteAllItems();
	m_ctrList.SetRedraw(FALSE);	

	if(type==1)
	{
			if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,sqlstr))
		{
			MessageBox("打开数据库失败!","数据库错误",MB_OK);
			return ;
		}

		int i=0;
		CString str;
		while(!m_recordset.IsEOF())
		{
			str.Format("%ld",i);
			m_ctrList.InsertItem(i,str);
			str.Format("%ld",m_recordset.m_ic);
			m_ctrList.SetItemText(i,1,str);
			str.Format("%ld",m_recordset.m_oc);
			m_ctrList.SetItemText(i,2,str);
			str.Format("%ld",m_recordset.m_pp);
			m_ctrList.SetItemText(i,3,str);
			m_ctrList.SetItemText(i,4,m_recordset.m_pm);
			m_ctrList.SetItemText(i,5,m_record.m_ty);
			i++;
			m_recordset.MoveNext();
		}
		m_recordset.Close();
	}
	else if(type==2)
	{
		if(!m_record.Open(AFX_DB_USE_DEFAULT_TYPE,sqlstr))
		{
			MessageBox("打开数据库失败!","数据库错误",MB_OK);
			return ;
		}
	
		int i=0;
		CString str;
		while(!m_record.IsEOF())
		{
			str.Format("%ld",i);
			m_ctrList.InsertItem(i,str);
			str.Format("%ld",m_record.m_ic);
			m_ctrList.SetItemText(i,1,str);
			str.Format("%ld",m_record.m_oc);
			m_ctrList.SetItemText(i,2,str);
			str.Format("%ld",m_record.m_pp);
			m_ctrList.SetItemText(i,3,str);
			m_ctrList.SetItemText(i,4,m_record.m_pm);
			m_ctrList.SetItemText(i,5,m_record.m_ty);
			str.Format("%ld",m_record.m_ct);
			m_ctrList.SetItemText(i,6,str);
			str.Format("%ld",m_record.m_ct0);
			m_ctrList.SetItemText(i,7,str);
			m_ctrList.SetItemText(i,8,m_record.m_mg);
			i++;
			m_record.MoveNext();
		}
		m_record.Close();
	
	}
	m_ctrList.SetRedraw(TRUE);
}


void KuGuan::OnCX1()
{
	dkucx.DoModal();
	sqlstr.Format("UPDATE rep SET ct=24    WHERE ic = 12   ");
	UpdateData();
	m_ctrList.DeleteAllItems();
	m_ctrList.SetRedraw(FALSE);	

	if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,sqlstr))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}
	m_recordset.Close();
	
	sqlstr.Format("select * from product right join rep  on product.ic =  rep.ic ");
	if(!m_record.Open(AFX_DB_USE_DEFAULT_TYPE,sqlstr))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}
	
	int i=0;
	CString str;
	while(!m_record.IsEOF())
	{
			str.Format("%ld",i);
			m_ctrList.InsertItem(i,str);
			str.Format("%ld",m_record.m_ic);
			m_ctrList.SetItemText(i,1,str);
			str.Format("%ld",m_record.m_oc);
			m_ctrList.SetItemText(i,2,str);
			str.Format("%ld",m_record.m_pp);
			m_ctrList.SetItemText(i,3,str);
			m_ctrList.SetItemText(i,4,m_record.m_pm);
			m_ctrList.SetItemText(i,5,m_record.m_ty);
			str.Format("%ld",m_record.m_ct);
			m_ctrList.SetItemText(i,6,str);
			str.Format("%ld",m_record.m_ct0);
			m_ctrList.SetItemText(i,7,str);
			m_ctrList.SetItemText(i,8,m_record.m_mg);
			i++;
			m_record.MoveNext();
	}
	m_record.Close();		
	m_ctrList.SetRedraw(TRUE);
}


void KuGuan::OnCX2()
{
	dkucx.DoModal();
	sqlstr.Format(" UPDATE rep SET ct=24    WHERE ic = 12  " );
	UpdateData();
	m_ctrList.DeleteAllItems();
	m_ctrList.SetRedraw(FALSE);	

		if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,sqlstr))
		{
			MessageBox("打开数据库失败!","数据库错误",MB_OK);
			return ;
		}
		m_recordset.Close();	
		sqlstr.Format("select * from product right join rep  on product.ic =  rep.ic ");
		if(!m_record.Open(AFX_DB_USE_DEFAULT_TYPE,sqlstr))
		{
			MessageBox("打开数据库失败!","数据库错误",MB_OK);
			return ;
		}
	
		int i=0;
		CString str;
		while(!m_record.IsEOF())
		{
			str.Format("%ld",i);
			m_ctrList.InsertItem(i,str);
			str.Format("%ld",m_record.m_ic);
			m_ctrList.SetItemText(i,1,str);
			str.Format("%ld",m_record.m_oc);
			m_ctrList.SetItemText(i,2,str);
			str.Format("%ld",m_record.m_pp);
			m_ctrList.SetItemText(i,3,str);
			m_ctrList.SetItemText(i,4,m_record.m_pm);
			m_ctrList.SetItemText(i,5,m_record.m_ty);
			str.Format("%ld",m_record.m_ct);
			m_ctrList.SetItemText(i,6,str);
			str.Format("%ld",m_record.m_ct0);
			m_ctrList.SetItemText(i,7,str);
			m_ctrList.SetItemText(i,8,m_record.m_mg);
			i++;
			m_record.MoveNext();
		}
	m_record.Close();	
	m_ctrList.SetRedraw(TRUE);
}


void KuGuan::OnCX3()
{
	dkucx.DoModal();
	sqlstr.Format(" UPDATE rep SET ct=24    WHERE ic = 12  ");
	UpdateData();
	m_ctrList.DeleteAllItems();
	m_ctrList.SetRedraw(FALSE);	

		if(!m_recordset.Open(AFX_DB_USE_DEFAULT_TYPE,sqlstr))
		{
			MessageBox("打开数据库失败!","数据库错误",MB_OK);
			return ;
		}
		m_recordset.Close();
	
		sqlstr.Format("select * from product right join rep  on product.ic =  rep.ic ");
		if(!m_record.Open(AFX_DB_USE_DEFAULT_TYPE,sqlstr))
		{
			MessageBox("打开数据库失败!","数据库错误",MB_OK);
			return ;
		}
	
		int i=0;
		CString str;
		while(!m_record.IsEOF())
		{
			str.Format("%ld",i);
			m_ctrList.InsertItem(i,str);
			str.Format("%ld",m_record.m_ic);
			m_ctrList.SetItemText(i,1,str);
			str.Format("%ld",m_record.m_oc);
			m_ctrList.SetItemText(i,2,str);
			str.Format("%ld",m_record.m_pp);
			m_ctrList.SetItemText(i,3,str);
			m_ctrList.SetItemText(i,4,m_record.m_pm);
			m_ctrList.SetItemText(i,5,m_record.m_ty);
			str.Format("%ld",m_record.m_ct);
			m_ctrList.SetItemText(i,6,str);
			str.Format("%ld",m_record.m_ct0);
			m_ctrList.SetItemText(i,7,str);
			m_ctrList.SetItemText(i,8,m_record.m_mg);
			i++;
			m_record.MoveNext();
		}
		m_record.Close();	
	m_ctrList.SetRedraw(TRUE);
}
