// PopDialog.cpp : implementation file
//



#include "stdafx.h"
#include "PopDlg.h"
#include "Posts.h"
#include "PostsDlg.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPopDlg dialog


CPopDlg::CPopDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPopDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPopDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPopDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPopDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPopDlg, CDialog)
	//{{AFX_MSG_MAP(CPopDlg)
	ON_WM_SHOWWINDOW()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPopDlg message handlers

void CPopDlg::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
	
	// TODO: Add your message handler code here
	::AnimateWindow(GetSafeHwnd(),800,AW_SLIDE|AW_VER_NEGATIVE);
}
