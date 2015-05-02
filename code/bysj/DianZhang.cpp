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
}


void CDianZhang::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDianZhang)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDianZhang, CDialog)
	//{{AFX_MSG_MAP(CDianZhang)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDianZhang message handlers
