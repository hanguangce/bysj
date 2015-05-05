#if !defined(AFX_KUGUAN_H__857B4633_9EBD_48DB_83E8_2ECCDDE81A29__INCLUDED_)
#define AFX_KUGUAN_H__857B4633_9EBD_48DB_83E8_2ECCDDE81A29__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// KuGuan.h : header file
//
/////////////////////////////////////////////////////////////////////////////
// KuGuan dialog
#include "pro_rep_set.h"
#include "productset.h"
#include "repset.h"
#include "Dkgcx.h"
#include "Dgkrh.h"
#include "Dgktj.h"
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
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(KuGuan)
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnUpdatehwidfo(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	pro_rep_set  m_record;
	productset m_recordset;
	repset		m_recordset0;	
	Dkgcx		dkucx;
	CString		sqlstr;
	Dgkrh		dgkrh;
	Dgktj		dgktj;
	void OnCX0();
	void OnCX1();
	void OnCX2();
	void OnCX3();

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KUGUAN_H__857B4633_9EBD_48DB_83E8_2ECCDDE81A29__INCLUDED_)
