// DianZhang.cpp : implementation file
//

#include "stdafx.h"
#include "bysj.h"
#include "DianZhang.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDianZhang dialog


CDianZhang::CDianZhang(CWnd* pParent /*=NULL*/)
	: CDialog(CDianZhang::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDianZhang)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	mode=0;
}


void CDianZhang::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDianZhang)
	DDX_Control(pDX, IDC_LIST_DZ, m_ctrList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDianZhang, CDialog)
	//{{AFX_MSG_MAP(CDianZhang)
	ON_BN_CLICKED(IDOK2, OnOk2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDianZhang message handlers

BOOL CDianZhang::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDianZhang::OnOk2() //刷新
{
	// TODO: Add your control notification handler code here
CString sqlstr;
int i=0;
CString str;

	UpdateData();	
	m_ctrList.DeleteAllItems();
	m_ctrList.SetRedraw(FALSE);	
while ( m_ctrList.DeleteColumn (0));
switch(mode){
case 0:
	m_ctrList.InsertColumn(0,"序号");
	m_ctrList.InsertColumn(1,"内码");
	m_ctrList.InsertColumn(2,"原厂条形码");
	m_ctrList.InsertColumn(3,"品牌");
	m_ctrList.InsertColumn(4,"品名");
	m_ctrList.InsertColumn(5,"款号");
	m_ctrList.InsertColumn(6,"类别");
	m_ctrList.InsertColumn(7,"经销商");
	m_ctrList.InsertColumn(8,"电话");
	m_ctrList.InsertColumn(9,"手机");
	m_ctrList.InsertColumn(10,"制造商");
	m_ctrList.InsertColumn(11,"电话");
	m_ctrList.InsertColumn(12,"手机");

	m_ctrList.SetColumnWidth(0,60);
	m_ctrList.SetColumnWidth(1,80);
	m_ctrList.SetColumnWidth(2,80);
	m_ctrList.SetColumnWidth(3,80);
	m_ctrList.SetColumnWidth(4,80);
	m_ctrList.SetColumnWidth(5,80);
	m_ctrList.SetColumnWidth(6,80);
	m_ctrList.SetColumnWidth(7,100);
	m_ctrList.SetColumnWidth(8,100);
	m_ctrList.SetColumnWidth(9,100);
	m_ctrList.SetColumnWidth(10,100);
	m_ctrList.SetColumnWidth(11,100);
	m_ctrList.SetColumnWidth(12,100);
	m_ctrList.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);


	
	sqlstr.Format("select * from product ");
	if(!set0.Open(AFX_DB_USE_DEFAULT_TYPE,sqlstr))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}
	i=0;
	while(!set0.IsEOF())
	{
			str.Format("%ld",i);
			m_ctrList.InsertItem(i,str);
			str.Format("%ld",set0.m_ic);
			m_ctrList.SetItemText(i,1,str);
			str.Format("%ld",set0.m_oc);
			m_ctrList.SetItemText(i,2,str);
			str.Format("%ld",set0.m_pp);
			m_ctrList.SetItemText(i,3,str);
			m_ctrList.SetItemText(i,4,set0.m_pm);
			m_ctrList.SetItemText(i,5,set0.m_kh);
			m_ctrList.SetItemText(i,6,set0.m_ty);
			m_ctrList.SetItemText(i,7,set0.m_jx);
			m_ctrList.SetItemText(i,8,set0.m_pn0);
			m_ctrList.SetItemText(i,9,set0.m_p0);
			m_ctrList.SetItemText(i,10,set0.m_prod);
			m_ctrList.SetItemText(i,11,set0.m_pn1);
			m_ctrList.SetItemText(i,12,set0.m_ph1);
			i++;
			set0.MoveNext();
	}
	set0.Close();
	
	break;
case 1:	
	m_ctrList.InsertColumn(0,"序号");
	m_ctrList.InsertColumn(1,"内码");
	m_ctrList.InsertColumn(2,"进价");
	m_ctrList.InsertColumn(3,"标价");
	m_ctrList.InsertColumn(4,"利润");

	m_ctrList.SetColumnWidth(0,60);
	m_ctrList.SetColumnWidth(1,80);
	m_ctrList.SetColumnWidth(2,80);
	m_ctrList.SetColumnWidth(3,80);
	m_ctrList.SetColumnWidth(4,80);

	m_ctrList.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);


	sqlstr.Format("select * from price ");
	if(!set3.Open(AFX_DB_USE_DEFAULT_TYPE,sqlstr))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}
	i=0;
	while(!set3.IsEOF())
	{
			str.Format("%ld",i);
			m_ctrList.InsertItem(i,str);
			str.Format("%ld",set3.m_ic);
			m_ctrList.SetItemText(i,1,str);
			str.Format("%ld",set3.m_jp);
			m_ctrList.SetItemText(i,2,str);
			str.Format("%ld",set3.m_bp);
			m_ctrList.SetItemText(i,3,str);
			str.Format("%ld",set3.m_lr);
			m_ctrList.SetItemText(i,3,str);
			i++;
			set3.MoveNext();
	}
	set3.Close();
	
	break;
case 2:	
	m_ctrList.InsertColumn(0,"序号");
	m_ctrList.InsertColumn(1,"内码");
	m_ctrList.InsertColumn(2,"库存数量");
	m_ctrList.InsertColumn(3,"已销售数量");
	m_ctrList.InsertColumn(4,"经办人");

	m_ctrList.SetColumnWidth(0,60);
	m_ctrList.SetColumnWidth(1,80);
	m_ctrList.SetColumnWidth(2,80);
	m_ctrList.SetColumnWidth(3,80);
	m_ctrList.SetColumnWidth(4,80);

	m_ctrList.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	
	sqlstr.Format("select * from product rep   ");
	if(!set1.Open(AFX_DB_USE_DEFAULT_TYPE,sqlstr))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}
	i=0;
	while(!set1.IsEOF())
	{
			str.Format("%ld",i);
			m_ctrList.InsertItem(i,str);
			str.Format("%ld",set1.m_ic);
			m_ctrList.SetItemText(i,1,str);
			str.Format("%ld",set1.m_ct);
			m_ctrList.SetItemText(i,2,str);
			str.Format("%ld",set1.m_ct0);
			m_ctrList.SetItemText(i,3,str);
			m_ctrList.SetItemText(i,4,set1.m_mg);
			i++;
			set1.MoveNext();
	}
	set1.Close();
	
	break;
case 3:	
	m_ctrList.InsertColumn(0,"序号");
	m_ctrList.InsertColumn(1,"员工编码");
	m_ctrList.InsertColumn(2,"姓名");
	m_ctrList.InsertColumn(3,"性别");
	m_ctrList.InsertColumn(4,"年龄");
	m_ctrList.InsertColumn(5,"职位工资");
	m_ctrList.InsertColumn(6,"工龄");
	m_ctrList.InsertColumn(7,"联系方式1");
	m_ctrList.InsertColumn(8,"联系方式2");
	m_ctrList.InsertColumn(9,"联系人");
	m_ctrList.InsertColumn(10,"联系人联系方式");
	
	m_ctrList.SetColumnWidth(0,60);
	m_ctrList.SetColumnWidth(1,80);
	m_ctrList.SetColumnWidth(2,80);
	m_ctrList.SetColumnWidth(3,80);
	m_ctrList.SetColumnWidth(4,80);
	m_ctrList.SetColumnWidth(5,80);
	m_ctrList.SetColumnWidth(6,80);
	m_ctrList.SetColumnWidth(7,100);
	m_ctrList.SetColumnWidth(8,100);	
	m_ctrList.SetColumnWidth(9,100);
	m_ctrList.SetColumnWidth(10,100);	
	m_ctrList.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);


	
	sqlstr.Format("select * from emtpys");
	if(!set2.Open(AFX_DB_USE_DEFAULT_TYPE,sqlstr))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}
	i=0;
	while(!set2.IsEOF())
	{
			str.Format("%ld",i);
			m_ctrList.InsertItem(i,str);
			str.Format("%ld",set2.m_eid);
			m_ctrList.SetItemText(i,1,str);
			m_ctrList.SetItemText(i,2,set2.m_ename);
			m_ctrList.SetItemText(i,3,set2.m_esex);
			m_ctrList.SetItemText(i,4,set2.m_eage);
			str.Format("%ld",set2.m_emon);
			m_ctrList.SetItemText(i,5,str);
			m_ctrList.SetItemText(i,6,set2.m_eages);
			m_ctrList.SetItemText(i,7,set2.m_ecot1);
			m_ctrList.SetItemText(i,8,set2.m_ecot2);
			m_ctrList.SetItemText(i,9,set2.m_ecp);
			m_ctrList.SetItemText(i,10,set2.m_ecpn);;
			i++;
			set2.MoveNext();
	}
	set2.Close();	
	break;
	case 4:	
	m_ctrList.InsertColumn(0,"序号");
	m_ctrList.InsertColumn(1,"交易流水号");
	m_ctrList.InsertColumn(2,"收银员");
	m_ctrList.InsertColumn(3,"销售员工");
	m_ctrList.InsertColumn(4,"交易时间");
	m_ctrList.InsertColumn(5,"交易数量");
	m_ctrList.InsertColumn(6,"交易金额");
	m_ctrList.InsertColumn(7,"利润");
	m_ctrList.InsertColumn(8,"商品1");
	m_ctrList.InsertColumn(9,"商品2");
	m_ctrList.InsertColumn(10,"商品3");
	m_ctrList.InsertColumn(11,"商品4");
	m_ctrList.InsertColumn(12,"商品5");
	m_ctrList.InsertColumn(13,"商品6");
	m_ctrList.InsertColumn(14,"商品7");
	m_ctrList.InsertColumn(15,"商品8");
	m_ctrList.InsertColumn(16,"商品9");
	m_ctrList.InsertColumn(17,"商品10");



	m_ctrList.SetColumnWidth(0,60);
	m_ctrList.SetColumnWidth(1,80);
	m_ctrList.SetColumnWidth(2,80);
	m_ctrList.SetColumnWidth(3,80);
	m_ctrList.SetColumnWidth(4,80);
	m_ctrList.SetColumnWidth(5,80);
	m_ctrList.SetColumnWidth(6,80);
	m_ctrList.SetColumnWidth(7,100);
	m_ctrList.SetColumnWidth(8,100);	
	m_ctrList.SetColumnWidth(9,100);
	m_ctrList.SetColumnWidth(10,100);	
	m_ctrList.SetColumnWidth(11,100);
	m_ctrList.SetColumnWidth(12,100);
	m_ctrList.SetColumnWidth(13,100);
	m_ctrList.SetColumnWidth(14,100);
	m_ctrList.SetColumnWidth(15,100);
	m_ctrList.SetColumnWidth(16,100);
	m_ctrList.SetColumnWidth(17,100);

	m_ctrList.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);


	
	sqlstr.Format("select * from xsjl");
	if(!set4.Open(AFX_DB_USE_DEFAULT_TYPE,sqlstr))
	{
		MessageBox("打开数据库失败!","数据库错误",MB_OK);
		return ;
	}
	i=0;
	while(!set4.IsEOF())
	{
			str.Format("%ld",i);
			m_ctrList.InsertItem(i,str);
			str.Format("%ld",set4.m_jylsh);
			m_ctrList.SetItemText(i,1,str);
			str.Format("%ld",set4.m_syy);
			m_ctrList.SetItemText(i,2,str);
			str.Format("%ld",set4.m_xsyg);
			m_ctrList.SetItemText(i,3,str);
		str.Format("%d-%d-%d",set4.m_jysj.GetYear(),set4.m_jysj.GetMonth(),set4.m_jysj.GetDay());
		m_ctrList.SetItemText(i,4,str);
	//		m_ctrList.SetItemText(i,4,set4.m_jysj);
			str.Format("%ld",set4.m_jysl);
			m_ctrList.SetItemText(i,5,str);
			str.Format("%ld",set4.m_jyje);
			m_ctrList.SetItemText(i,6,str);
			str.Format("%ld",set4.m_lr);
			m_ctrList.SetItemText(i,7,str);			
			m_ctrList.SetItemText(i,8,set4.m_p1);		
			m_ctrList.SetItemText(i,9,set4.m_p2);			
			m_ctrList.SetItemText(i,10,set4.m_p3);
			m_ctrList.SetItemText(i,11,set4.m_p4);
			m_ctrList.SetItemText(i,12,set4.m_p5);			
			m_ctrList.SetItemText(i,13,set4.m_p6);			
			m_ctrList.SetItemText(i,14,set4.m_p7);
			m_ctrList.SetItemText(i,15,set4.m_p8);
			m_ctrList.SetItemText(i,16,set4.m_p9);
			m_ctrList.SetItemText(i,17,set4.m_p10);

			i++;
			set4.MoveNext();
	}
	set4.Close();	
	break;
default:
	break;
	}

		m_ctrList.SetRedraw(TRUE);
	UpdateData(true);
}

BOOL CDianZhang::OnCommand(WPARAM wParam, LPARAM lParam) 
{
	// TODO: Add your specialized code here and/or call the base class
	int menuID = LOWORD(wParam); 
	switch(menuID) { 
		case ID_yginfo: 
			mode=3;

			break;
		case ID_hwidfo:
			mode=2;

			break; 
		case ID_kcinfo:
			mode=0;

			break; 
		case ID_jginfo:
			mode=1;

			break; 
		case ID_jyinfo:
			mode=4;

			break; 
		default: break; 
	}
	OnOk2();
	return CDialog::OnCommand(wParam, lParam);
}
