// bysjDlg.h : header file
//

#if !defined(AFX_BYSJDLG_H__2D36F7CF_4562_49B2_8327_4033F4034482__INCLUDED_)
#define AFX_BYSJDLG_H__2D36F7CF_4562_49B2_8327_4033F4034482__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBysjDlg dialog

class CBysjDlg : public CDialog
{
// Construction
public:
	CBysjDlg(CWnd* pParent = NULL);	// standard constructor

	int nIndex ;	
	_ConnectionPtr m_pConnection;
	_CommandPtr m_pCommand;
	_RecordsetPtr m_pRecordset;
// Dialog Data
	//{{AFX_DATA(CBysjDlg)
	enum { IDD = IDD_BYSJ_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBysjDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL




// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBysjDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void Onbysj1();
	afx_msg void OnSelchangeCombo1();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BYSJDLG_H__2D36F7CF_4562_49B2_8327_4033F4034482__INCLUDED_)
