#if !defined(AFX_POPDIALOG_H__A78DB692_10BD_45CC_A9D3_77B1324110C9__INCLUDED_)
#define AFX_POPDIALOG_H__A78DB692_10BD_45CC_A9D3_77B1324110C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PopDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPopDlg dialog

class CPopDlg : public CDialog
{
// Construction
public:
	CPopDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPopDlg)
	enum { IDD = IDD_POPDIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPopDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPopDlg)
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POPDIALOG_H__A78DB692_10BD_45CC_A9D3_77B1324110C9__INCLUDED_)
