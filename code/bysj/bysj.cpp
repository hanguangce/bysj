// bysj.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "bysj.h"
#include "bysjDlg.h"
#include "DianZhang.h"
#include "KuGuan.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBysjApp

BEGIN_MESSAGE_MAP(CBysjApp, CWinApp)
	//{{AFX_MSG_MAP(CBysjApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBysjApp construction

CBysjApp::CBysjApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CBysjApp object

CBysjApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CBysjApp initialization

BOOL CBysjApp::InitInstance()
{
	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.



#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

/////////////////////////////////////////////////////////
AfxOleInit();


	SQLConfigDataSource(NULL,ODBC_ADD_DSN,
		"Microsoft Access Driver (*.mdb)",
		"DSN=bysj_db\0"
		"DataBase=Database\0"
		"Description=Hotel\0"
	    "FileType=Access\0"
        "DBQ=c:\\Database.mdb\0"
		               );


	CBysjDlg dlg;
//	m_pMainWnd = &dlg;           //????

Cdb mydb;

//CString str;
//str.Format(_T("@@ %d"), mydb.vCount.intVal);
//AfxMessageBox(str);

	int nResponse = dlg.DoModal();	
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK



	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	return FALSE;
}
