// SCCDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SCC.h"
#include "SCCDlg.h"

#include "ConfigDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	CWinXPButtonST	m_btnOK;
	CHyperLink	m_staHomePage;
	CHyperLink	m_staEMail;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	virtual BOOL OnInitDialog();
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
	DDX_Control(pDX, IDOK, m_btnOK);
	DDX_Control(pDX, IDC_STATIC_HOMEPAGE, m_staHomePage);
	DDX_Control(pDX, IDC_STATIC_EMAIL, m_staEMail);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSCCDlg dialog

CSCCDlg::CSCCDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSCCDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSCCDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSCCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSCCDlg)
	DDX_Control(pDX, IDC_COMBO_DIRECTCONVERT_STX, m_comboDirectConvertStx);
	DDX_Control(pDX, IDC_RADIO_CONVERT_BY_FILE, m_btnConvertByFile);
	DDX_Control(pDX, IDC_BUTTON_CONFIG, m_btnConfig);
	DDX_Control(pDX, IDC_BUTTON_EXECUTE, m_btnExecute);
	DDX_Control(pDX, IDC_BUTTON_ABOUT, m_btnAbout);
	DDX_Control(pDX, IDC_BUTTON_BROWSE, m_btnBrowse);
	DDX_Control(pDX, IDC_BUTTON_PROCESS, m_btnProcess);
	DDX_Control(pDX, IDC_EDIT_OUTPUT, m_edtOutput);
	DDX_Control(pDX, IDC_EDIT_FILE_SOURCE, m_edtFileSource);
	DDX_Control(pDX, IDC_CHECK_SHOWLINENUM, m_btnShowLineNum);
	DDX_Control(pDX, IDC_RADIO_STYLE_UBB, m_btnStyleUBB);
	DDX_Control(pDX, IDC_RADIO_STYLE_HTML, m_btnStyleHTML);
	DDX_Control(pDX, IDC_EDIT_FILE_DESTINATION, m_edtFileDestination);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSCCDlg, CDialog)
	//{{AFX_MSG_MAP(CSCCDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_PROCESS, OnButtonProcess)
	ON_BN_CLICKED(IDC_BUTTON_BROWSE, OnButtonBrowse)
	ON_BN_CLICKED(IDC_BUTTON_ABOUT, OnButtonAbout)
	ON_BN_CLICKED(IDC_BUTTON_EXECUTE, OnButtonExecute)
	ON_BN_CLICKED(IDC_BUTTON_CONFIG, OnButtonConfig)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_RADIO_STYLE_UBB, OnRadioStyleUbb)
	ON_BN_CLICKED(IDC_RADIO_STYLE_HTML, OnRadioStyleHtml)
	ON_BN_CLICKED(IDC_RADIO_CONVERT_DIRECT, OnRadioConvertDirect)
	ON_BN_CLICKED(IDC_RADIO_CONVERT_BY_FILE, OnRadioConvertByFile)
	ON_EN_SETFOCUS(IDC_EDIT_OUTPUT, OnSetfocusEditOutput)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSCCDlg message handlers

BOOL CSCCDlg::OnInitDialog()
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
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	short shBtnColor = 30;

	m_btnStyleHTML.SetCheck(BST_CHECKED);
	m_btnConvertByFile.SetCheck(BST_CHECKED);
	m_comboDirectConvertStx.SetCurSel(0);

	m_btnShowLineNum.SetIcon(IDI_ICON_LEDON, IDI_ICON_LEDOFF);
	m_btnShowLineNum.SetTooltipText(_T("设置是否需要显示行号"), TRUE);
	//m_btnShowLineNum.SetCheck(BST_CHECKED);

	m_btnAbout.SetIcon(IDI_ICON_ABOUT);
	m_btnAbout.SetTooltipText(_T("关于本软件..."), TRUE);
	m_btnAbout.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, shBtnColor);
	m_btnAbout.SetRounded(TRUE);

	m_btnProcess.SetIcon(IDI_ICON_PROCESS);
	m_btnProcess.SetTooltipText(_T("开始转换"), TRUE);
	m_btnProcess.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, shBtnColor);
	m_btnProcess.SetRounded(TRUE);

	m_btnBrowse.SetIcon(IDI_ICON_BROWSE);
	m_btnBrowse.SizeToContent();
	m_btnBrowse.SetTooltipText(_T("打开一个源代码文件..."), TRUE);
	m_btnBrowse.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, shBtnColor);
	m_btnBrowse.SetRounded(TRUE);

	m_btnExecute.SetIcon(IDI_ICON_EXECUTE);
	m_btnExecute.SizeToContent();
	m_btnExecute.SetTooltipText(_T("查看着色效果..."), TRUE);
	m_btnExecute.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, shBtnColor);
	m_btnExecute.SetRounded(TRUE);

	//m_btnExit.SetIcon(IDI_ICON_EXIT, (int)BTNST_AUTO_GRAY);
	m_btnConfig.SetIcon(IDI_ICON_CONFIG_ON, IDI_ICON_CONFIG_OFF);
	m_btnConfig.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, shBtnColor);
	m_btnConfig.SetTooltipText(_T("参数设置..."), TRUE);

	//设置默认颜色：
	/*
	m_colorKeyword = RGB(0, 0, 255);		//blue
	m_colorMacro = RGB(255, 0, 0);			//red
	m_colorRegister = RGB(128, 128, 0);		//#808000
	m_colorQuotation = RGB(255, 0, 255);	//#FF00FF  orange
	m_colorComment = RGB(0, 128, 0);		//#008000  green
	m_colorLineNum = RGB(128, 128, 128);	//#808080
	*/

	//设置默认的行号后的空格数：
	m_nLineNumIndent = 2;

	m_strCaption = _T("老罗代码着色器 by LC");

	//读取INI文件：
	//初始化ini文件的路径：
	GetCurrentDirectory(MAX_PATH, m_strIniFile.GetBuffer(MAX_PATH));
	m_strIniFile.ReleaseBuffer();
	m_strIniFile += "\\SCC.ini";

	//读入颜色值：
	char szColor[7];
	//关键字：
	GetPrivateProfileString(_T("COLORS"), _T("Keyword"), _T("FF0000"), szColor, 7, m_strIniFile);
	szColor[6] = '\0';
	m_colorKeyword = strtol(szColor, NULL, 16);
	//m_colorKeyword = RGB(GetBValue(m_colorKeyword), GetGValue(m_colorKeyword), GetRValue(m_colorKeyword));

	//宏定义：
	GetPrivateProfileString(_T("COLORS"), _T("Macro"), _T("0000FF"), szColor, 7, m_strIniFile);
	szColor[6] = '\0';
	m_colorMacro = strtol(szColor, NULL, 16);
	//m_colorMacro = RGB(GetBValue(m_colorMacro), GetGValue(m_colorMacro), GetRValue(m_colorMacro));

	//寄存器：
	GetPrivateProfileString(_T("COLORS"), _T("Register"), _T("008080"), szColor, 7, m_strIniFile);
	szColor[6] = '\0';
	m_colorRegister = strtol(szColor, NULL, 16);
	//m_colorRegister = RGB(GetBValue(m_colorRegister), GetGValue(m_colorRegister), GetRValue(m_colorRegister));

	//双引号：
	GetPrivateProfileString(_T("COLORS"), _T("Quotation"), _T("FF00FF"), szColor, 7, m_strIniFile);
	szColor[6] = '\0';
	m_colorQuotation = strtol(szColor, NULL, 16);
	//m_colorQuotation = RGB(GetBValue(m_colorQuotation), GetGValue(m_colorQuotation), GetRValue(m_colorQuotation));

	//注释：
	GetPrivateProfileString(_T("COLORS"), _T("Comment"), _T("008000"), szColor, 7, m_strIniFile);
	szColor[6] = '\0';
	m_colorComment = strtol(szColor, NULL, 16);
	//m_colorComment = RGB(GetBValue(m_colorComment), GetGValue(m_colorComment), GetRValue(m_colorComment));

	//行号：
	GetPrivateProfileString(_T("COLORS"), _T("LineNum"), _T("808080"), szColor, 7, m_strIniFile);
	szColor[6] = '\0';
	m_colorLineNum = strtol(szColor, NULL, 16);
	//m_colorLineNum = RGB(GetBValue(m_colorLineNum), GetGValue(m_colorLineNum), GetRValue(m_colorLineNum));

	//初始化“将TAB转换成空格”：
	m_nChangeTabToSpace = GetPrivateProfileInt(_T("MISC"), _T("Change_Tab_To_Space"), BST_CHECKED, m_strIniFile);

	//初始化“将空格转换成&nbsp”：
	m_nChangeSpaceToNbsp = GetPrivateProfileInt(_T("MISC"), _T("Change_Space_To_Nbsp"), BST_CHECKED, m_strIniFile);

	//初始化“将回车转换成<br>”：
	m_nChangeCRLFToBr = GetPrivateProfileInt(_T("MISC"), _T("Change_CRLF_To_Br"), BST_CHECKED, m_strIniFile);

	//初始化TAB_SPACE的状态：
	m_nTabSpace = GetPrivateProfileInt("MISC", "TAB_SPACE", 4, m_strIniFile);

	//初始化行号后的空格数：
	m_nLineNumIndent = GetPrivateProfileInt("MISC", "LINE_NUM_INDENT", 2, m_strIniFile);

	//从中间展开显示主对话框：
	CenterWindow();
	AnimateWindow(m_hWnd, 100, AW_CENTER);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

float CSCCDlg::DecToHex(CString szInput)
{
	CString szOutput;
	CString x;
	float out;

	out = (float)atoi((LPCTSTR)szInput[0]);

	return out;
}

void CSCCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSCCDlg::OnPaint() 
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
HCURSOR CSCCDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

/********************************************
//函数名：LoadKeywordMacro
//作用：载入关键字和宏
//参数说明：无
********************************************/
void CSCCDlg::LoadKeywordMacro()
{
	//清零：
	m_strarrayKeyword.RemoveAll();
	m_strarrayMacro.RemoveAll();

	//关键字表和宏表定义：
	CStdioFile hFileStx;
	CString szCurrentDir;
	GetModuleFileName(GetModuleHandle("SCC"), szCurrentDir.GetBuffer(MAX_PATH), MAX_PATH);
	szCurrentDir.ReleaseBuffer();
	int nPos = szCurrentDir.ReverseFind(_T('\\'));
	szCurrentDir.Delete(nPos, szCurrentDir.GetLength() - nPos);
	CString szFileNameStx = szCurrentDir + _T("\\stx\\") + m_strFileExt + _T(".stx");

	if (!hFileStx.Open(szFileNameStx, CFile::modeRead))
	{
		MessageBox(m_strFileExt);
		MessageBox(_T("打开stx文件出错！"), m_strCaption, MB_OK | MB_ICONHAND);
	}
	else
	{
		CString szTemp;
		while (hFileStx.ReadString(szTemp))
		{
			if (szTemp == _T("[Keyword]"))
			{
				break;
			}
		}
		while (hFileStx.ReadString(szTemp))
		{
			if (szTemp == _T("[Macro]") || szTemp == _T("[Register]"))
			{
				break;
			}
			else if (szTemp != _T(""))
			{
				m_strarrayKeyword.Add(szTemp);
			}
		}

		hFileStx.SeekToBegin();
		while (hFileStx.ReadString(szTemp))
		{
			if (szTemp == _T("[Macro]"))
			{
				break;
			}
		}
		while (hFileStx.ReadString(szTemp))
		{
			if (szTemp == _T("[Keyword]") || szTemp == _T("[Register]"))
			{
				break;
			}
			else if (szTemp != _T(""))
			{
				m_strarrayMacro.Add(szTemp);
			}
		}

		hFileStx.SeekToBegin();
		while (hFileStx.ReadString(szTemp))
		{
			if (szTemp == _T("[Register]"))
			{
				break;
			}
		}
		while (hFileStx.ReadString(szTemp))
		{
			if ((szTemp == _T("[Keyword]")) || (szTemp == _T("[Macro]")))
			{
				break;
			}
			else if (szTemp != _T(""))
			{
				m_strarrayRegister.Add(szTemp);
			}
		}

		hFileStx.Close();
	}
}

void CSCCDlg::ProcessCpp(CString szFileContent)
{
	//载入关键字和宏：
	LoadKeywordMacro();

	//初始化颜色值：
	//关键字：
	CString szColorKeyword;
	szColorKeyword.Format("#%02X%02X%02X", GetRValue(m_colorKeyword), GetGValue(m_colorKeyword), GetBValue(m_colorKeyword));

	//宏定义：
	CString szColorMacro;
	szColorMacro.Format("#%02X%02X%02X", GetRValue(m_colorMacro), GetGValue(m_colorMacro), GetBValue(m_colorMacro));

	//寄存器：
	CString szColorRegister;
	szColorRegister.Format("#%02X%02X%02X", GetRValue(m_colorRegister), GetGValue(m_colorRegister), GetBValue(m_colorRegister));

	//双引号：
	CString szColorQuotation;
	szColorQuotation.Format("#%02X%02X%02X", GetRValue(m_colorQuotation), GetGValue(m_colorQuotation), GetBValue(m_colorQuotation));

	//注释：
	CString szColorComment;
	szColorComment.Format("#%02X%02X%02X", GetRValue(m_colorComment), GetGValue(m_colorComment), GetBValue(m_colorComment));

	//行号颜色：
	CString szColorLineNum;
	szColorLineNum.Format("#%02X%02X%02X", GetRValue(m_colorLineNum), GetGValue(m_colorLineNum), GetBValue(m_colorLineNum));

	CString szOutput = "";
	CString szReplacement = "";
	BOOL bNeedCRLF = TRUE;
	int i;
	int j;
	int nLineNumIndent;

	/*
	//读入文件内容：
	CFile hFileInput;
	CString szFileContent = "";
	if (!hFileInput.Open(m_strFileNameSource, CFile::modeRead))
	{
		MessageBox("读取 " + m_strFileNameSource + " 文件时出错！", m_strCaption, MB_OK | MB_ICONHAND);
		return ;
	}
	else
	{
		hFileInput.ReadHuge(szFileContent.GetBuffer(hFileInput.GetLength()), hFileInput.GetLength());
		hFileInput.Close();
		//释放缓冲区：
		szFileContent.ReleaseBuffer();
	}
	*/

	int nRowNum = 1;
	CString szFormat;
	if (m_btnShowLineNum.GetCheck() == 1)		//如果要显示行号
	{
		int nPos = -1;
		int nRowCount = 1;
		//统计文件的行数：
		while ((nPos = szFileContent.Find("\r\n", nPos + 1)) != -1)
		{
			nRowCount++;
		}
		szFormat.Format("%d", nRowCount);
		szFormat.Format("%d", szFormat.GetLength());
		szFormat = _T('%') + szFormat + _T("d");
	}

	if (m_btnStyleHTML.GetCheck() == 1)								//如果用HTML标签
	{
		if (m_btnShowLineNum.GetCheck() == 1)						//如果要显示行号
		{
			szReplacement.Format(szFormat, nRowNum++);
			szReplacement.Replace(_T(' '), _T('0'));
			szOutput += _T("<font color=") + szColorLineNum + _T(">") + szReplacement + _T("</font>");
			for (nLineNumIndent = 0; nLineNumIndent < m_nLineNumIndent; nLineNumIndent++)
			{
				szOutput += _T("&nbsp;");
			}
		}
		for (i = 0; i < szFileContent.GetLength(); ++i)				//开始逐个字符进行判断
		{
			szReplacement = szFileContent.GetAt(i);
			if ((szReplacement == _T('/')) && (szFileContent.GetAt(i + 1) == _T('*')))	//如果是“/*”（注释的前半段）
			{
				szOutput += _T("<font color=") + szColorComment + _T(">/*");
				++i;
				while ((szFileContent.GetAt(++i) != _T('*')) || (szFileContent.GetAt(i + 1) != _T('/')))	//直到“*/”为止
				{
					szReplacement = szFileContent.GetAt(i);
					if (szReplacement == _T('<'))					//如果是“<”
					{
						szOutput += _T("&lt;");						//转换成“&lt;”（HTML）
					}
					else if (szReplacement == _T('>'))				//如果是“>”
					{
						szOutput += _T("&gt;");						//转换成“&gt;”（HTML）
					}
					else if (szReplacement == _T('\t'))				//如果是TAB
					{
						if (m_nChangeTabToSpace == BST_CHECKED)
						{
							for (int k = 0; k < m_nTabSpace; ++k)
							{
								szOutput += _T("&nbsp;");
							}
						}
						else
						{
							szOutput += _T('\t');
						}
						//szOutput += _T("&nbsp;&nbsp;&nbsp;&nbsp;");	//转换成四个“&nbsp;”（空格）
					}
					else if (szReplacement == _T(' '))				//如果是空格
					{
						if (m_nChangeSpaceToNbsp == BST_CHECKED)
						{
							szOutput += _T("&nbsp;");					//转换成“&nbsp;”（HTML）
						}
						else
						{
							szOutput += _T(' ');
						}
					}
					else if ((szReplacement == _T('\r')) && (szFileContent.GetAt(i + 1) == _T('\n')))	//如果是换行符
					{
						if (m_nChangeCRLFToBr == BST_CHECKED)
						{
							szOutput += _T("<br>");						//转换成“<br>”（HTML）
						}
						else
						{
							szOutput += _T("\r\n");
						}
						if (m_btnShowLineNum.GetCheck() == 1)		//如果要显示行号
						{
							szReplacement.Format(szFormat, nRowNum++);
							szReplacement.Replace(_T(' '), _T('0'));
							szOutput += _T("<font color=") + szColorLineNum + _T(">") + szReplacement + _T("</font>");
							for (nLineNumIndent = 0; nLineNumIndent < m_nLineNumIndent; nLineNumIndent++)
							{
								szOutput += _T("&nbsp;");
							}
							++i;
						}
					}
					else
					{
						szOutput += szReplacement;
					}
				}
				szOutput += _T("*/</font>");						//“*/”的结束
				++i;
			}
			else if ((szReplacement == _T('/')) && (szFileContent.GetAt(i + 1) == _T('/')))	//如果是“//”（注释）
			{
				szOutput += _T("<font color=") + szColorComment + _T(">") + szReplacement;
				while (((szReplacement = szFileContent.GetAt(++i)) != _T('\r')) || (szFileContent.GetAt(i + 1) != _T('\n')))	//直到换行符为止（一行的最后）
				{
					if (szReplacement == _T('<'))					//如果是“<”
					{
						szOutput += _T("&lt;");						//转换成“&lt;”（HTML）
					}
					else if (szReplacement == _T('>'))				//如果是“>”
					{
						szOutput += _T("&gt;");						//转换成“&gt;”（HTML）
					}
					else if (szReplacement == _T('\t'))				//如果是TAB
					{
						if (m_nChangeTabToSpace == BST_CHECKED)
						{
							for (int k = 0; k < m_nTabSpace; ++k)
							{
								szOutput += _T("&nbsp;");
							}
						}
						else
						{
							szOutput += _T('\t');
						}
						//szOutput += _T("&nbsp;&nbsp;&nbsp;&nbsp;");	//转换成四个“&nbsp;”（空格）
					}
					else if (szReplacement == _T(' '))				//如果是空格
					{
						if (m_nChangeSpaceToNbsp == BST_CHECKED)
						{
							szOutput += _T("&nbsp;");					//转换成“&nbsp;”（HTML）
						}
						else
						{
							szOutput += _T(' ');
						}
					}
					else
					{
						szOutput += szReplacement;
					}
					if (szFileContent.GetAt(i + 1) == NULL)			//如果注释行没有换行符
					{
						bNeedCRLF = FALSE;
						break;
					}
				}
				if (bNeedCRLF)
				{
					szOutput += _T("</font>");
					if (m_nChangeCRLFToBr == BST_CHECKED)
					{
						szOutput += _T("<br>");
					}
					else
					{
						szOutput += _T("\r\n");
					}
					if (m_btnShowLineNum.GetCheck() == 1)			//如果要显示行号
					{
						szReplacement.Format(szFormat, nRowNum++);
						szReplacement.Replace(_T(' '), _T('0'));
						szOutput += _T("<font color=") + szColorLineNum + _T(">") + szReplacement + _T("</font>");
						for (nLineNumIndent = 0; nLineNumIndent < m_nLineNumIndent; nLineNumIndent++)
						{
							szOutput += _T("&nbsp;");
						}
						++i;
					}
				}
				else
				{
					szOutput += _T("</font>");
				}
			}
			else if (IsLetter(szReplacement))						//如果是字符
			{
				while (IsLetter(szFileContent.GetAt(++i)))			//循环读下一个，直到不是字符为止
				{
					szReplacement += szFileContent.GetAt(i);
				}
				for (j = 0; j < m_strarrayKeyword.GetSize(); ++j)	//对比看它是否为关键字
				{
					if (szReplacement.CompareNoCase(m_strarrayKeyword[j]) == 0)		//如果是关键字
					{
						szReplacement = _T("<font color=") + szColorKeyword + _T(">") + szReplacement + _T("</font>");
						break;
					}
				}
				for (j = 0; j < m_strarrayMacro.GetSize(); ++j)		//对比看它是否为宏定义
				{
					if (szReplacement.CompareNoCase(m_strarrayMacro[j]) == 0)		//如果是宏定义
					{
						szReplacement = _T("<font color=") + szColorMacro + _T(">") + szReplacement + _T("</font>");
						break;
					}
				}
				for (j = 0; j < m_strarrayRegister.GetSize(); ++j)	//对比看它是否为寄存器
				{
					if (szReplacement.CompareNoCase(m_strarrayRegister[j]) == 0)	//如果是寄存器
					{
						szReplacement = _T("<font color=") + szColorRegister + _T(">") + szReplacement + _T("</font>");
						break;
					}
				}
				szOutput += szReplacement;
				--i;
			}
			else if (szReplacement == _T('<'))						//如果是“<”
			{
				szOutput += _T("&lt;");								//转换成“&lt;”（HTML）
			}
			else if (szReplacement == _T('>'))						//如果是“>”
			{
				szOutput += _T("&gt;");								//转换成“&gt;”（HTML）
			}
			else if (szReplacement == _T('\t'))						//如果是TAB
			{
				if (m_nChangeTabToSpace == BST_CHECKED)
				{
					for (int k = 0; k < m_nTabSpace; ++k)
					{
						szOutput += _T("&nbsp;");
					}
				}
				else
				{
					szOutput += _T('\t');
				}
				//szOutput += _T("&nbsp;&nbsp;&nbsp;&nbsp;");			//转换成四个“&nbsp;”（空格）
			}
			else if (szReplacement == _T(' '))						//如果是空格
			{
				if (m_nChangeSpaceToNbsp == BST_CHECKED)
				{
					szOutput += _T("&nbsp;");							//转换成“&nbsp;”（HTML）
				}
				else
				{
					szOutput += _T(' ');
				}
			}
			else if ((szReplacement == _T('\"')) && (szFileContent.GetAt(i - 1) != _T('\\')))	//如果是“"”
			{
				szOutput += _T("<font color=") + szColorQuotation + _T(">&quot;");// + szReplacement;
				while ((szReplacement = szFileContent.GetAt(++i)) != _T('\"'))					//直到“"”为止
				{
					if (szReplacement == _T('<'))					//如果是“<”
					{
						szOutput += _T("&lt;");						//转换成“&lt;”（HTML）
					}
					else if (szReplacement == _T('>'))				//如果是“>”
					{
						szOutput += _T("&gt;");						//转换成“&gt;”（HTML）
					}
					else if (szReplacement == _T('\t'))				//如果是TAB
					{
						if (m_nChangeTabToSpace == BST_CHECKED)
						{
							for (int k = 0; k < m_nTabSpace; ++k)
							{
								szOutput += _T("&nbsp;");
							}
						}
						else
						{
							szOutput += _T('\t');
						}
						//szOutput += _T("&nbsp;&nbsp;&nbsp;&nbsp;");	//转换成四个“&nbsp;”（空格）
					}
					else if (szReplacement == _T(' '))				//如果是空格
					{
						if (m_nChangeSpaceToNbsp == BST_CHECKED)
						{
							szOutput += _T("&nbsp;");					//转换成“&nbsp;”（HTML）
						}
						else
						{
							szOutput += _T(' ');
						}
					}
					else if ((szReplacement == _T('\r')) && (szFileContent.GetAt(i + 1) == _T('\n')))	//如果是换行符
					{
						if (m_nChangeCRLFToBr == BST_CHECKED)
						{
							szOutput += _T("<br>");						//转换成“<br>”（HTML）
						}
						else
						{
							szOutput += _T("\r\n");
						}
						if (m_btnShowLineNum.GetCheck() == 1)		//如果要显示行号
						{
							szReplacement.Format(szFormat, nRowNum++);
							szReplacement.Replace(_T(' '), _T('0'));
							szOutput += _T("<font color=") + szColorLineNum + _T(">") + szReplacement + _T("</font>");
							for (nLineNumIndent = 0; nLineNumIndent < m_nLineNumIndent; nLineNumIndent++)
							{
								szOutput += _T("&nbsp;");
							}
							++i;
						}
					}
					else
					{
						szOutput += szReplacement;
					}
				}
				//szOutput += szReplacement + _T("</font>");			//“"”的结束
				szOutput += _T("&quot;</font>");
			}
			else if ((szReplacement == _T('\r')) && (szFileContent.GetAt(i + 1) == _T('\n')))	//如果是换行符
			{
				if (m_nChangeCRLFToBr == BST_CHECKED)
				{
					szOutput += _T("<br>");								//转换成“<br>”
				}
				else
				{
					szOutput += _T("\r\n");
				}
				if (m_btnShowLineNum.GetCheck() == 1)				//如果要显示行号
				{
					szReplacement.Format(szFormat, nRowNum++);
					szReplacement.Replace(_T(' '), _T('0'));
					szOutput += _T("<font color=") + szColorLineNum + _T(">") + szReplacement + _T("</font>");
					for (nLineNumIndent = 0; nLineNumIndent < m_nLineNumIndent; nLineNumIndent++)
					{
						szOutput += _T("&nbsp;");
					}
					++i;
				}
			}
			else		//如果都不满足上面的条件，则直接输出，不进行任何格式转换
			{
				szOutput += szReplacement;
			}
		}
	}
	else if (m_btnStyleUBB.GetCheck() == 1)							//如果用UBB标签
	{
		if (m_btnShowLineNum.GetCheck() == 1)						//如果要显示行号
		{
			szReplacement.Format(szFormat, nRowNum++);
			szReplacement.Replace(_T(' '), _T('0'));
			szOutput += _T("[color=") + szColorLineNum + _T("]") + szReplacement + _T("[/color]");
			for (nLineNumIndent = 0; nLineNumIndent < m_nLineNumIndent; nLineNumIndent++)
			{
				//szOutput += _T("&nbsp;");
				szOutput += _T(' ');
			}
		}
		for (i = 0; i < szFileContent.GetLength(); ++i)				//开始逐个字符进行判断
		{
			szReplacement = szFileContent.GetAt(i);
			if ((szReplacement == _T('/')) && (szFileContent.GetAt(i + 1) == _T('*')))	//如果是“/*”（注释的前半段）
			{
				szOutput += _T("[color=") + szColorComment + _T("]/*");
				++i;
				while ((szFileContent.GetAt(++i) != _T('*')) || (szFileContent.GetAt(i + 1) != _T('/')))	//直到“*/”为止（注释的最后）
				{
					szReplacement = szFileContent.GetAt(i);
					if (szReplacement == _T('\t'))					//如果是TAB
					{
						if (m_nChangeTabToSpace == BST_CHECKED)
						{
							for (int k = 0; k < m_nTabSpace; ++k)
							{
								//szOutput += _T("&nbsp;");
								szOutput += _T(' ');
							}
						}
						else
						{
							szOutput += _T('\t');
						}
						//szOutput += _T("&nbsp;&nbsp;&nbsp;&nbsp;");	//转换成四个“&nbsp;”（空格）
					}
					/*
					else if (szReplacement == _T(' '))				//如果是空格
					{
						if (m_nChangeSpaceToNbsp == BST_CHECKED)
						{
							szOutput += _T("&nbsp;");					//转换成“&nbsp;”（UBB）
						}
						else
						{
							szOutput += _T(' ');
						}
					}
					*/
					else if ((szReplacement == _T('\r')) && (szFileContent.GetAt(i + 1) == _T('\n')))	//如果是换行符
					{
						/*
						if (m_nChangeCRLFToBr == BST_CHECKED)
						{
							szOutput += _T("[br]");						//转换成“[br]”（UBB）
						}
						else
						*/
						{
							//szOutput += _T("\r\n");
							if (m_btnShowLineNum.GetCheck() == 1)
							{
								szOutput += _T("[/color]");
							}
							szOutput += _T('\r');
						}
						if (m_btnShowLineNum.GetCheck() == 1)		//如果要显示行号
						{
							szReplacement.Format(szFormat, nRowNum++);
							szReplacement.Replace(_T(' '), _T('0'));
							szOutput += _T("[color=") + szColorLineNum + _T("]") + szReplacement + _T("[/color]");
							for (nLineNumIndent = 0; nLineNumIndent < m_nLineNumIndent; nLineNumIndent++)
							{
								//szOutput += _T("&nbsp;");
								szOutput += _T(' ');
							}
							++i;
							szOutput += _T("[color=") + szColorComment + _T("]/*");
						}
					}
					else
					{
						szOutput += szReplacement;
					}
				}
				szOutput += _T("*/[/color]");						//“*/”的结束
				++i;
			}
			else if ((szReplacement == _T('/')) && (szFileContent.GetAt(i + 1) == _T('/')))	//如果是“//”（注释）
			{
				szOutput += _T("[color=") + szColorComment + _T("]") + szReplacement;
				while (((szReplacement = szFileContent.GetAt(++i)) != _T('\r')) || (szFileContent.GetAt(i + 1) != _T('\n')))	//直到换行符为止（一行的最后）
				{
					if (szReplacement == _T('\t'))					//如果是TAB
					{
						if (m_nChangeTabToSpace == BST_CHECKED)
						{
							for (int k = 0; k < m_nTabSpace; ++k)
							{
								//szOutput += _T("&nbsp;");
								szOutput += _T(' ');
							}
						}
						else
						{
							szOutput += _T('\t');
						}
						//szOutput += _T("&nbsp;&nbsp;&nbsp;&nbsp;");	//转换成四个“&nbsp;”（空格）
					}
					/*
					else if (szReplacement == _T(' '))				//如果是空格
					{
						if (m_nChangeSpaceToNbsp == BST_CHECKED)
						{
							szOutput += _T("&nbsp;");					//转换成“&nbsp;”（UBB）
						}
						else
						{
							szOutput += _T(' ');
						}
					}
					*/
					else
					{
						szOutput += szReplacement;
					}
					if (szFileContent.GetAt(i + 1) == NULL)			//如果注释行没有换行符
					{
						bNeedCRLF = FALSE;
						break;
					}
				}
				if (bNeedCRLF)
				{
					szOutput += _T("[/color]");
					/*
					if (m_nChangeCRLFToBr == BST_CHECKED)
					{
						szOutput += _T("[br]");
					}
					else
					*/
					{
						//szOutput += _T("\r\n");
						szOutput += _T('\r');
					}
					if (m_btnShowLineNum.GetCheck() == 1)			//如果要显示行号
					{
						szReplacement.Format(szFormat, nRowNum++);
						szReplacement.Replace(_T(' '), _T('0'));
						szOutput += _T("[color=") + szColorLineNum + _T("]") + szReplacement + _T("[/color]");
							for (nLineNumIndent = 0; nLineNumIndent < m_nLineNumIndent; nLineNumIndent++)
							{
								//szOutput += _T("&nbsp;");
								szOutput += _T(' ');
							}
						++i;
					}
				}
				else
				{
					szOutput += _T("[/color]");
				}
			}
			else if (IsLetter(szReplacement))						//如果是字符
			{
				while (IsLetter(szFileContent.GetAt(++i)))			//循环读下一个，直到不是字符为止
				{
					szReplacement += szFileContent.GetAt(i);
				}
				for (j = 0; j < m_strarrayKeyword.GetSize(); ++j)	//对比看它是否为关键字
				{
					if (szReplacement.CompareNoCase(m_strarrayKeyword[j]) == 0)		//如果是关键字
					{
						szReplacement = _T("[color=") + szColorKeyword + _T("]") + szReplacement + _T("[/color]");
						break;
					}
				}
				for (j = 0; j < m_strarrayMacro.GetSize(); ++j)		//对比看它是否为宏定义
				{
					if (szReplacement.CompareNoCase(m_strarrayMacro[j]) == 0)		//如果是宏定义
					{
						szReplacement = _T("[color=") + szColorMacro + _T("]") + szReplacement + _T("[/color]");
						break;
					}
				}
				for (j = 0; j < m_strarrayRegister.GetSize(); ++j)	//对比看它是否为寄存器
				{
					if (szReplacement.CompareNoCase(m_strarrayRegister[j]) == 0)		//如果是寄存器
					{
						szReplacement = _T("[color=") + szColorRegister + _T("]") + szReplacement + _T("[/color]");
						break;
					}
				}
				szOutput += szReplacement;
				--i;
			}
			else if (szReplacement == _T('\t'))						//如果是TAB
			{
				if (m_nChangeTabToSpace == BST_CHECKED)
				{
					for (int k = 0; k < m_nTabSpace; ++k)
					{
						//szOutput += _T("&nbsp;");
						szOutput += _T(' ');
					}
				}
				else
				{
					szOutput += _T('\t');
				}
				//szOutput += _T("&nbsp;&nbsp;&nbsp;&nbsp;");			//转换成四个“&nbsp;”（空格）
			}
			/*
			else if (szReplacement == _T(' '))						//如果是空格
			{
				if (m_nChangeSpaceToNbsp == BST_CHECKED)
				{
					szOutput += _T("&nbsp;");							//转换成“&nbsp;”（UBB）
				}
				else
				{
					szOutput += _T(' ');
				}
			}
			*/
			else if ((szReplacement == _T('\"')) && (szFileContent.GetAt(i - 1) != _T('\\')))	//如果是“"”
			{
				szOutput += _T("[color=") + szColorQuotation + _T("]") + szReplacement;
				while ((szReplacement = szFileContent.GetAt(++i)) != _T('\"'))	//直到“"”为止
				{
					if (szReplacement == _T('\t'))					//如果是TAB
					{
						if (m_nChangeTabToSpace == BST_CHECKED)
						{
							for (int k = 0; k < m_nTabSpace; ++k)
							{
								//szOutput += _T("&nbsp;");
								szOutput += _T(' ');
							}
						}
						else
						{
							szOutput += _T('\t');
						}
						//szOutput += _T("&nbsp;&nbsp;&nbsp;&nbsp;");	//转换成四个“&nbsp;”（空格）
					}
					/*
					else if (szReplacement == _T(' '))				//如果是空格
					{
						if (m_nChangeSpaceToNbsp == BST_CHECKED)
						{
							szOutput += _T("&nbsp;");					//转换成“&nbsp;”（UBB）
						}
						else
						{
							szOutput += _T(' ');
						}
					}
					*/
					else if ((szReplacement == _T('\r')) && (szFileContent.GetAt(i + 1) == _T('\n')))	//如果是换行符
					{
						/*
						if (m_nChangeCRLFToBr == BST_CHECKED)
						{
							szOutput += _T("[br]");						//转换成“[br]”（UBB）
						}
						else
						*/
						{
							//szOutput += _T("\r\n");
							szOutput += _T('\r');
						}
						if (m_btnShowLineNum.GetCheck() == 1)		//如果要显示行号
						{
							szReplacement.Format(szFormat, nRowNum++);
							szReplacement.Replace(_T(' '), _T('0'));
							szOutput += _T("[color=") + szColorLineNum + _T("]") + szReplacement + _T("[/color]");
							for (nLineNumIndent = 0; nLineNumIndent < m_nLineNumIndent; nLineNumIndent++)
							{
								//szOutput += _T("&nbsp;");
								szOutput += _T(' ');
							}
							++i;
						}
					}
					else
					{
						szOutput += szReplacement;
					}
				}
				szOutput += szReplacement + _T("[/color]");			//“"”的结束
			}
			else if ((szReplacement == _T('\r')) && (szFileContent.GetAt(i + 1) == _T('\n')))	//如果是换行符
			{
				/*
				if (m_nChangeCRLFToBr == BST_CHECKED)
				{
					szOutput += _T("[br]");
				}
				else
				*/
				{
					//szOutput += _T("\r\n");
					szOutput += _T('\r');
				}
				if (m_btnShowLineNum.GetCheck() == 1)				//如果要显示行号
				{
					szReplacement.Format(szFormat, nRowNum++);
					szReplacement.Replace(_T(' '), _T('0'));
					szOutput += _T("[color=") + szColorLineNum + _T("]") + szReplacement + _T("[/color]");
					for (nLineNumIndent = 0; nLineNumIndent < m_nLineNumIndent; nLineNumIndent++)
					{
						//szOutput += _T("&nbsp;");
						szOutput += _T(' ');
					}
					++i;
				}
			}
			/*
			else if (szReplacement == _T('['))						//如果是“[”
			{
				szOutput += _T("[[");
			}
			else if (szReplacement == _T(']'))						//如果是“]”
			{
				if (szOutput.Right(8) != _T("[/color]"))
				{
					szOutput += _T("]]");
				}
				else
				{
					szOutput += _T(" ]");
				}
			}
			*/
			else		//如果都不满足上面的条件，则直接输出，不进行任何格式转换
			{
				szOutput += szReplacement;
			}
		}
	}

	//输出到文件：
	MakeOutputFile(szOutput);
	//复制到输出框：
	m_edtOutput.SetWindowText(szOutput);
	m_edtOutput.SetFocus();
}

void CSCCDlg::ProcessAsm(CString szFileContent)
{
	//载入关键字和宏：
	LoadKeywordMacro();

	//初始化颜色值：
	//关键字：
	CString szColorKeyword;
	szColorKeyword.Format("#%02X%02X%02X", GetRValue(m_colorKeyword), GetGValue(m_colorKeyword), GetBValue(m_colorKeyword));

	//宏定义：
	CString szColorMacro;
	szColorMacro.Format("#%02X%02X%02X", GetRValue(m_colorMacro), GetGValue(m_colorMacro), GetBValue(m_colorMacro));

	//寄存器：
	CString szColorRegister;
	szColorRegister.Format("#%02X%02X%02X", GetRValue(m_colorRegister), GetGValue(m_colorRegister), GetBValue(m_colorRegister));

	//双引号：
	CString szColorQuotation;
	szColorQuotation.Format("#%02X%02X%02X", GetRValue(m_colorQuotation), GetGValue(m_colorQuotation), GetBValue(m_colorQuotation));

	//注释：
	CString szColorComment;
	szColorComment.Format("#%02X%02X%02X", GetRValue(m_colorComment), GetGValue(m_colorComment), GetBValue(m_colorComment));

	//行号颜色：
	CString szColorLineNum;
	szColorLineNum.Format("#%02X%02X%02X", GetRValue(m_colorLineNum), GetGValue(m_colorLineNum), GetBValue(m_colorLineNum));

	CString szOutput = "";
	CString szReplacement = "";
	BOOL bNeedCRLF = TRUE;
	int i;
	int j;
	int nLineNumIndent;

	/*
	//读入文件内容：
	CFile hFileInput;
	CString szFileContent = "";
	if (!hFileInput.Open(m_strFileNameSource, CFile::modeRead))
	{
		MessageBox("读取 " + m_strFileNameSource + " 文件时出错！", m_strCaption, MB_OK | MB_ICONHAND);
		return ;
	}
	else
	{
		hFileInput.ReadHuge(szFileContent.GetBuffer(hFileInput.GetLength()), hFileInput.GetLength());
		hFileInput.Close();
		//释放缓冲区：
		szFileContent.ReleaseBuffer();
	}
	*/

	int nRowNum = 1;
	CString szFormat;
	if (m_btnShowLineNum.GetCheck() == 1)		//如果要显示行号
	{
		int nPos = -1;
		int nRowCount = 1;
		//统计文件的行数：
		while ((nPos = szFileContent.Find("\r\n", nPos + 1)) != -1)
		{
			nRowCount++;
		}
		szFormat.Format("%d", nRowCount);
		szFormat.Format("%d", szFormat.GetLength());
		szFormat = _T('%') + szFormat + _T("d");
	}

	if (m_btnStyleHTML.GetCheck() == 1)								//如果用HTML标签
	{
		if (m_btnShowLineNum.GetCheck() == 1)						//如果要显示行号
		{
			szReplacement.Format(szFormat, nRowNum++);
			szReplacement.Replace(_T(' '), _T('0'));
			szOutput += _T("<font color=") + szColorLineNum + _T(">") + szReplacement + _T("</font>");
			for (nLineNumIndent = 0; nLineNumIndent < m_nLineNumIndent; nLineNumIndent++)
			{
				szOutput += _T("&nbsp;");
			}
		}
		for (i = 0; i < szFileContent.GetLength(); ++i)				//开始逐个字符进行判断
		{
			szReplacement = szFileContent.GetAt(i);
			if (szReplacement == _T(';'))							//如果是“;”（注释）
			{
				szOutput += _T("<font color=") + szColorComment + _T(">;");
				while (((szReplacement = szFileContent.GetAt(++i)) != _T('\r')) || (szFileContent.GetAt(i + 1) != _T('\n')))	//直到换行符为止（一行的最后）
				{
					if (szReplacement == _T('<'))					//如果是“<”
					{
						szOutput += _T("&lt;");						//转换成“&lt;”（HTML）
					}
					else if (szReplacement == _T('>'))				//如果是“>”
					{
						szOutput += _T("&gt;");						//转换成“&gt;”（HTML）
					}
					else if (szReplacement == _T('\t'))				//如果是TAB
					{
						if (m_nChangeTabToSpace == BST_CHECKED)
						{
							for (int k = 0; k < m_nTabSpace; ++k)
							{
								szOutput += _T("&nbsp;");
							}
						}
						else
						{
							szOutput += _T('\t');
						}
						//szOutput += _T("&nbsp;&nbsp;&nbsp;&nbsp;");	//转换成四个“&nbsp;”（空格）
					}
					else if (szReplacement == _T(' '))					//如果是空格
					{
						if (m_nChangeSpaceToNbsp == BST_CHECKED)
						{
							szOutput += _T("&nbsp;");					//转换成“&nbsp;”（HTML）
						}
						else
						{
							szOutput += _T(' ');
						}
					}
					else
					{
						szOutput += szReplacement;
					}
					if (szFileContent.GetAt(i + 1) == NULL)			//如果注释行没有换行符
					{
						bNeedCRLF = FALSE;
						break;
					}
				}
				if (bNeedCRLF)
				{
					szOutput += _T("</font>");
					if (m_nChangeCRLFToBr == BST_CHECKED)
					{
						szOutput += _T("<br>");
					}
					else
					{
						szOutput += _T("\r\n");
					}
					if (m_btnShowLineNum.GetCheck() == 1)			//如果要显示行号
					{
						szReplacement.Format(szFormat, nRowNum++);
						szReplacement.Replace(_T(' '), _T('0'));
						szOutput += _T("<font color=") + szColorLineNum + _T(">") + szReplacement + _T("</font>");
						for (nLineNumIndent = 0; nLineNumIndent < m_nLineNumIndent; nLineNumIndent++)
						{
							szOutput += _T("&nbsp;");
						}
						++i;
					}
				}
				else
				{
					szOutput += _T("</font>");
				}
			}
			else if (IsLetter(szReplacement))						//如果是字符
			{
				while (IsLetter(szFileContent.GetAt(++i)))			//循环读下一个，直到不是字符为止
				{
					szReplacement += szFileContent.GetAt(i);
				}
				for (j = 0; j < m_strarrayKeyword.GetSize(); ++j)	//对比看它是否为关键字
				{
					if (szReplacement.CompareNoCase(m_strarrayKeyword[j]) == 0)		//如果是关键字
					{
						szReplacement = _T("<font color=") + szColorKeyword + _T(">") + szReplacement + _T("</font>");
						break;
					}
				}
				for (j = 0; j < m_strarrayMacro.GetSize(); ++j)		//对比看它是否为宏定义
				{
					if (szReplacement.CompareNoCase(m_strarrayMacro[j]) == 0)		//如果是宏定义
					{
						szReplacement = _T("<font color=") + szColorMacro + _T(">") + szReplacement + _T("</font>");
						break;
					}
				}
				for (j = 0; j < m_strarrayRegister.GetSize(); ++j)	//对比看它是否为寄存器
				{
					if (szReplacement.CompareNoCase(m_strarrayRegister[j]) == 0)	//如果是寄存器
					{
						szReplacement = _T("<font color=") + szColorRegister + _T(">") + szReplacement + _T("</font>");
						break;
					}
				}
				szOutput += szReplacement;
				--i;
			}
			else if (szReplacement == _T('<'))						//如果是“<”
			{
				szOutput += _T("&lt;");								//转换成“&lt;”（HTML）
			}
			else if (szReplacement == _T('>'))						//如果是“>”
			{
				szOutput += _T("&gt;");								//转换成“&gt;”（HTML）
			}
			else if (szReplacement == _T('\t'))						//如果是TAB
			{
				if (m_nChangeTabToSpace == BST_CHECKED)
				{
					for (int k = 0; k < m_nTabSpace; ++k)
					{
						szOutput += _T("&nbsp;");
					}
				}
				else
				{
					szOutput += _T('\t');
				}
				//szOutput += _T("&nbsp;&nbsp;&nbsp;&nbsp;");			//转换成四个“&nbsp;”（空格）
			}
			else if (szReplacement == _T(' '))							//如果是空格
			{
				if (m_nChangeSpaceToNbsp == BST_CHECKED)
				{
					szOutput += _T("&nbsp;");							//转换成“&nbsp;”（HTML）
				}
				else
				{
					szOutput += _T(' ');
				}
			}
			else if ((szReplacement == _T('\"')) && (szFileContent.GetAt(i - 1) != _T('\\')))	//如果是“"”
			{
				szOutput += _T("<font color=") + szColorQuotation + _T(">&quot;");// + szReplacement;
				while ((szReplacement = szFileContent.GetAt(++i)) != _T('\"'))					//直到“"”为止
				{
					if (szReplacement == _T('<'))					//如果是“<”
					{
						szOutput += _T("&lt;");						//转换成“&lt;”（HTML）
					}
					else if (szReplacement == _T('>'))				//如果是“>”
					{
						szOutput += _T("&gt;");						//转换成“&gt;”（HTML）
					}
					else if (szReplacement == _T('\t'))				//如果是TAB
					{
						if (m_nChangeTabToSpace == BST_CHECKED)
						{
							for (int k = 0; k < m_nTabSpace; ++k)
							{
								szOutput += _T("&nbsp;");
							}
						}
						else
						{
							szOutput += _T('\t');
						}
						//szOutput += _T("&nbsp;&nbsp;&nbsp;&nbsp;");	//转换成四个“&nbsp;”（空格）
					}
					else if (szReplacement == _T(' '))				//如果是空格
					{
						if (m_nChangeSpaceToNbsp == BST_CHECKED)
						{
							szOutput += _T("&nbsp;");					//转换成“&nbsp;”（HTML）
						}
						else
						{
							szOutput += _T(' ');
						}
					}
					else if ((szReplacement == _T('\r')) && (szFileContent.GetAt(i + 1) == _T('\n')))	//如果是换行符
					{
						if (m_nChangeCRLFToBr == BST_CHECKED)
						{
							szOutput += _T("<br>");						//转换成“<br>”（HTML）
						}
						else
						{
							szOutput += _T("\r\n");
						}
						if (m_btnShowLineNum.GetCheck() == 1)		//如果要显示行号
						{
							szReplacement.Format(szFormat, nRowNum++);
							szReplacement.Replace(_T(' '), _T('0'));
							szOutput += _T("<font color=") + szColorLineNum + _T(">") + szReplacement + _T("</font>");
							for (nLineNumIndent = 0; nLineNumIndent < m_nLineNumIndent; nLineNumIndent++)
							{
								szOutput += _T("&nbsp;");
							}
							++i;
						}
					}
					else
					{
						szOutput += szReplacement;
					}
				}
				//szOutput += szReplacement + _T("</font>");			//“"”的结束
				szOutput += _T("&quot;</font>");
			}
			else if ((szReplacement == _T('\r')) && (szFileContent.GetAt(i + 1) == _T('\n')))	//如果是换行符
			{
				if (m_nChangeCRLFToBr == BST_CHECKED)
				{
					szOutput += _T("<br>");								//转换成“<br>”
				}
				else
				{
					szOutput += _T("\r\n");
				}
				if (m_btnShowLineNum.GetCheck() == 1)				//如果要显示行号
				{
					szReplacement.Format(szFormat, nRowNum++);
					szReplacement.Replace(_T(' '), _T('0'));
					szOutput += _T("<font color=") + szColorLineNum + _T(">") + szReplacement + _T("</font>");
					for (nLineNumIndent = 0; nLineNumIndent < m_nLineNumIndent; nLineNumIndent++)
					{
						szOutput += _T("&nbsp;");
					}
					++i;
				}
			}
			else		//如果都不满足上面的条件，则直接输出，不进行任何格式转换
			{
				szOutput += szReplacement;
			}
		}
	}
	else if (m_btnStyleUBB.GetCheck() == 1)							//如果用UBB标签
	{
		if (m_btnShowLineNum.GetCheck() == 1)						//如果要显示行号
		{
			szReplacement.Format(szFormat, nRowNum++);
			szReplacement.Replace(_T(' '), _T('0'));
			szOutput += _T("[color=") + szColorLineNum + _T("]") + szReplacement + _T("[/color]");
			for (nLineNumIndent = 0; nLineNumIndent < m_nLineNumIndent; nLineNumIndent++)
			{
				//szOutput += _T("&nbsp;");
				szOutput += _T(' ');
			}
		}
		for (i = 0; i < szFileContent.GetLength(); ++i)				//开始逐个字符进行判断
		{
			szReplacement = szFileContent.GetAt(i);
			if (szReplacement == _T(';'))							//如果是“;”（注释）
			{
				szOutput += _T("[color=") + szColorComment + _T("]") + szReplacement;
				while (((szReplacement = szFileContent.GetAt(++i)) != _T('\r')) || (szFileContent.GetAt(i + 1) != _T('\n')))	//直到换行符为止（一行的最后）
				{
					if (szReplacement == _T('\t'))					//如果是TAB
					{
						if (m_nChangeTabToSpace == BST_CHECKED)
						{
							for (int k = 0; k < m_nTabSpace; ++k)
							{
								szOutput += _T(' ');
							}
						}
						else
						{
							szOutput += _T('\t');
						}
						//szOutput += _T("&nbsp;&nbsp;&nbsp;&nbsp;");	//转换成四个“&nbsp;”（空格）
					}
					/*
					else if (szReplacement == _T(' '))				//如果是空格
					{
						if (m_nChangeSpaceToNbsp == BST_CHECKED)
						{
							szOutput += _T("&nbsp;");					//转换成“&nbsp;”（UBB）
						}
						else
						{
							szOutput += _T(' ');
						}
					}
					*/
					else
					{
						szOutput += szReplacement;
					}
					if (szFileContent.GetAt(i + 1) == NULL)			//如果注释行没有换行符
					{
						bNeedCRLF = FALSE;
						break;
					}
				}
				if (bNeedCRLF)
				{
					szOutput += _T("[/color]");
					/*
					if (m_nChangeCRLFToBr == BST_CHECKED)
					{
						szOutput += _T("[br]");
					}
					else
					*/
					{
						//szOutput += _T("\r\n");
						szOutput += _T('\r');
					}
					if (m_btnShowLineNum.GetCheck() == 1)			//如果要显示行号
					{
						szReplacement.Format(szFormat, nRowNum++);
						szReplacement.Replace(_T(' '), _T('0'));
						szOutput += _T("[color=") + szColorLineNum + _T("]") + szReplacement + _T("[/color]");
						for (nLineNumIndent = 0; nLineNumIndent < m_nLineNumIndent; nLineNumIndent++)
						{
							//szOutput += _T("&nbsp;");
							szOutput += _T(' ');
						}
						++i;
					}
				}
				else
				{
					szOutput += _T("[/color]");
				}
			}
			else if (IsLetter(szReplacement))						//如果是字符
			{
				while (IsLetter(szFileContent.GetAt(++i)))			//循环读下一个，直到不是字符为止
				{
					szReplacement += szFileContent.GetAt(i);
				}
				for (j = 0; j < m_strarrayKeyword.GetSize(); ++j)	//对比看它是否为关键字
				{
					if (szReplacement.CompareNoCase(m_strarrayKeyword[j]) == 0)		//如果是关键字
					{
						szReplacement = _T("[color=") + szColorKeyword + _T("]") + szReplacement + _T("[/color]");
						break;
					}
				}
				for (j = 0; j < m_strarrayMacro.GetSize(); ++j)		//对比看它是否为宏定义
				{
					if (szReplacement.CompareNoCase(m_strarrayMacro[j]) == 0)		//如果是宏定义
					{
						szReplacement = _T("[color=") + szColorMacro + _T("]") + szReplacement + _T("[/color]");
						break;
					}
				}
				for (j = 0; j < m_strarrayRegister.GetSize(); ++j)	//对比看它是否为寄存器
				{
					if (szReplacement.CompareNoCase(m_strarrayRegister[j]) == 0)		//如果是寄存器
					{
						szReplacement = _T("[color=") + szColorRegister + _T("]") + szReplacement + _T("[/color]");
						break;
					}
				}
				szOutput += szReplacement;
				--i;
			}
			else if (szReplacement == _T('\t'))						//如果是TAB
			{
				if (m_nChangeTabToSpace == BST_CHECKED)
				{
					for (int k = 0; k < m_nTabSpace; ++k)
					{
						//szOutput += _T("&nbsp;");
						szOutput += _T(' ');
					}
				}
				else
				{
					szOutput += _T('\t');
				}
				//szOutput += _T("&nbsp;&nbsp;&nbsp;&nbsp;");			//转换成四个“&nbsp;”（空格）
			}
			/*
			else if (szReplacement == _T(' '))						//如果是空格
			{
				if (m_nChangeSpaceToNbsp == BST_CHECKED)
				{
					szOutput += _T("&nbsp;");							//转换成“&nbsp;”（UBB）
				}
				else
				{
					szOutput += _T(' ');
				}
			}
			*/
			else if ((szReplacement == _T('\"')) && (szFileContent.GetAt(i - 1) != _T('\\')))	//如果是“"”
			{
				szOutput += _T("[color=") + szColorQuotation + _T("]") + szReplacement;
				while ((szReplacement = szFileContent.GetAt(++i)) != _T('\"'))	//直到“"”为止
				{
					if (szReplacement == _T('\t'))					//如果是TAB
					{
						if (m_nChangeTabToSpace == BST_CHECKED)
						{
							for (int k = 0; k < m_nTabSpace; ++k)
							{
								//szOutput += _T("&nbsp;");
								szOutput += _T(' ');
							}
						}
						else
						{
							szOutput += _T('\t');
						}
						//szOutput += _T("&nbsp;&nbsp;&nbsp;&nbsp;");	//转换成四个“&nbsp;”（空格）
					}
					/*
					else if (szReplacement == _T(' '))				//如果是空格
					{
						if (m_nChangeSpaceToNbsp == BST_CHECKED)
						{
							szOutput += _T("&nbsp;");					//转换成“&nbsp;”（UBB）
						}
						else
						{
							szOutput += _T(' ');
						}
					}
					*/
					else if ((szReplacement == _T('\r')) && (szFileContent.GetAt(i + 1) == _T('\n')))	//如果是换行符
					{
						/*
						if (m_nChangeCRLFToBr == BST_CHECKED)
						{
							szOutput += _T("[br]");						//转换成“[br]”（UBB）
						}
						else
						*/
						{
							//szOutput += _T("\r\n");
							szOutput += _T('\r');
						}
						if (m_btnShowLineNum.GetCheck() == 1)		//如果要显示行号
						{
							szReplacement.Format(szFormat, nRowNum++);
							szReplacement.Replace(_T(' '), _T('0'));
							szOutput += _T("[color=") + szColorLineNum + _T("]") + szReplacement + _T("[/color]");
							for (nLineNumIndent = 0; nLineNumIndent < m_nLineNumIndent; nLineNumIndent++)
							{
								//szOutput += _T("&nbsp;");
								szOutput += _T(' ');
							}
							++i;
						}
					}
					else
					{
						szOutput += szReplacement;
					}
				}
				szOutput += szReplacement + _T("[/color]");			//“"”的结束
			}
			else if ((szReplacement == _T('\r')) && (szFileContent.GetAt(i + 1) == _T('\n')))	//如果是换行符
			{
				/*
				if (m_nChangeCRLFToBr == BST_CHECKED)
				{
					szOutput += _T("[br]");
				}
				else
				*/
				{
					//szOutput += _T("\r\n");
					szOutput += _T('\r');
				}
				if (m_btnShowLineNum.GetCheck() == 1)				//如果要显示行号
				{
					szReplacement.Format(szFormat, nRowNum++);
					szReplacement.Replace(_T(' '), _T('0'));
					szOutput += _T("[color=") + szColorLineNum + _T("]") + szReplacement + _T("[/color]");
					for (nLineNumIndent = 0; nLineNumIndent < m_nLineNumIndent; nLineNumIndent++)
					{
						//szOutput += _T("&nbsp;");
						szOutput += _T(' ');
					}
					++i;
				}
			}
			/*
			else if (szReplacement == _T('['))						//如果是“[”
			{
				szOutput += _T("[[");
			}
			else if (szReplacement == _T(']'))						//如果是“]”
			{
				if (szOutput.Right(8) != _T("[/color]"))
				{
					szOutput += _T("]]");
				}
				else
				{
					szOutput += _T(" ]");
				}
			}
			*/
			else		//如果都不满足上面的条件，则直接输出，不进行任何格式转换
			{
				szOutput += szReplacement;
			}
		}
	}

	//输出到文件：
	MakeOutputFile(szOutput);
	//复制到输出框：
	m_edtOutput.SetWindowText(szOutput);
	m_edtOutput.SetFocus();
}

void CSCCDlg::OnButtonProcess() 
{
	// TODO: Add your control notification handler code here

	CString szFileContent = "";

	//如果是“通过文件转换”：
	if (m_btnConvertByFile.GetCheck() == 1)
	{
		m_edtFileSource.GetWindowText(m_strFileNameSource);
		m_strFileNameSource.TrimLeft();
		m_strFileNameSource.TrimRight();
		if (m_strFileNameSource == _T(""))
		{
			MessageBox("您忘啦？请先选择源文件！", m_strCaption, MB_OK | MB_ICONINFORMATION);
			return ;
		}

		//判断文件类型：
		m_strFileExt = m_strFileNameSource;
		m_strFileExt = m_strFileExt.Right(m_strFileExt.GetLength() - m_strFileExt.ReverseFind('.') - 1);

		//读入文件内容：
		CFile hFileInput;
		if (!hFileInput.Open(m_strFileNameSource, CFile::modeRead))
		{
			MessageBox("读取 " + m_strFileNameSource + " 文件时出错！", m_strCaption, MB_OK | MB_ICONHAND);
			return ;
		}
		else
		{
			hFileInput.ReadHuge(szFileContent.GetBuffer(hFileInput.GetLength()), hFileInput.GetLength());
			hFileInput.Close();
			//释放缓冲区：
			szFileContent.ReleaseBuffer();
		}

		//如果是C/C++文件：
		if ((m_strFileExt.CompareNoCase(_T("c")) == 0) || (m_strFileExt.CompareNoCase(_T("cpp")) == 0))
		{
			ProcessCpp(szFileContent);
		}
		//如果是Asm文件：
		else if (m_strFileExt.CompareNoCase(_T("asm")) == 0)
		{
			ProcessAsm(szFileContent);
		}
		else
		{
			MessageBox("很抱歉！本软件的目前版本不支持 *." + m_strFileExt + " 的文件！", m_strCaption, MB_OK | MB_ICONINFORMATION);
		}
	}
	//如果是“直接转换”：
	else
	{
		//构造“文件类型”：
		m_edtOutput.GetWindowText(szFileContent);
		switch (m_comboDirectConvertStx.GetCurSel())
		{
		//ASM:
		case 0:
			m_strFileExt = _T("asm");
			ProcessAsm(szFileContent);
			break;
		//C++:
		case 1:
			m_strFileExt = _T("cpp");
			ProcessCpp(szFileContent);
			break;
		//C:
		case 2:
			m_strFileExt = _T("c");
			ProcessCpp(szFileContent);
			break;
		}

	}

}

void CSCCDlg::OnButtonBrowse() 
{
	// TODO: Add your control notification handler code here

	//初始化 OPENFILENAME 变量：
	OPENFILENAME ofn;
	TCHAR szFileName[MAX_PATH];
	ZeroMemory(&ofn, sizeof(OPENFILENAME));
	ZeroMemory(szFileName, MAX_PATH);
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = m_hWnd;
	ofn.lpstrFilter = "C/C++ Files (*.cpp *.c)\0Asm Files (*.asm)\0*.asm\0*.cpp;*.c\0All Files (*.*)\0*.*\0";
	ofn.lpstrFile = szFileName;
	ofn.nMaxFile = MAX_PATH;
	ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_LONGNAMES | OFN_EXPLORER;

	//“打开”对话框：
	if (GetOpenFileName(&ofn))
	{
		//定制输入输出文件名：
		MakeInputOutputFileName(szFileName);
	}
}

/********************************************
//函数名：IsLetter
//作用：检查字符是否为字母
//参数说明：ch 待检查的字符
********************************************/
bool CSCCDlg::IsLetter(CString ch)
{
	return ((ch >= 0x41 && ch <= 0x5a) || (ch >= 0x61 && ch <= 0x7a) || (ch == _T('#')) || (ch == _T('.')) || (ch == _T('?')) || (ch == _T('_')) || (ch >= 0x30 && ch <= 0x39)) ? true : false;
}

void CSCCDlg::OnButtonAbout() 
{
	// TODO: Add your control notification handler code here
	CAboutDlg dlg;
	dlg.DoModal();
}

BOOL CAboutDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	short shBtnColor = 30;

	// Set HyperLink for E-Mail
	m_staEMail.SetURL(_T("mailto:lcother@163.net"));
	m_staEMail.SetUnderline(CHyperLink::ulAlways);

	// Set HyperLink for Home Page
	m_staHomePage.SetURL(_T("http://www.LuoCong.com"));
	m_staHomePage.SetUnderline(CHyperLink::ulAlways);

	m_btnOK.SetTooltipText(_T("看完啦！"), TRUE);
	m_btnOK.SetIcon(IDI_ICON_ABOUTDLG_OK);
	m_btnOK.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, shBtnColor);
	m_btnOK.SetRounded(TRUE);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSCCDlg::OnButtonExecute() 
{
	// TODO: Add your control notification handler code here
	CString szFileNameDestination;
	m_edtFileDestination.GetWindowText(szFileNameDestination);
	szFileNameDestination.TrimLeft();
	szFileNameDestination.TrimRight();
	if (szFileNameDestination.GetLength() == 0)
	{
		MessageBox(_T("您忘啦？请先指定输出文件！"), m_strCaption, MB_OK | MB_ICONINFORMATION);
	}
	else
	{
		if ((long)ShellExecute(m_hWnd, _T("open"), szFileNameDestination, NULL, NULL, SW_SHOWNORMAL) == SE_ERR_FNF)
		{
			MessageBox(_T("很抱歉，输出文件不存在！"), m_strCaption, MB_OK | MB_ICONINFORMATION);
		}
	}
}

void CSCCDlg::MakeOutputFile(CString szBody)
{
	if (m_btnStyleUBB.GetCheck() == 1)
	{
		MessageBox(_T("转换成功！"), m_strCaption, MB_OK | MB_ICONINFORMATION);
		return ;
	}

	if (m_btnConvertByFile.GetCheck() == 0)
	{
		MessageBox(_T("转换成功！"), m_strCaption, MB_OK | MB_ICONINFORMATION);
		return ;
	}

	CString szOutput;

	//得到输出文件名：
	m_edtFileDestination.GetWindowText(m_strFileNameDestination);

	//构造文件内容：
	szOutput = _T("<html>\r\n");
	szOutput += _T("<title>");
	szOutput += _T("老罗代码着色器 www.LuoCong.com - [") + m_strFileNameDestination + _T("]</title>\r\n");
	szOutput += _T("<meta http-equiv=\"Content-Type\" content=\"text/html; charset=gb2312\">\r\n");
	szOutput += _T("<body>\r\n");
	szOutput += szBody + _T("\r\n");
	szOutput += _T("</body>\r\n</html>");

	//写输出文件：
	CFile hFileOutput;

	if (!hFileOutput.Open(m_strFileNameDestination, CFile::modeCreate | CFile::modeWrite))
	{
		MessageBox(_T("创建 ") + m_strFileNameDestination + _T(" 文件时出错！"), m_strCaption, MB_OK | MB_ICONHAND);
	}
	else
	{
		hFileOutput.WriteHuge(szOutput.GetBuffer(szOutput.GetLength()), szOutput.GetLength());
		szOutput.ReleaseBuffer();
		MessageBox(_T("输出文件 ") + m_strFileNameDestination + _T(" 成功！"), m_strCaption, MB_OK | MB_ICONINFORMATION);
		hFileOutput.Close();
	}
}

void CSCCDlg::OnButtonConfig() 
{
	// TODO: Add your control notification handler code here
	CConfigDlg dlg;
	dlg.m_pSCCDlg = this;
	if (dlg.DoModal() != IDOK)
		return ;
}

BOOL CSCCDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class

	//拖放操作：
	if (pMsg->message == WM_DROPFILES)
	{
		char lpszFile[MAX_PATH];
		DragQueryFile((HDROP)pMsg->wParam, 0, lpszFile, sizeof(lpszFile));
		//定制输入输出文件名：
		MakeInputOutputFileName(lpszFile);
		DragFinish((HDROP)pMsg->wParam);
	}
	return CDialog::PreTranslateMessage(pMsg);
}

void CSCCDlg::MakeInputOutputFileName(CString szFileName)
{
	//把文件名复制到 IDC_EDIT_FILE_SOURCE 中：
	m_edtFileSource.SetWindowText(szFileName);

	//给文件名添加一个"*.htm"后缀，并复制到 IDC_EDIT_FILE_DESTINATION 中：
	CString szTemp;
	szTemp = szFileName;
	szTemp += ".htm";
	m_edtFileDestination.SetWindowText(szTemp);
}

void CSCCDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	CString szStr;

	//写入颜色值到ini文件中：
	//关键字：
	//szStr.Format("%02X%02X%02X", GetRValue(m_colorKeyword), GetGValue(m_colorKeyword), GetBValue(m_colorKeyword));
	//m_colorKeyword = RGB(1, 2, 3);
	szStr.Format("%06X", m_colorKeyword);
	WritePrivateProfileString(_T("COLORS"), _T("Keyword"), szStr, m_strIniFile);

	//宏定义：
	//szStr.Format("%02X%02X%02X", GetRValue(m_colorMacro), GetGValue(m_colorMacro), GetBValue(m_colorMacro));
	szStr.Format("%06X", m_colorMacro);
	WritePrivateProfileString(_T("COLORS"), _T("Macro"), szStr, m_strIniFile);

	//寄存器：
	//szStr.Format("%02X%02X%02X", GetRValue(m_colorRegister), GetGValue(m_colorRegister), GetBValue(m_colorRegister));
	szStr.Format("%06X", m_colorRegister);
	WritePrivateProfileString(_T("COLORS"), _T("Register"), szStr, m_strIniFile);

	//双引号：
	//szStr.Format("%02X%02X%02X", GetRValue(m_colorQuotation), GetGValue(m_colorQuotation), GetBValue(m_colorQuotation));
	szStr.Format("%06X", m_colorQuotation);
	WritePrivateProfileString(_T("COLORS"), _T("Quotation"), szStr, m_strIniFile);

	//注释：
	//szStr.Format("%02X%02X%02X", GetRValue(m_colorComment), GetGValue(m_colorComment), GetBValue(m_colorComment));
	szStr.Format("%06X", m_colorComment);
	WritePrivateProfileString(_T("COLORS"), _T("Comment"), szStr, m_strIniFile);

	//行号：
	//szStr.Format("%02X%02X%02X", GetRValue(m_colorLineNum), GetGValue(m_colorLineNum), GetBValue(m_colorLineNum));
	szStr.Format("%06X", m_colorLineNum);
	WritePrivateProfileString(_T("COLORS"), _T("LineNum"), szStr, m_strIniFile);

	//将TAB转换成空格：
	szStr.Format("%d", m_nChangeTabToSpace);
	WritePrivateProfileString(_T("MISC"), _T("Change_Tab_To_Space"), szStr, m_strIniFile);

	//将空格转换成&nbsp：
	szStr.Format("%d", m_nChangeSpaceToNbsp);
	WritePrivateProfileString(_T("MISC"), _T("Change_Space_To_Nbsp"), szStr, m_strIniFile);

	//将回车转换成<br>：
	szStr.Format("%d", m_nChangeCRLFToBr);
	WritePrivateProfileString(_T("MISC"), _T("Change_CRLF_To_Br"), szStr, m_strIniFile);

	//TAB_SPACE：
	szStr.Format("%d", m_nTabSpace);
	WritePrivateProfileString(_T("MISC"), _T("TAB_SPACE"), szStr, m_strIniFile);

	//行号后的空格数：
	szStr.Format("%d", m_nLineNumIndent);
	WritePrivateProfileString(_T("MISC"), _T("LINE_NUM_INDENT"), szStr, m_strIniFile);
}

void CSCCDlg::OnRadioStyleUbb() 
{
	// TODO: Add your control notification handler code here
	//使控件失效：
	m_edtFileDestination.EnableWindow(FALSE);
	m_btnExecute.EnableWindow(FALSE);
}

void CSCCDlg::OnRadioStyleHtml() 
{
	// TODO: Add your control notification handler code here
	//如果“通过文件转换”：
	if (m_btnConvertByFile.GetCheck() == 1)
	{
		//使控件有效：
		m_edtFileDestination.EnableWindow(TRUE);
		m_btnExecute.EnableWindow(TRUE);
	}
}

void CSCCDlg::OnRadioConvertDirect() 
{
	// TODO: Add your control notification handler code here
	//使某些控件有效：
	m_comboDirectConvertStx.EnableWindow(TRUE);
	//使某些控件无效：
	m_edtFileSource.EnableWindow(FALSE);
	m_edtFileDestination.EnableWindow(FALSE);
	m_btnBrowse.EnableWindow(FALSE);
	m_btnExecute.EnableWindow(FALSE);
	m_edtOutput.SetWindowText(_T("请在这里粘贴入要转换的内容。\r\n并在“类型”处选择源代码的类型。\r\n当转换完成后，内容会在这里显示。"));
	m_edtOutput.SetFocus();
}

void CSCCDlg::OnRadioConvertByFile() 
{
	// TODO: Add your control notification handler code here
	//使某些控件无效：
	m_comboDirectConvertStx.EnableWindow(FALSE);
	//使某些控件有效：
	m_edtFileSource.EnableWindow(TRUE);
	if (m_btnStyleUBB.GetCheck() == 0)
	{
		m_edtFileDestination.EnableWindow(TRUE);
		m_btnExecute.EnableWindow(TRUE);
	}
	m_btnBrowse.EnableWindow(TRUE);
	m_edtOutput.SetWindowText(_T(""));
}

void CSCCDlg::OnSetfocusEditOutput() 
{
	// TODO: Add your control notification handler code here
	//一旦Focus就全选：
	m_edtOutput.SetSel(0, -1);
}

void CSCCDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	//淡出显示对话框：
	AnimateWindow(m_hWnd, 200, AW_BLEND | AW_HIDE);
	
	CDialog::OnClose();
}
