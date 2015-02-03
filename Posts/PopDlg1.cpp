// PopDlg1.cpp : implementation file
//

#include "stdafx.h"
#include "Posts.h"
#include "PopDlg1.h"

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
	ON_WM_TIMER()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPopDlg message handlers

void CPopDlg::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
	
	// TODO: Add your message handler code here
	 //获得桌面大小
	 CRect rectWorkArea;
	 SystemParametersInfo(SPI_GETWORKAREA,0,&rectWorkArea,SPIF_SENDCHANGE);   
 
	 //获得对话框大小
	 CRect rectDlg;
	 GetWindowRect(&rectDlg);
	 int nW = rectDlg.Width();
	 int nH = rectDlg.Height();
 
	 //将窗口设置到右下脚
	 ::SetWindowPos(this->m_hWnd,HWND_BOTTOM,
	  rectWorkArea.left,rectWorkArea.bottom-nH,
	  nW,nH,
	  SWP_NOZORDER);

	 ::AnimateWindow(GetSafeHwnd(),800,AW_SLIDE|AW_VER_NEGATIVE);

	 SetTimer(1,1000,NULL);
}

void CPopDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	::SendMessage(this->m_hWnd,WM_CLOSE,NULL,NULL);
	KillTimer(1);
	CDialog::OnTimer(nIDEvent);
}

BOOL CPopDlg::OnEraseBkgnd(CDC* pDC) 
{

	return CDialog::OnEraseBkgnd(pDC);

	// load IDB_BITMAP1 from our resources
	CBitmap bmp;
	if (bmp.LoadBitmap(IDB_BITMAP1))
	{
		// Get the size of the bitmap
		BITMAP bmpInfo;
		bmp.GetBitmap(&bmpInfo);
		
		// Create an in-memory DC compatible with the
		// display DC we're using to paint
		CDC dcMemory;
		dcMemory.CreateCompatibleDC(pDC);
		
		// Select the bitmap into the in-memory DC
		CBitmap* pOldBitmap = dcMemory.SelectObject(&bmp);
		
		// Find a centerpoint for the bitmap in the client area
		CRect rect;
		GetClientRect(&rect);
		int nX = rect.left + (rect.Width() - bmpInfo.bmWidth) / 2;
		int nY = rect.top + (rect.Height() - bmpInfo.bmHeight) / 2;
		
		// Copy the bits from the in-memory DC into the on-
		// screen DC to actually do the painting. Use the centerpoint
		// we computed for the target offset.
		StretchBlt(pDC->GetSafeHdc(), 0,0,rect.Width(), rect.Height(), dcMemory.GetSafeHdc(),0,0,bmpInfo.bmWidth, bmpInfo.bmHeight, SRCCOPY);
		
		dcMemory.SelectObject(pOldBitmap);
	}
	else
		TRACE0("ERROR: Where's IDB_BITMAP1?\n");

	
	

	return TRUE;
	
	//return CDialog::OnEraseBkgnd(pDC);
}
