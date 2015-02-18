// PostsDlg.h : header file
//

#if !defined(AFX_POSTSDLG_H__F6A7F3DF_73D6_49F8_BB6F_1BE318DF9179__INCLUDED_)
#define AFX_POSTSDLG_H__F6A7F3DF_73D6_49F8_BB6F_1BE318DF9179__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SetDlg.h"
/////////////////////////////////////////////////////////////////////////////
// CPostsDlg dialog

class CPostsDlg : public CDialog
{
// Construction
public:
	void HotKeySet();
	BOOL SetTransparent(HWND hWnd, int LayerN);
	void ReadButtonName();	
	void ButtonSet();
	void ReadToClip(CString);
	void OnFileWrite(char* szFileName);

	CPostsDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPostsDlg)
	enum { IDD = IDD_POSTS_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPostsDlg)
	public:
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	UINT curHotID;
	UINT curHotKeyID;
	HOTKEY	CurHotKey[20]; //热键设置
	// Generated message map functions
	//{{AFX_MSG(CPostsDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnAd1();
	afx_msg void OnBtnAd2();
	afx_msg void OnBtnAd3();
	afx_msg void OnBtnAd4();
	afx_msg void OnBtnAd5();
	afx_msg void OnBtnAd6();
	afx_msg void OnBtnFileOpen();
	afx_msg void OnBtnFileWrite();
	afx_msg void OnClose();
	afx_msg void OnDestroy();
	afx_msg void OnDoubleclickedBtnAd1();
	afx_msg void OnDoubleclickedBtnAd2();
	afx_msg void OnDoubleclickedBtnAd3();
	afx_msg void OnDoubleclickedBtnAd4();
	afx_msg void OnDoubleclickedBtnAd5();
	afx_msg void OnDoubleclickedBtnAd6();
	afx_msg void OnBtnFolder();
	//}}AFX_MSG
	afx_msg LONG OnHotKey(WPARAM wParam,LPARAM lParam);  //手工添加
	afx_msg LONG OnNotifyIcon(WPARAM wParam, LPARAM lParam);
	afx_msg LONG OnDlgShow(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POSTSDLG_H__F6A7F3DF_73D6_49F8_BB6F_1BE318DF9179__INCLUDED_)
