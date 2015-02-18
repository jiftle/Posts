#if !defined(AFX_HOTKEYDLG_H__2FB3E904_BA69_4ECB_A9BC_53045682E8A8__INCLUDED_)
#define AFX_HOTKEYDLG_H__2FB3E904_BA69_4ECB_A9BC_53045682E8A8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HotkeyDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHotkeyDlg dialog

class CHotkeyDlg : public CDialog
{
// Construction
public:
	CHotkeyDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CHotkeyDlg)
	enum { IDD = IDD_DLG_HOTKEY };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHotkeyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CHotkeyDlg)
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HOTKEYDLG_H__2FB3E904_BA69_4ECB_A9BC_53045682E8A8__INCLUDED_)
