// SetDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Posts.h"
#include "SetDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetDlg dialog


CSetDlg::CSetDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSetDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT



}


void CSetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetDlg, CDialog)
	//{{AFX_MSG_MAP(CSetDlg)
	ON_BN_CLICKED(IDC_BTN_OK, OnBtnOk)
	ON_BN_CLICKED(IDC_BTN_CLOSE, OnBtnClose)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetDlg message handlers

void CSetDlg::OnBtnOk() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	CPostsApp *app=(CPostsApp*)AfxGetApp();
	app->strAd2=_T("广告1");
	app->strAd2=_T("广告2");
	app->strAd3=_T("广告3");
	app->strAd4=_T("广告4");
	app->strAd5=_T("广告5");
	app->strAd6=_T("广告6");

	CString strTmpAd;
	GetDlgItem(IDC_AD1)->GetWindowText(strTmpAd);
	if (strTmpAd.IsEmpty())
	{
	app->strAd1=_T("广告1");
	}
	else
	{
	app->strAd1=strTmpAd;
	}
	
	GetDlgItem(IDC_AD2)->GetWindowText(strTmpAd);
	if (strTmpAd.IsEmpty())
	{
	app->strAd2=_T("广告2");
	}
	else
	{
	app->strAd2=strTmpAd;
	}

	GetDlgItem(IDC_AD3)->GetWindowText(strTmpAd);
	if (strTmpAd.IsEmpty())
		app->strAd3=_T("广告3");
	else
		app->strAd3=strTmpAd;
	
		GetDlgItem(IDC_AD4)->GetWindowText(strTmpAd);
	if (strTmpAd.IsEmpty())
		app->strAd4=_T("广告4");
	else
		app->strAd4=strTmpAd;
	
	GetDlgItem(IDC_AD5)->GetWindowText(strTmpAd);
	if (strTmpAd.IsEmpty())
		app->strAd5=_T("广告5");
	else
		app->strAd5=strTmpAd;

		GetDlgItem(IDC_AD6)->GetWindowText(strTmpAd);
	if (strTmpAd.IsEmpty())
		app->strAd6=_T("广告6");
	else
		app->strAd6=strTmpAd;
EndDialog(1);
}

void CSetDlg::OnBtnClose() 
{
	// TODO: Add your control notification handler code here
	EndDialog(0);
}
