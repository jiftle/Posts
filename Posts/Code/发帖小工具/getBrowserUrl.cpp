
#include "StdAfx.h"
#include "getBrowserUrl.h"


bool BrowserInfo::GetBrowserURL(char* szURL)
{
	HWND hMainWnd=NULL;
	HWND hChild=NULL,hTmp=NULL;
	char szTitle[128]={0};

	//获得激活窗口的句柄
	hMainWnd = ::GetForegroundWindow();
	if(!hMainWnd) return false;
//	if(!::GetWindowText(hMainWnd,szTitle,sizeof(szTitle)/sizeof(char)))
	//	return false;
	
	if (!::GetClassName(hMainWnd,szTitle,sizeof(szTitle)/sizeof(char)))
	{
		return false;
	}

	BrowseType bt;
	bt=GetBrowseType(szTitle);

	switch(bt)
	{
	case BT_Firefox:
		if(!GetFirefoxURL(hMainWnd,szURL)) return false;
		break;
	case BT_IE:
		if(!GetIEURL(hMainWnd,szURL)) return false;
		break;
	case BT_Opera:
		if (!GetOperaURL(hMainWnd,szURL)) return false;
		break;
	case BT_I360se:
		if(!GetI360seURL(hMainWnd,szURL)) return false;
		break;
	case BT_I360se35:
		if(!GetI360se35URL(hMainWnd,szURL)) return false;
		break;
	case BT_Sougou:
		if(!GetSougouURL(hMainWnd,szURL)) return false;
		break;
	case BT_Maxthon2:
		if(!GetMaxthon2URL(hMainWnd,szURL)) return false;
		break;
	case BT_Chrome:
		if(!GetChromeURL(hMainWnd,szURL)) return false;
		break;
	case BT_Chrome_39:
		if(!GetOperaURL(hMainWnd,szURL)) return false;
		break;
	default:
		return false;
		break;
	}

	return true;
}

BrowseType BrowserInfo::GetBrowseType(char * szTitle)
{
	BrowseType bt;
	int iBrw=0;
	if (strcmp(szTitle,Firefox)==0)
	{
		bt= BT_Firefox;
	}
	else if (strcmp(szTitle,IE)==0)
	{
		bt= BT_IE;
	}
	else if (strcmp(szTitle,Opera)==0)
	{
		bt= BT_Opera;
	}
	else if (strcmp(szTitle,I360se)==0)
	{
		bt= BT_I360se;
	}
	else if (strcmp(szTitle,Sougou)==0)
	{
		bt= BT_Sougou;
	}
	else if (strcmp(szTitle,Maxthon2)==0)
	{
		bt= BT_Maxthon2;
	}
	else if (strcmp(szTitle,Chrome)==0)
	{
		bt= BT_Chrome;
	}
	else if (strcmp(szTitle,Chrome_39)==0)
	{
		bt= BT_Chrome_39;
	}
	else if (strcmp(szTitle,I360se35)==0)
	{
		bt= BT_I360se35;
	}
	else
	{
		bt= BT_UNKOWN;
	}


	return bt;
}

bool BrowserInfo::GetFirefoxURL(HWND hwnd, char* szURL)
{
	Sleep(500); //wait for alt键释放

	keybd_event(VK_CONTROL,0,0,0 );
	keybd_event('L',0,0,0 );
	keybd_event('L',0, KEYEVENTF_KEYUP,	0);
	keybd_event(VK_CONTROL,	0,KEYEVENTF_KEYUP,0);

	keybd_event(VK_CONTROL,0,0,0);
	keybd_event('C',0,0,0);
	keybd_event('C',0,KEYEVENTF_KEYUP,0);
	keybd_event(VK_CONTROL,0,KEYEVENTF_KEYUP,0);

	Sleep(300);

	HANDLE h=::GetClipboardData(CF_TEXT);
	HGLOBAL   hglb; 
	LPTSTR    lptstr; 

	if (!IsClipboardFormatAvailable(CF_TEXT)) 
		return false; 
	if (!OpenClipboard(NULL)) 
		return false; 
	
	hglb = GetClipboardData(CF_TEXT); 
	if (hglb != NULL) 
	{ 
		lptstr = (char*)GlobalLock(hglb); 
		GlobalUnlock(hglb); 
	} 
	CloseClipboard(); 
	
	strcpy(szURL,lptstr);

	return true;
}

bool BrowserInfo::GetIEURL(HWND hwnd, char* szURL)
{
	HWND hwndTmp=NULL,hwndTmp1=NULL;
	char szBuf[MAX_PATH]={0};

	hwndTmp=::FindWindowEx(hwnd,NULL,_T("WorkerW"),NULL);
	if (hwndTmp == NULL) return false;

	hwndTmp1=::FindWindowEx(hwndTmp,NULL,_T("ReBarWindow32"),NULL);
	if (hwndTmp1 == NULL) return false;

	hwndTmp=::FindWindowEx(hwndTmp1,NULL,_T("ComboBoxEx32"),NULL);
	if (hwndTmp == NULL) return false;
	
	int len=::SendMessage(hwndTmp, WM_GETTEXT,(WPARAM)(sizeof(szBuf)/sizeof(char)),(
		LPARAM)szBuf);
	if (!len)
	{
		return false;
	}
	else
	{
		strncpy(szURL,szBuf,len);
		return true;
	}
}

bool BrowserInfo::GetOperaURL(HWND hwnd, char* szURL)
{
	Sleep(500); //wait for alt键释放
	
	keybd_event(VK_CONTROL,0,0,0 );
	keybd_event('L',0,0,0 );
	keybd_event('L',0, KEYEVENTF_KEYUP,	0);
	keybd_event(VK_CONTROL,	0,KEYEVENTF_KEYUP,0);
	
	keybd_event(VK_CONTROL,0,0,0);
	keybd_event('C',0,0,0);
	keybd_event('C',0,KEYEVENTF_KEYUP,0);
	keybd_event(VK_CONTROL,0,KEYEVENTF_KEYUP,0);
	
	Sleep(300);
	
	HANDLE h=::GetClipboardData(CF_TEXT);
	HGLOBAL   hglb; 
	LPTSTR    lptstr; 
	
	if (!IsClipboardFormatAvailable(CF_TEXT)) 
		return false; 
	if (!OpenClipboard(NULL)) 
		return false; 
	
	hglb = GetClipboardData(CF_TEXT); 
	if (hglb != NULL) 
	{ 
		lptstr = (char*)GlobalLock(hglb); 
		GlobalUnlock(hglb); 
	} 
	CloseClipboard(); 
	
	strcpy(szURL,lptstr);

	return true;
}

bool BrowserInfo::GetI360seURL(HWND hwnd, char* szURL)
{
	HWND hwndTmp=NULL,hwndTmp1=NULL;
	char szBuf[MAX_PATH]={0};
	
	hwndTmp=::FindWindowEx(hwnd,NULL,_T("XCtrl_Wnd"),_T("TopBar"));
	if (hwndTmp == NULL) return false;
	
	hwndTmp1=::FindWindowEx(hwndTmp,NULL,_T("XCtrl_Wnd"),_T("AddressBar"));
	if (hwndTmp1 == NULL) return false;
			
	//int len=::SendMessage(hwndTmp1, WM_GETTEXT,(WPARAM)(sizeof(szBuf)/sizeof(char)),(
	//	LPARAM)szBuf);
	
	//0x44C 是控件ID的十六进制形式,控件id是固定不变的 spy++ 中的标识符就是Contrl ID
	int len=::GetDlgItemText(hwndTmp1,0x44C,szBuf,sizeof(szBuf)/sizeof(char));
	if (!len)
	{
		return false;
	}
	else
	{
		strncpy(szURL,szBuf,len);
		return true;
	}
	return true;
}
bool BrowserInfo::GetSougouURL(HWND hwnd, char* szURL)
{
	HWND hwndTmp=NULL,hwndTmp1=NULL;
	char szBuf[MAX_PATH]={0};
	
	hwndTmp=::FindWindowEx(hwnd,NULL,_T("SE_TuotuoRebar"),NULL);
	if (hwndTmp == NULL) return false;
	
	hwndTmp1=::FindWindowEx(hwndTmp,NULL,_T("SE_TuotuoAddressBar"),NULL);
	if (hwndTmp1 == NULL) return false;
	hwndTmp=::FindWindowEx(hwndTmp1,NULL,_T("SE_TuotuoAddressBarComboBox"),NULL);
	if (hwndTmp == NULL) return false;
	hwndTmp1=::FindWindowEx(hwndTmp,NULL,_T("SE_TuotuoAddressBarEditCtrl"),NULL);
	if (hwndTmp1 == NULL) return false;

	int len=::SendMessage(hwndTmp1, WM_GETTEXT,(WPARAM)(sizeof(szBuf)/sizeof(char)),(
		LPARAM)szBuf);
	
	if (!len)
	{
		return false;
	}
	else
	{
		strncpy(szURL,szBuf,len);
		return true;
	}
	return true;
}

bool BrowserInfo::GetMaxthon2URL(HWND hwnd, char* szURL)
{
	char buf[512];
	memset(buf,0,sizeof(buf)/sizeof(char));
	HWND hWndPar=NULL,hWndChild=NULL;
	
	hWndChild =::FindWindowEx(hwnd,NULL,"XTPDockBar","xtpBarTop");
	hWndChild =::FindWindowEx(hWndChild,NULL,"XTPToolBar",_T("地址栏"));
	
	hWndChild =::FindWindowEx(hWndChild,NULL,"RichEdit20W",NULL);
	
	int len=::SendMessage(hWndChild, WM_GETTEXT,(WPARAM)(sizeof(buf)/sizeof(char)),(
						LPARAM)buf);
	if (!len)
	{
		return false;
	}
	else
	{
		strncpy(szURL,buf,len);
		return true;
	}
}

bool BrowserInfo::GetChromeURL(HWND hwnd, char* szURL)
{

	HWND hwndTmp=NULL,hwndTmp1=NULL;
	char szBuf[MAX_PATH]={0};
	
	hwndTmp=::FindWindowEx(hwnd,NULL,_T("Chrome_AutocompleteEditView"),NULL);
	if (hwndTmp == NULL) return false;
	
	int len=::SendMessage(hwndTmp, WM_GETTEXT,(WPARAM)(sizeof(szBuf)/sizeof(char)),(
		LPARAM)szBuf);
	if (!len)
	{
		return false;
	}
	else
	{
		strncpy(szURL,szBuf,len);
		return true;
	}
}

bool BrowserInfo::GetI360se35URL(HWND hwnd, char* szURL)
{
	HWND hwndTmp=NULL,hwndTmp1=NULL;
	char szBuf[MAX_PATH]={0};
	
	hwndTmp=::FindWindowEx(hwnd,NULL,_T("XToolBar"),_T("TopBar"));
	if (hwndTmp == NULL) return false;
	
	hwndTmp1=::FindWindowEx(hwndTmp,NULL,_T("XToolBar"),_T("MajorBar"));
	if (hwndTmp1 == NULL) return false;
	
	hwndTmp = GetDlgItem(hwndTmp1,0x0003EB);

// 	hwndTmp=::FindWindowEx(hwndTmp1,NULL,_T("XWnd"),NULL);
// 	if (hwndTmp == NULL) return false;

	hwndTmp1=::FindWindowEx(hwndTmp,NULL,_T("RichEdit20W"),NULL);
	if (hwndTmp1 == NULL) return false;


	int len=::SendMessage(hwndTmp1, WM_GETTEXT,(WPARAM)(sizeof(szBuf)/sizeof(char)),(
	LPARAM)szBuf);
	
	//0x44C 是控件ID的十六进制形式,控件id是固定不变的 spy++ 中的标识符就是Contrl ID
//	int len=::GetDlgItemText(hwndTmp1,0x44C,szBuf,sizeof(szBuf)/sizeof(char));
	if (!len)
	{
		return false;
	}
	else
	{
		strncpy(szURL,szBuf,len);
		return true;
	}
	return true;
}
