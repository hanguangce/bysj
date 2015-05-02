#if !defined(AFX_KUGUAN_H__857B4633_9EBD_48DB_83E8_2ECCDDE81A29__INCLUDED_)
#define AFX_KUGUAN_H__857B4633_9EBD_48DB_83E8_2ECCDDE81A29__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// KuGuan.h : header file
//
/////////////////////////////////////////////////////////////////////////////
// KuGuan dialog
#include "databaseset.h"
//#include "productset.h"
class KuGuan : public CDialog
{
// Construction
public:
	KuGuan(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(KuGuan)
	enum { IDD = IDD_KuGuan };
	CListCtrl	m_ctrList;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(KuGuan)
	public:
	virtual int DoModal();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(KuGuan)
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	databaseset m_recordset;


};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KUGUAN_H__857B4633_9EBD_48DB_83E8_2ECCDDE81A29__INCLUDED_)
