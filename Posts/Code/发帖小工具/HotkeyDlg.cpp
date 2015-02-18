// HotkeyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Posts.h"
#include "HotkeyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHotkeyDlg dialog


CHotkeyDlg::CHotkeyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHotkeyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHotkeyDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CHotkeyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHotkeyDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHotkeyDlg, CDialog)
	//{{AFX_MSG_MAP(CHotkeyDlg)
	ON_WM_SHOWWINDOW()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHotkeyDlg message handlers

void CHotkeyDlg::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	
	CDialog::OnShowWindow(bShow, nStatus);
	// TODO: Add your message handler code here
	
	//�ؼ�����
	CString strText;
	for(int j= IDC_BTN_AD1;j<=IDC_BTN_AD6;j++){
		GetParent()->GetDlgItemText(j,strText);
		((CComboBox*)GetDlgItem(IDC_CBO_BTNNAME))->AddString(strText);
	}
	((CComboBox*)GetDlgItem(IDC_CBO_BTNNAME))->SetCurSel(0);
	
	//--------------------- ��Ͽ��ʼ�� -------------------------
	CString strTemp;
    int iCount=((CComboBox*)GetDlgItem(IDC_CBO_VKCODE))->GetCount();//ȡ��Ŀǰ�Ѿ��е�����
    if(iCount<1)//��ֹ�ظ�������
	{
		((CComboBox*)GetDlgItem(IDC_CBO_VKCODE))->ResetContent();
        
		
		for(int i='A';i<='Z';i++)
		{
			strTemp.Format("%c",i);
			((CComboBox*)GetDlgItem(IDC_CBO_VKCODE))->AddString(strTemp);
		}
		
		for(int i=0;i<=9;i++)
		{
			strTemp.Format("%d",i);
			((CComboBox*)GetDlgItem(IDC_CBO_VKCODE))->AddString(strTemp);
		}
    }
	
    ((CComboBox*)GetDlgItem(IDC_CBO_VKCODE))->SetCurSel(0);
}

void CHotkeyDlg::OnOK() 
{
	// TODO: Add extra validation here

	//��ÿؼ�ID
	CString strText,strTextTmp;
	GetDlgItemText(IDC_CBO_BTNNAME,strText);
	
	CPostsApp *app = (CPostsApp *)AfxGetApp(); //����ָ��Ӧ�ó������ָ��

	for(int j= IDC_BTN_AD1;j<=IDC_BTN_AD6;j++){
		GetParent()->GetDlgItemText(j,strTextTmp);
		if (strTextTmp==strText)
		{
			app->CurHotKey.nCTRL_ID=j;
			break;
		}
	}

	//��ø�����״̬
	for (UINT nID=IDC_CHECK_CTRL;nID<=IDC_CHECK_SHIFT;nID++)
	{
// 		����   
// 			((CButton*)GetDlgItem(IDC_CHECK1))->SetCheck(TRUE);   
		 
			DWORD   dwState;
			dwState= ((CButton*)GetDlgItem(nID))->GetCheck();   
			if (dwState==1)
			{
				switch (nID)
				{
				case IDC_CHECK_ALT:
					app->CurHotKey.fsModifiers=MOD_ALT;
					break;
				case IDC_CHECK_CTRL:
					app->CurHotKey.fsModifiers=MOD_CONTROL;
					break;
				case IDC_CHECK_SHIFT:
					app->CurHotKey.fsModifiers=MOD_SHIFT;
					break;
				}				
			}
	}
	
//���������
	char cVK[2]="";
	GetDlgItemText(IDC_CBO_VKCODE,cVK,2);
	app->CurHotKey.vk=cVK[0];

	CDialog::OnOK();
}
