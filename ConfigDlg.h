#if !defined(AFX_CONFIGDLG_H__F9392752_F2BC_4BE8_B712_384FCF0A37CC__INCLUDED_)
#define AFX_CONFIGDLG_H__F9392752_F2BC_4BE8_B712_384FCF0A37CC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ConfigDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CConfigDlg dialog

#include "BtnST.h"
#include "SCCDlg.h"

class CSCCDlg;

class CConfigDlg : public CDialog
{
// Construction
public:
	CConfigDlg(CWnd* pParent = NULL);   // standard constructor

	//主对话框：
	CSCCDlg *m_pSCCDlg;

	//设置颜色按钮的颜色：
	void SetColorButtons();

	//颜色：
	COLORREF m_colorKeyword;
	COLORREF m_colorMacro;
	COLORREF m_colorRegister;
	COLORREF m_colorQuotation;
	COLORREF m_colorComment;
	COLORREF m_colorLineNum;

// Dialog Data
	//{{AFX_DATA(CConfigDlg)
	enum { IDD = IDD_DIALOG_CONFIG };
	CButton	m_checkboxChangeCRLFToBr;
	CButton	m_checkboxChangeTabToSpace;
	CButton	m_checkboxChangeSpaceToNbsp;
	CSpinButtonCtrl	m_spinTabSpace;
	CEdit	m_edtTabSpace;
	CButtonST	m_btnColorQuotation;
	CEdit	m_edtColorQuotation;
	CButtonST	m_btnColorQuote;
	CButtonST	m_btnOK;
	CButtonST	m_btnCancel;
	CButtonST	m_btnUseDefault;
	CSpinButtonCtrl	m_spinLineNumIndent;
	CEdit	m_edtLineNumIndent;
	CEdit	m_edtColorLineNum;
	CButtonST	m_btnColorLineNum;
	CEdit	m_edtColorComment;
	CButtonST	m_btnColorComment;
	CEdit	m_edtColorRegister;
	CEdit	m_edtColorMacro;
	CEdit	m_edtColorKeyword;
	CButtonST	m_btnColorRegister;
	CButtonST	m_btnColorMacro;
	CButtonST	m_btnColorKeyword;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CConfigDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CConfigDlg)
	afx_msg void OnButtonColorKeyword();
	afx_msg void OnButtonColorMacro();
	afx_msg void OnButtonColorRegister();
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonColorComment();
	afx_msg void OnButtonColorLinenum();
	virtual void OnOK();
	afx_msg void OnButtonUseDefault();
	afx_msg void OnButtonColorQuotation();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONFIGDLG_H__F9392752_F2BC_4BE8_B712_384FCF0A37CC__INCLUDED_)
