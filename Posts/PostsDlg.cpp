// PostsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Posts.h"
#include "PostsDlg.h"
#include "PopDlg.h"
#include "HotkeyDlg.h"

#include "getBrowserUrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define HotKeyID 5000
#define WM_USER_001	WM_USER+2

#define WM_NOTIFYICON    WM_USER+1 //���������ͼ��ʱ����Ϣ�ã�
NOTIFYICONDATA	m_Nid; //���̽ṹ��������ڽṹ��ֵ
BOOL bTray; //�Ƿ��Ѿ�����

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About


class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG


	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
		//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPostsDlg dialog

CPostsDlg::CPostsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPostsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPostsDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

}

void CPostsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPostsDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPostsDlg, CDialog)
	//{{AFX_MSG_MAP(CPostsDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_AD1, OnBtnAd1)
	ON_BN_CLICKED(IDC_BTN_AD2, OnBtnAd2)
	ON_BN_CLICKED(IDC_BTN_AD3, OnBtnAd3)
	ON_BN_CLICKED(IDC_BTN_AD4, OnBtnAd4)
	ON_BN_CLICKED(IDC_BTN_AD5, OnBtnAd5)
	ON_BN_CLICKED(IDC_BTN_AD6, OnBtnAd6)
	ON_BN_CLICKED(IDC_BTN_FILE_OPEN, OnBtnFileOpen)
	ON_BN_CLICKED(IDC_BTN_FILE_WRITE, OnBtnFileWrite)
	ON_WM_CLOSE()
	ON_WM_DESTROY()
	ON_BN_DOUBLECLICKED(IDC_BTN_AD1, OnDoubleclickedBtnAd1)
	ON_BN_DOUBLECLICKED(IDC_BTN_AD2, OnDoubleclickedBtnAd2)
	ON_BN_DOUBLECLICKED(IDC_BTN_AD3, OnDoubleclickedBtnAd3)
	ON_BN_DOUBLECLICKED(IDC_BTN_AD4, OnDoubleclickedBtnAd4)
	ON_BN_DOUBLECLICKED(IDC_BTN_AD5, OnDoubleclickedBtnAd5)
	ON_BN_DOUBLECLICKED(IDC_BTN_AD6, OnDoubleclickedBtnAd6)
	ON_BN_CLICKED(IDC_BTN_FOLDER, OnBtnFolder)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_HOTKEY,OnHotKey) //�ֶ�����
	ON_MESSAGE(WM_NOTIFYICON,OnNotifyIcon)//��Ϣ
	ON_MESSAGE(WM_USER_001,OnDlgShow)//��Ϣ
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPostsDlg message handlers
	NOTIFYICONDATA nid; 

BOOL CPostsDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING,IDM_HOTKEY_SET, _T("�ȼ�����"));
			pSysMenu->AppendMenu(MF_STRING, IDM_MENU_SET, _T("��ť��������"));
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	//��ǰ��
	SetWindowPos(&wndTopMost,0,0,0,0, SWP_NOMOVE|SWP_NOSIZE);
	
	ReadButtonName();
   
//������������ͼ��
	ModifyStyleEx(WS_EX_APPWINDOW,WS_EX_TOOLWINDOW,0);
	SetTransparent(this->GetSafeHwnd(),60);   // NΪ͸����(1-100)

 //�����ȼ�
	for(int i =0;i<20;i++)
	{
		CurHotKey[i].fsModifiers=0;
		CurHotKey[i].hotkeyID=0;
		CurHotKey[i].nCTRL_ID=0;
		CurHotKey[i].vk=0;
	}
	curHotID=0;

 ASSERT(NULL != GetSafeHwnd());
	//Register�ȼ�
	int nRet = RegisterHotKey(GetSafeHwnd(),HotKeyID+1,MOD_ALT,'A'); //�ȼ� ctrl + d
	if(!nRet)
		AfxMessageBox(_T("RegisterHotKey Alt+A  false"));
	nRet = RegisterHotKey(GetSafeHwnd(),HotKeyID+2,MOD_ALT,'S'); //�ȼ� ctrl + d
	if(!nRet)
		AfxMessageBox(_T("RegisterHotKey Alt+S false"));
	curHotKeyID=HotKeyID +2;

//======= ���� ===============
	::memset(&m_Nid,0,sizeof(m_Nid));
	m_Nid.cbSize=sizeof(NOTIFYICONDATA);
	m_Nid.hWnd=m_hWnd;
	m_Nid.uID=IDD_POSTS_DIALOG;          //ע����������ؼ�(����)��ID��
	m_Nid.uFlags=NIF_ICON|NIF_MESSAGE|NIF_TIP;
	m_Nid.uCallbackMessage=WM_NOTIFYICON;       //��Ϣ�궨��
	m_Nid.hIcon=(HICON)LoadImage(AfxGetInstanceHandle(),
		MAKEINTRESOURCE(IDR_MAINFRAME),IMAGE_ICON,16,16,NULL);

	CString str;
	str.LoadString(IDS_TIP);
	strcpy(m_Nid.szTip,str);               //���ŵ�����ͼ���ϵ���Ϣ��ʾ

	bTray =FALSE;

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPostsDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else if (nID==IDM_MENU_SET)
	{
		ButtonSet();
	}
	else if (nID==IDM_HOTKEY_SET)
	{
		HotKeySet();
	}
	else
		CDialog::OnSysCommand(nID, lParam);
	
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CPostsDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPostsDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


void CPostsDlg::ReadToClip(CString strFile)
{
	CFile file;
	if(!file.Open(strFile,CFile::modeRead))
	{
		CString strCaption;
		GetWindowText(strCaption);
		MessageBox(_T("Can't open the file."),strCaption,MB_OK|MB_ICONINFORMATION);
		return;
	}

	int iFileLenght=file.GetLength();
	char*	buf= new char[iFileLenght/sizeof(char)];
	memset(buf,0,iFileLenght/sizeof(char));
// 	file.Read(buf,iFileLenght/sizeof(TCHAR));
 	file.Read(buf,iFileLenght/sizeof(char));

	file.Close();
  HGLOBAL   hGlobal=GlobalAlloc(GHND|GMEM_SHARE,iFileLenght/sizeof(char)+1);     //����ָ�������ڴ�   
  char   *pGlobal=(TCHAR*)GlobalLock(hGlobal);     //��ס�ڴ沢�����ָ��   
  for(UINT   i=0;i<iFileLenght/sizeof(char);i++)   
		 pGlobal[i]=buf[i];     //����д���ڴ�   

  GlobalUnlock(hGlobal);     //�����ڴ��   
  ::OpenClipboard(NULL);     //�򿪼�����   
  EmptyClipboard();     //��ռ�����   
  SetClipboardData(CF_TEXT,hGlobal);     //��ID��������� CF_UNICODETEXT 
  //SetClipboardData(CF_TEXT,hGlobal);
  CloseClipboard();     //�رռ�����

  delete []buf;
}

void CPostsDlg::OnBtnAd1() 
{
	CString strCaption;	
	GetDlgItem(IDC_BTN_AD1)->GetWindowText(strCaption);
	strCaption += _T(".txt");
	ReadToClip(_T(".\\")+ strCaption);
//	ReadToClip(_T(".\\001.txt"));
}
void CPostsDlg::OnBtnAd2() 
{
	//	ReadToClip(_T(".\\002.txt"));
	CString strCaption;	
	GetDlgItem(IDC_BTN_AD2)->GetWindowText(strCaption);
	strCaption += _T(".txt");
	ReadToClip(_T(".\\")+ strCaption);
}

void CPostsDlg::OnBtnAd3() 
{
	// TODO: Add your control notification handler code here
//	ReadToClip(_T(".\\003.txt"));
	CString strCaption;	
	GetDlgItem(IDC_BTN_AD3)->GetWindowText(strCaption);
	strCaption += _T(".txt");
	ReadToClip(_T(".\\")+ strCaption);
}

void CPostsDlg::OnBtnAd4() 
{
	// TODO: Add your control notification handler code here
//	ReadToClip(_T(".\\004.txt"));
	CString strCaption;	
	GetDlgItem(IDC_BTN_AD4)->GetWindowText(strCaption);
	strCaption += _T(".txt");
	ReadToClip(_T(".\\")+ strCaption);
}

void CPostsDlg::OnBtnAd5() 
{
 	// TODO: Add your control notification handler code here
 	//ReadToClip(_T(".\\005.txt"));
	CString strCaption;	
	GetDlgItem(IDC_BTN_AD5)->GetWindowText(strCaption);
	strCaption += _T(".txt");
	ReadToClip(_T(".\\")+ strCaption);
}
 
 void CPostsDlg::OnBtnAd6() 
 {
 	// TODO: Add your control notification handler code here
 //	ReadToClip(_T(".\\006.txt"));
CString strCaption;	
	GetDlgItem(IDC_BTN_AD6)->GetWindowText(strCaption);
	strCaption += _T(".txt");
	ReadToClip(_T(".\\")+ strCaption);
 }



void CPostsDlg::ButtonSet()
{

	//GetDlgItem(IDC_AD1)->SetWindowText("0000");
	CSetDlg dlg;
	if(dlg.DoModal()==1)
	{
		CPostsApp* app=(CPostsApp*)AfxGetApp();
		GetDlgItem(IDC_BTN_AD1)->SetWindowText(app->strAd1);
		GetDlgItem(IDC_BTN_AD2)->SetWindowText(app->strAd2);
		GetDlgItem(IDC_BTN_AD3)->SetWindowText(app->strAd3);
		GetDlgItem(IDC_BTN_AD4)->SetWindowText(app->strAd4);
		GetDlgItem(IDC_BTN_AD5)->SetWindowText(app->strAd5);
		GetDlgItem(IDC_BTN_AD6)->SetWindowText(app->strAd6);
	}
}

void CPostsDlg::ReadButtonName()
{
	CPostsApp* app=(CPostsApp*)AfxGetApp();
	TCHAR szBuf[10]=_T("");

	GetPrivateProfileString(_T("Setting"),_T("AD1"),_T(""),szBuf,sizeof(szBuf)/sizeof(TCHAR),
		".\\Posts.ini");
	app->strAd1.Format("%s",szBuf);
	GetPrivateProfileString(_T("Setting"),_T("AD2"),_T(""),szBuf,sizeof(szBuf)/sizeof(TCHAR),
		".\\Posts.ini");
	app->strAd2.Format("%s",szBuf);
	GetPrivateProfileString(_T("Setting"),_T("AD3"),_T(""),szBuf,sizeof(szBuf)/sizeof(TCHAR),
		".\\Posts.ini");
	app->strAd3.Format("%s",szBuf);
		GetPrivateProfileString(_T("Setting"),_T("AD4"),_T(""),szBuf,sizeof(szBuf)/sizeof(TCHAR),
		".\\Posts.ini");
	app->strAd4.Format("%s",szBuf);
		GetPrivateProfileString(_T("Setting"),_T("AD5"),_T(""),szBuf,sizeof(szBuf)/sizeof(TCHAR),
		".\\Posts.ini");
	app->strAd5.Format("%s",szBuf);
		GetPrivateProfileString(_T("Setting"),_T("AD6"),_T(""),szBuf,sizeof(szBuf)/sizeof(TCHAR),
		".\\Posts.ini");
	app->strAd6.Format("%s",szBuf);

		GetDlgItem(IDC_BTN_AD1)->SetWindowText(app->strAd1);
		GetDlgItem(IDC_BTN_AD2)->SetWindowText(app->strAd2);
		GetDlgItem(IDC_BTN_AD3)->SetWindowText(app->strAd3);
		GetDlgItem(IDC_BTN_AD4)->SetWindowText(app->strAd4);
		GetDlgItem(IDC_BTN_AD5)->SetWindowText(app->strAd5);
		GetDlgItem(IDC_BTN_AD6)->SetWindowText(app->strAd6);
}

BOOL CPostsDlg::SetTransparent(HWND hWnd, int LayerN) 
{ 
    HMODULE hModule = GetModuleHandle("User32.DLL"); 
    if(hModule==NULL) 
    { 
        return FALSE; 
    } 

    if(LayerN<0) LayerN = 0; 
    if(LayerN>100) LayerN =100; 

    typedef BOOL (WINAPI* SETLAYEREDWND)(HWND,COLORREF,BYTE,DWORD); 
    SETLAYEREDWND SetLayeredWindowPtr = NULL; 
    SetLayeredWindowPtr = (SETLAYEREDWND)GetProcAddress(hModule, "SetLayeredWindowAttributes");    
     
    if(SetLayeredWindowPtr) 
    {    
        LONG lStyle = GetWindowLong(hWnd,GWL_EXSTYLE)|0x00080000; 
                SetWindowLong(hWnd, GWL_EXSTYLE, lStyle); 

        SetLayeredWindowPtr(hWnd, 
            RGB(0,0,0), 
            BYTE((255 * LayerN)/100), 2); 
    } 

    return true; 
} 

LONG CPostsDlg::OnHotKey(WPARAM wParam,LPARAM lParam)         
{

	UINT fuModifiers = (UINT) LOWORD(lParam);  // key-modifier flags 
	UINT uVirtKey = (UINT) HIWORD(lParam);     // virtual-key code 

	if ((int)wParam==HotKeyID+1)
	{
		OnFileWrite(".\\���ӵ�ַ.txt") ;
	}
	else if((int)wParam==HotKeyID+2)
	{
		OnFileWrite(".\\������ַ.txt") ;
	}
	else
	{
		for (int i=0;i<20;i++)
		{
			if ((int)wParam==CurHotKey[i].hotkeyID)
			{
				PostMessage(WM_COMMAND, MAKEWPARAM(CurHotKey[i].nCTRL_ID, BN_CLICKED), NULL);
  
				keybd_event(VK_CONTROL,MapVirtualKey(VK_CONTROL,0),0 ,0);   
				//   ����ctrl��   
				keybd_event('V',MapVirtualKey('V',0), 0,0);   
				//   ����V��   
				keybd_event('V',MapVirtualKey('V',0),   KEYEVENTF_KEYUP, 0);   
				//   �ſ�v��   
				keybd_event(VK_CONTROL,MapVirtualKey(VK_CONTROL, 0),
					KEYEVENTF_KEYUP,   0   );   
				//   �ſ�Ctrl��   
  
			}
		}
	}

	return 0;        
} 




void CPostsDlg::OnBtnFileOpen() 
{
	ShellExecute(this->m_hWnd,"open",".\\���ӵ�ַ.txt","","",SW_SHOW);
	
}

void CPostsDlg::OnBtnFileWrite() 
{
	ShellExecute(this->m_hWnd,"open",".\\������ַ.txt","","",SW_SHOW);
}


void CPostsDlg::OnFileWrite(char* szFileName) 
{

	/*
	//����ַ�����ݴ����ļ�
	  HWND hWnd = NULL;
	  char szWriteBuf[512]={0}; //д���ļ�������
	  int iBrowserType =-1 ; //�����������

	  hWnd = ::GetForegroundWindow(); //��ǰ�Ļ����

	  TRACE("\n����ھ��:%d\n",hWnd);

	  
	  //----------------------- �жϻ���ڵ�����-------------------
	  char szClassName[512]={0};
		
	  if (!GetClassName(hWnd,szClassName,sizeof(szClassName)/sizeof(char)))
	  {
		MessageBox("û�л�ȡ������",NULL,MB_OK);
	  }

	  TRACE("ClassName: %s",szClassName); 
	
	  if(!strcmp(szClassName,"XFrame_Wnd"))
	  {//360�����2.2
		 iBrowserType = 0;
	  }
	  else if(!strcmp(szClassName,"Maxthon2_Frame"))
	  {
		  	 iBrowserType = 1;
	  }
	  else
	  {
	  	 iBrowserType = -1;
	  }

	  HWND hWndPar=NULL,hWndChild=NULL;

	  hWndPar = hWnd;
	  switch(iBrowserType)
	  {
	  case 0:
			hWndChild =::FindWindowEx(hWndPar,NULL,"XCtrl_Wnd","TopBar");

			hWndChild =::FindWindowEx(hWndChild,NULL,"XCtrl_Wnd","AddressBar");

			//0x44C �ǿؼ�ID��ʮ��������ʽ,�ؼ�id�ǹ̶������
			::GetDlgItemText(hWndChild,0x44C,szWriteBuf,sizeof(szWriteBuf)/sizeof(char));

	  case 1:
			hWndChild =::FindWindowEx(hWndPar,NULL,"XTPDockBar","xtpBarTop");
			hWndChild =::FindWindowEx(hWndChild,NULL,"XTPToolBar",_T("��ַ��"));

			hWndChild =::FindWindowEx(hWndChild,NULL,"RichEdit20W",NULL);

			::SendMessage(hWndChild, WM_GETTEXT,sizeof(szWriteBuf)/sizeof(char),(LPARAM)szWriteBuf); 
	  default:
;
	  }
*/

	  /*
	 char buf[512]; //д���ļ�������
		memset(buf,0,sizeof(buf)/sizeof(char));
		HWND hWndPar=NULL,hWndChild=NULL;
		hWndPar=::FindWindow("XFrame_Wnd",NULL);
		TRACE("\n%d\n",hWndPar);

	if (hWndPar !=NULL)
	{
	
		hWndChild =::FindWindowEx(hWndPar,NULL,"XCtrl_Wnd","TopBar");
		
		hWndChild =::FindWindowEx(hWndChild,NULL,"XCtrl_Wnd","AddressBar");

		//0x44C �ǿؼ�ID��ʮ��������ʽ,�ؼ�id�ǹ̶������
		::GetDlgItemText(hWndChild,0x44C,buf,sizeof(buf)/sizeof(char));
	//MessageBox(buf,NULL,MB_OK);
	
	}
	else
	{
		// ���������
//		char buf[512];
//		memset(buf,0,sizeof(buf)/sizeof(char));
	 	HWND hWndPar=NULL,hWndChild=NULL;
		hWndPar=::FindWindow("Maxthon2_Frame",NULL);
		
		if (hWndPar !=NULL)
		{
		hWndChild =::FindWindowEx(hWndPar,NULL,"XTPDockBar","xtpBarTop");
		hWndChild =::FindWindowEx(hWndChild,NULL,"XTPToolBar",_T("��ַ��"));
		
		hWndChild =::FindWindowEx(hWndChild,NULL,"RichEdit20W",NULL);
		
		::SendMessage(hWndChild, WM_GETTEXT,sizeof(buf)/sizeof(char),(LPARAM)buf); 
		}
		else
		{
			HWND hWndPar=NULL,hWndChild=NULL;
			hWndPar=::FindWindow("SE_SogouExplorerFrame",NULL);
		
			hWndChild =::FindWindowEx(hWndPar,NULL,"SE_TuotuoRebar",NULL);
		
			hWndChild =::FindWindowEx(hWndChild,NULL,"SE_TuotuoAddressBar",NULL);
			hWndChild =::FindWindowEx(hWndChild,NULL,"SE_TuotuoAddressBarComboBox",NULL);
			
			hWndChild =::FindWindowEx(hWndChild,NULL,"SE_TuotuoAddressBarEditCtrl",NULL);
			
			::SendMessage(hWndChild, WM_GETTEXT,sizeof(buf)/sizeof(char),(LPARAM)buf); 
		}
	}

  */


char szWriteBuf[MAX_PATH]={0};

BrowserInfo::GetBrowserURL(szWriteBuf);
	if (int len=strlen(szWriteBuf)!=0)
	{
		
	
		CFile locFile;
		locFile.Open(szFileName,CFile::modeNoTruncate|CFile::modeCreate|
					CFile::modeReadWrite|CFile::shareDenyNone,NULL);

		locFile.SeekToEnd();
		locFile.Write(szWriteBuf,strlen(szWriteBuf));
		locFile.Write("\r\n",2);

		locFile.Close();
	}
	else
		strcpy(szWriteBuf,"û�п��Ա�������ݡ�");
		
		CPopDlg*   myDlg=   new  CPopDlg;   
		myDlg->Create(IDD_POPDIALOG); 
		myDlg->SetWindowText("�ѱ���");
		::SetDlgItemText(myDlg->GetSafeHwnd(),IDC_EDIT_TIP,szWriteBuf);

		myDlg->ShowWindow(SW_SHOW);
}



LONG CPostsDlg::OnNotifyIcon(WPARAM wParam, LPARAM lParam)
{
	
	if((int)wParam==IDD_POSTS_DIALOG)//ȷ����Ŀ�괰�ڷ�������Ϣ(����ʡ��)
	{
		if(lParam==WM_LBUTTONDBLCLK) //��������¼� 
		{ 
			ShowWindow(SW_NORMAL);//��ʾ����
			::Shell_NotifyIcon(NIM_DELETE,&m_Nid); 
			bTray =FALSE;

			//��ǰ��
		//	SetWindowPos(&wndTopMost,0,0,0,0, SWP_NOMOVE|SWP_NOSIZE);
		}
		else if(lParam==WM_RBUTTONDOWN) //�Ҽ������¼� 
		{
			LPPOINT lpoint=new tagPOINT; 
			::GetCursorPos(lpoint);//�õ����λ�� 
			CMenu menu; 
			menu.CreatePopupMenu();//����һ������ʽ�˵� 
			//���Ӳ˵���رա������������ϢWM_DESTROY�������ڣ��� 
			//���أ�������������� 
		// 	menu.AppendMenu(MF_STRING,WM_USER_001,"��ʾ"); 
			menu.AppendMenu(MF_STRING,WM_DESTROY,"�˳�"); 
	
			SetForegroundWindow();
			//ȷ������ʽ�˵���λ�� 
			menu.TrackPopupMenu(TPM_LEFTALIGN,lpoint->x,lpoint->y,this); 
			
			PostMessage(WM_NULL,0,0);
			// http://support.microsoft.com/kb/135788
			// BUGFIX: See "PRB: Menus for Notification Icons Don't Work Correctly"
			//��Դ���� 
			HMENU hmenu=menu.Detach(); 
			menu.DestroyMenu(); 
			delete lpoint; 
		
		}
	
	}
	
	return 0;
}


void CPostsDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	//::Shell_NotifyIcon(NIM_DELETE,&m_Nid); 
	//CDialog::OnClose();
	if (!bTray)
	{
		ShowWindow(SW_HIDE);//���ش���
		::Shell_NotifyIcon(NIM_ADD,&m_Nid); 
		bTray =TRUE;
	}
//	AfxMessageBox("");
}

void CPostsDlg::OnDlgShow()
{
	ShowWindow(SW_NORMAL);//��ʾ����
	::Shell_NotifyIcon(NIM_DELETE,&m_Nid); 
	bTray =FALSE;
}

void CPostsDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	::Shell_NotifyIcon(NIM_DELETE,&m_Nid);

}

void CPostsDlg::HotKeySet()
{

	CHotkeyDlg dlg;
	if (dlg.DoModal()==IDOK)
	{
		CPostsApp* app=(CPostsApp*)AfxGetApp();

		//Register�ȼ�
		int nRet = RegisterHotKey(GetSafeHwnd(),curHotKeyID+1,app->CurHotKey.fsModifiers,
			app->CurHotKey.vk); //�ȼ� ctrl + d
		if(!nRet)
			AfxMessageBox(_T("RegisterHotKey Alt+A  false"));

		//��¼��ǰ�ؼ����ȼ��Ķ�Ӧ��ϵ
		CurHotKey[curHotID].hotkeyID=curHotKeyID+1; //�ȼ�ID
		CurHotKey[curHotID].nCTRL_ID=app->CurHotKey.nCTRL_ID; //�ؼ�ID
		curHotKeyID++; //��ǰ�ȼ������ID
		curHotID++;
	}
	


}

void CPostsDlg::OnDoubleclickedBtnAd1() 
{
	CString strCaption;	
	GetDlgItem(IDC_BTN_AD1)->GetWindowText(strCaption);
	strCaption += _T(".txt");
	strCaption = _T(".\\")+ strCaption;
	ShellExecute(this->m_hWnd,"open",strCaption,"","",SW_SHOW);

}

void CPostsDlg::OnDoubleclickedBtnAd2() 
{
	// TODO: Add your control notification handler code here
	CString strCaption;	
	GetDlgItem(IDC_BTN_AD2)->GetWindowText(strCaption);
	strCaption += _T(".txt");
	strCaption = _T(".\\")+ strCaption;
	ShellExecute(this->m_hWnd,"open",strCaption,"","",SW_SHOW);

}

void CPostsDlg::OnDoubleclickedBtnAd3() 
{
	// TODO: Add your control notification handler code here
	CString strCaption;	
	GetDlgItem(IDC_BTN_AD3)->GetWindowText(strCaption);
	strCaption += _T(".txt");
	strCaption = _T(".\\")+ strCaption;
	ShellExecute(this->m_hWnd,"open",strCaption,"","",SW_SHOW);

}

void CPostsDlg::OnDoubleclickedBtnAd4() 
{
	// TODO: Add your control notification handler code here
	CString strCaption;	
	GetDlgItem(IDC_BTN_AD4)->GetWindowText(strCaption);
	strCaption += _T(".txt");
	strCaption = _T(".\\")+ strCaption;
	ShellExecute(this->m_hWnd,"open",strCaption,"","",SW_SHOW);
	
}

void CPostsDlg::OnDoubleclickedBtnAd5() 
{
	// TODO: Add your control notification handler code here
	CString strCaption;	
	GetDlgItem(IDC_BTN_AD5)->GetWindowText(strCaption);
	strCaption += _T(".txt");
	strCaption = _T(".\\")+ strCaption;
	ShellExecute(this->m_hWnd,"open",strCaption,"","",SW_SHOW);

}

void CPostsDlg::OnDoubleclickedBtnAd6() 
{
	// TODO: Add your control notification handler code here
	CString strCaption;	
	GetDlgItem(IDC_BTN_AD6)->GetWindowText(strCaption);
	strCaption += _T(".txt");
	strCaption = _T(".\\")+ strCaption;
	ShellExecute(this->m_hWnd,"open",strCaption,"","",SW_SHOW);
	
}

void CPostsDlg::OnBtnFolder() 
{
	ShellExecute(NULL,NULL, ".\\",NULL,NULL,SW_SHOW);
}

