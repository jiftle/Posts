
#define Firefox "MozillaUIWindowClass"
#define IE	"IEFrame"
#define Opera	"OperaWindowClass"
#define I360se	"XFrame_Wnd"
#define I360se35	"360se_Frame"
#define Sougou	"SE_SogouExplorerFrame"
#define Maxthon2 "Maxthon2_Frame"
#define Chrome "Chrome_WidgetWin_0"
#define Chrome_39 "Chrome_WidgetWin_1"


enum BrowseType{
	BT_Firefox=0,
		BT_IE,
		BT_Opera,
		BT_I360se,
		BT_I360se35,
		BT_Sougou,
		BT_Maxthon2,
		BT_Chrome,
		BT_Chrome_39, //Chrome_WidgetWin_1

		BT_UNKOWN =100
};

class BrowserInfo{
public:
	static bool GetBrowserURL(char* szURL);
	
protected:
	static bool GetFirefoxURL(HWND hwnd, char* szURL);
	static bool GetIEURL(HWND hwnd, char* szURL);
	static bool GetOperaURL(HWND hwnd, char* szURL);
	static bool GetI360seURL(HWND hwnd, char* szURL);
	static bool GetI360se35URL(HWND hwnd, char* szURL);
	static bool GetSougouURL(HWND hwnd, char* szURL);
	static bool GetMaxthon2URL(HWND hwnd, char* szURL);
	static bool GetChromeURL(HWND hwnd, char* szURL);
	
	static BrowseType GetBrowseType(char * szTitle);
	
};