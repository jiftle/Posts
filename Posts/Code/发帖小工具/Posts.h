// Posts.h : main header file for the POSTS application
//

#if !defined(AFX_POSTS_H__50A0BFB9_187D_4CDE_B1D5_961DEAC3B1EF__INCLUDED_)
#define AFX_POSTS_H__50A0BFB9_187D_4CDE_B1D5_961DEAC3B1EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
/////////////////////////////////////////////////////////////////////////////
// CPostsApp:
// See Posts.cpp for the implementation of this class
//

typedef struct{
	UINT nCTRL_ID;
	UINT fsModifiers;
	UINT vk;
	UINT hotkeyID;
	}HOTKEY;
class CPostsApp : public CWinApp
{
public:
	CPostsApp();

	CString strAd1;
	CString strAd2;
	CString strAd3;
	CString strAd4;
	CString strAd5;
	CString strAd6;
	HOTKEY	CurHotKey; //»»º¸…Ë÷√
	

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPostsApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPostsApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POSTS_H__50A0BFB9_187D_4CDE_B1D5_961DEAC3B1EF__INCLUDED_)
