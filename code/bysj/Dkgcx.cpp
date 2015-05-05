// Dkgcx.cpp : implementation file
//

#include "stdafx.h"
#include "bysj.h"
#include "Dkgcx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Dkgcx dialog


Dkgcx::Dkgcx(CWnd* pParent /*=NULL*/)
	: CDialog(Dkgcx::IDD, pParent)
{
	//{{AFX_DATA_INIT(Dkgcx)
	m_edit0 = 0;
	m_edit1 = 0;
	m_edit2 = 0;
	m_edit3 = 0;
	//}}AFX_DATA_INIT
	button=0;
}


void Dkgcx::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Dkgcx)
	DDX_Text(pDX, IDC_KGCX_E0, m_edit0);
	DDV_MinMaxLong(pDX, m_edit0, 0, 99999);
	DDX_Text(pDX, IDC_KGCX_E1, m_edit1);
	DDV_MinMaxLong(pDX, m_edit1, 0, 99999);
	DDX_Text(pDX, IDC_KGCX_E2, m_edit2);
	DDV_MinMaxLong(pDX, m_edit2, 0, 99999);
	DDX_Text(pDX, IDC_KGCX_E3, m_edit3);
	DDV_MinMaxLong(pDX, m_edit3, 0, 99999);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Dkgcx, CDialog)
	//{{AFX_MSG_MAP(Dkgcx)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Dkgcx message handlers

void Dkgcx::OnButton1() 
{
	// TODO: Add your control notification handler code here
	button=1;
	OnOK();
}

void Dkgcx::OnButton2() 
{
	// TODO: Add your control notification handler code here
	button=2;
	OnOK();
}

void Dkgcx::OnButton3() 
{
	// TODO: Add your control notification handler code here
	button=3;
	OnOK();
}

void Dkgcx::OnButton4() 
{
	// TODO: Add your control notification handler code here
	button=4;
	OnOK();
}
