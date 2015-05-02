// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__ED26145F_555D_4BA4_B7D1_71B31FA6F0C6__INCLUDED_)
#define AFX_STDAFX_H__ED26145F_555D_4BA4_B7D1_71B31FA6F0C6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxsock.h>		// MFC socket extensions

#ifndef _AFX_NO_DB_SUPPORT
#include <afxdb.h>	// MFC ODBC database classes
#endif // _AFX_NO_DB_SUPPORT

//#import "c:\program files\common files\system\ado\msado15.dll"  no_namespace  rename ("EOF", "adoEOF") 
#include <odbcinst.h>//ODBC数据库API头文件
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__ED26145F_555D_4BA4_B7D1_71B31FA6F0C6__INCLUDED_)
