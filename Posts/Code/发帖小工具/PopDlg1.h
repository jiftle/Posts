#if !defined(AFX_POPDLG1_H__9EAA385C_04E1_4610_AAB8_448D9CABC976__INCLUDED_)
#define AFX_POPDLG1_H__9EAA385C_04E1_4610_AAB8_448D9CABC976__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PopDlg1.h : header file
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
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POPDLG1_H__9EAA385C_04E1_4610_AAB8_448D9CABC976__INCLUDED_)
