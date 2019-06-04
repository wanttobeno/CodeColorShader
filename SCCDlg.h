// SCCDlg.h : header file
//

#if !defined(AFX_SCCDLG_H__DA04BC0B_7D07_4C28_8864_97098E217857__INCLUDED_)
#define AFX_SCCDLG_H__DA04BC0B_7D07_4C28_8864_97098E217857__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "BtnST.h"
#include "WinXPButtonST.h"
#include "HyperLink.h"

/////////////////////////////////////////////////////////////////////////////
// CSCCDlg dialog

class CSCCDlg : public CDialog
{
// Construction
public:
	CSCCDlg(CWnd* pParent = NULL);	// standard constructor

	void ProcessCpp(CString szFileContent);
	void ProcessAsm(CString szFileContent);
	void LoadKeywordMacro();
	bool IsLetter(CString ch);
	void MakeOutputFile(CString szBody);
	void MakeInputOutputFileName(CString szFileName);
	float DecToHex(CString szInput);

	CString m_strIniFile;
	CString m_strFileNameSource;
	CString m_strFileNameDestination;
	CString m_strFileExt;
	CString m_strCaption;

	//关键字表、宏表定义和寄存器定义：
	CStringArray m_strarrayKeyword;
	CStringArray m_strarrayMacro;
	CStringArray m_strarrayRegister;

	//颜色定义：
	COLORREF m_colorKeyword;
	COLORREF m_colorMacro;
	COLORREF m_colorRegister;
	COLORREF m_colorQuotation;
	COLORREF m_colorComment;
	COLORREF m_colorLineNum;

	//将TAB转换成空格：
	int m_nChangeTabToSpace;

	//将空格转换成&nbsp：
	int m_nChangeSpaceToNbsp;

	//将回车转换成<br>：
	int m_nChangeCRLFToBr;

	//TAB所占的空格数：
	int m_nTabSpace;

	//行号后的空格数：
	int m_nLineNumIndent;

// Dialog Data
	//{{AFX_DATA(CSCCDlg)
	enum { IDD = IDD_SCC_DIALOG };
	CComboBox	m_comboDirectConvertStx;
	CButton	m_btnConvertByFile;
	CButtonST	m_btnConfig;
	CWinXPButtonST	m_btnExecute;
	CWinXPButtonST	m_btnAbout;
	CWinXPButtonST	m_btnBrowse;
	CWinXPButtonST	m_btnProcess;
	CEdit	m_edtOutput;
	CEdit	m_edtFileSource;
	CButtonST	m_btnShowLineNum;
	CButton	m_btnStyleUBB;
	CButton	m_btnStyleHTML;
	CEdit	m_edtFileDestination;
	CEdit	m_edtlFileSource;
	CEdit	m_edtlOutput;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSCCDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSCCDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonProcess();
	afx_msg void OnButtonBrowse();
	afx_msg void OnButtonAbout();
	afx_msg void OnButtonExecute();
	afx_msg void OnButtonConfig();
	afx_msg void OnDestroy();
	afx_msg void OnRadioStyleUbb();
	afx_msg void OnRadioStyleHtml();
	afx_msg void OnRadioConvertDirect();
	afx_msg void OnRadioConvertByFile();
	afx_msg void OnSetfocusEditOutput();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCCDLG_H__DA04BC0B_7D07_4C28_8864_97098E217857__INCLUDED_)
