// ConfigDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SCC.h"
#include "ConfigDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CConfigDlg dialog


CConfigDlg::CConfigDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CConfigDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CConfigDlg)
	//}}AFX_DATA_INIT
}


void CConfigDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CConfigDlg)
	DDX_Control(pDX, IDC_CHECK_CHANGECRLFTOBR, m_checkboxChangeCRLFToBr);
	DDX_Control(pDX, IDC_CHECK_CHANGETABTOSPACE, m_checkboxChangeTabToSpace);
	DDX_Control(pDX, IDC_CHECK_CHANGESPACETONBSP, m_checkboxChangeSpaceToNbsp);
	DDX_Control(pDX, IDC_SPIN_TAB_SPACE, m_spinTabSpace);
	DDX_Control(pDX, IDC_EDIT_TAB_SPACE, m_edtTabSpace);
	DDX_Control(pDX, IDC_BUTTON_COLOR_QUOTATION, m_btnColorQuotation);
	DDX_Control(pDX, IDC_EDIT_COLOR_QUOTATION, m_edtColorQuotation);
	DDX_Control(pDX, IDOK, m_btnOK);
	DDX_Control(pDX, IDCANCEL, m_btnCancel);
	DDX_Control(pDX, IDC_BUTTON_USE_DEFAULT, m_btnUseDefault);
	DDX_Control(pDX, IDC_SPIN_LINENUM_INDENT, m_spinLineNumIndent);
	DDX_Control(pDX, IDC_EDIT_LINENUM_INDENT, m_edtLineNumIndent);
	DDX_Control(pDX, IDC_EDIT_COLOR_LINENUM, m_edtColorLineNum);
	DDX_Control(pDX, IDC_BUTTON_COLOR_LINENUM, m_btnColorLineNum);
	DDX_Control(pDX, IDC_EDIT_COLOR_COMMENT, m_edtColorComment);
	DDX_Control(pDX, IDC_BUTTON_COLOR_COMMENT, m_btnColorComment);
	DDX_Control(pDX, IDC_EDIT_COLOR_REGISTER, m_edtColorRegister);
	DDX_Control(pDX, IDC_EDIT_COLOR_MACRO, m_edtColorMacro);
	DDX_Control(pDX, IDC_EDIT_COLOR_KEYWORD, m_edtColorKeyword);
	DDX_Control(pDX, IDC_BUTTON_COLOR_REGISTER, m_btnColorRegister);
	DDX_Control(pDX, IDC_BUTTON_COLOR_MACRO, m_btnColorMacro);
	DDX_Control(pDX, IDC_BUTTON_COLOR_KEYWORD, m_btnColorKeyword);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CConfigDlg, CDialog)
	//{{AFX_MSG_MAP(CConfigDlg)
	ON_BN_CLICKED(IDC_BUTTON_COLOR_KEYWORD, OnButtonColorKeyword)
	ON_BN_CLICKED(IDC_BUTTON_COLOR_MACRO, OnButtonColorMacro)
	ON_BN_CLICKED(IDC_BUTTON_COLOR_REGISTER, OnButtonColorRegister)
	ON_BN_CLICKED(IDC_BUTTON_COLOR_COMMENT, OnButtonColorComment)
	ON_BN_CLICKED(IDC_BUTTON_COLOR_LINENUM, OnButtonColorLinenum)
	ON_BN_CLICKED(IDC_BUTTON_USE_DEFAULT, OnButtonUseDefault)
	ON_BN_CLICKED(IDC_BUTTON_COLOR_QUOTATION, OnButtonColorQuotation)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CConfigDlg message handlers

void CConfigDlg::OnButtonColorKeyword() 
{
	// TODO: Add your control notification handler code here
	CColorDialog dlg;
	dlg.m_cc.Flags |= CC_FULLOPEN | CC_RGBINIT;
	dlg.m_cc.rgbResult = m_colorKeyword;
	if (dlg.DoModal() == IDOK)
	{
		m_colorKeyword = dlg.GetColor();
		m_btnColorKeyword.SetColor(CButtonST::BTNST_COLOR_BK_IN, m_colorKeyword);
		m_btnColorKeyword.SetColor(CButtonST::BTNST_COLOR_BK_OUT, m_colorKeyword);
		m_btnColorKeyword.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, m_colorKeyword);
		CString szColor;
		szColor.Format("#%02X%02X%02X", GetRValue(m_colorKeyword), GetGValue(m_colorKeyword), GetBValue(m_colorKeyword));
		m_edtColorKeyword.SetWindowText(szColor);
	}
}

void CConfigDlg::OnButtonColorMacro() 
{
	// TODO: Add your control notification handler code here
	CColorDialog dlg;
	dlg.m_cc.Flags |= CC_FULLOPEN | CC_RGBINIT;
	dlg.m_cc.rgbResult = m_colorMacro;
	if (dlg.DoModal() == IDOK)
	{
		m_colorMacro = dlg.GetColor();
		m_btnColorMacro.SetColor(CButtonST::BTNST_COLOR_BK_IN, m_colorMacro);
		m_btnColorMacro.SetColor(CButtonST::BTNST_COLOR_BK_OUT, m_colorMacro);
		m_btnColorMacro.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, m_colorMacro);
		CString szColor;
		szColor.Format("#%02X%02X%02X", GetRValue(m_colorMacro), GetGValue(m_colorMacro), GetBValue(m_colorMacro));
		m_edtColorMacro.SetWindowText(szColor);
	}
}

void CConfigDlg::OnButtonColorRegister() 
{
	// TODO: Add your control notification handler code here
	CColorDialog dlg;
	dlg.m_cc.Flags |= CC_FULLOPEN | CC_RGBINIT;
	dlg.m_cc.rgbResult = m_colorRegister;
	if (dlg.DoModal() == IDOK)
	{
		m_colorRegister = dlg.GetColor();
		m_btnColorRegister.SetColor(CButtonST::BTNST_COLOR_BK_IN, m_colorRegister);
		m_btnColorRegister.SetColor(CButtonST::BTNST_COLOR_BK_OUT, m_colorRegister);
		m_btnColorRegister.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, m_colorRegister);
		CString szColor;
		szColor.Format("#%02X%02X%02X", GetRValue(m_colorRegister), GetGValue(m_colorRegister), GetBValue(m_colorRegister));
		m_edtColorRegister.SetWindowText(szColor);
	}
}

void CConfigDlg::OnButtonColorQuotation() 
{
	// TODO: Add your control notification handler code here
	CColorDialog dlg;
	dlg.m_cc.Flags |= CC_FULLOPEN | CC_RGBINIT;
	dlg.m_cc.rgbResult = m_colorQuotation;
	if (dlg.DoModal() == IDOK)
	{
		m_colorQuotation = dlg.GetColor();
		m_btnColorQuotation.SetColor(CButtonST::BTNST_COLOR_BK_IN, m_colorQuotation);
		m_btnColorQuotation.SetColor(CButtonST::BTNST_COLOR_BK_OUT, m_colorQuotation);
		m_btnColorQuotation.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, m_colorQuotation);
		CString szColor;
		szColor.Format("#%02X%02X%02X", GetRValue(m_colorQuotation), GetGValue(m_colorQuotation), GetBValue(m_colorQuotation));
		m_edtColorQuotation.SetWindowText(szColor);
	}
}

void CConfigDlg::OnButtonColorComment() 
{
	// TODO: Add your control notification handler code here
	CColorDialog dlg;
	dlg.m_cc.Flags |= CC_FULLOPEN | CC_RGBINIT;
	dlg.m_cc.rgbResult = m_colorComment;
	if (dlg.DoModal() == IDOK)
	{
		m_colorComment = dlg.GetColor();
		m_btnColorComment.SetColor(CButtonST::BTNST_COLOR_BK_IN, m_colorComment);
		m_btnColorComment.SetColor(CButtonST::BTNST_COLOR_BK_OUT, m_colorComment);
		m_btnColorComment.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, m_colorComment);
		CString szColor;
		szColor.Format("#%02X%02X%02X", GetRValue(m_colorComment), GetGValue(m_colorComment), GetBValue(m_colorComment));
		m_edtColorComment.SetWindowText(szColor);
	}
}

void CConfigDlg::OnButtonColorLinenum() 
{
	// TODO: Add your control notification handler code here
	CColorDialog dlg;
	dlg.m_cc.Flags |= CC_FULLOPEN | CC_RGBINIT;
	dlg.m_cc.rgbResult = m_colorLineNum;
	if (dlg.DoModal() == IDOK)
	{
		m_colorLineNum = dlg.GetColor();
		m_btnColorLineNum.SetColor(CButtonST::BTNST_COLOR_BK_IN, m_colorLineNum);
		m_btnColorLineNum.SetColor(CButtonST::BTNST_COLOR_BK_OUT, m_colorLineNum);
		m_btnColorLineNum.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, m_colorLineNum);
		CString szColor;
		szColor.Format("#%02X%02X%02X", GetRValue(m_colorLineNum), GetGValue(m_colorLineNum), GetBValue(m_colorLineNum));
		m_edtColorLineNum.SetWindowText(szColor);
	}
}

BOOL CConfigDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	short shBtnColor = 30;

	//������ɫ��
	m_colorKeyword = m_pSCCDlg->m_colorKeyword;
	m_colorMacro = m_pSCCDlg->m_colorMacro;
	m_colorRegister = m_pSCCDlg->m_colorRegister;
	m_colorQuotation = m_pSCCDlg->m_colorQuotation;
	m_colorComment = m_pSCCDlg->m_colorComment;
	m_colorLineNum = m_pSCCDlg->m_colorLineNum;

	//����Tooltip��
	m_btnColorKeyword.SetTooltipText(_T("�ؼ��ֵ���ɫ"));
	m_btnColorKeyword.SetBtnCursor(IDC_CURSOR_HAND);

	m_btnColorMacro.SetTooltipText(_T("�궨�����ɫ"));
	m_btnColorMacro.SetBtnCursor(IDC_CURSOR_HAND);

	m_btnColorRegister.SetTooltipText(_T("�Ĵ�������ɫ"));
	m_btnColorRegister.SetBtnCursor(IDC_CURSOR_HAND);

	m_btnColorQuotation.SetTooltipText(_T("˫���ŵ���ɫ"));
	m_btnColorQuotation.SetBtnCursor(IDC_CURSOR_HAND);

	m_btnColorComment.SetTooltipText(_T("ע�͵���ɫ"));
	m_btnColorComment.SetBtnCursor(IDC_CURSOR_HAND);

	m_btnColorLineNum.SetTooltipText(_T("�кŵ���ɫ"));
	m_btnColorLineNum.SetBtnCursor(IDC_CURSOR_HAND);

	m_btnOK.SetTooltipText(_T("�˳��������趨..."), TRUE);
	m_btnOK.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, shBtnColor);

	m_btnCancel.SetTooltipText(_T("�˳��������趨..."), TRUE);
	m_btnCancel.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, shBtnColor);

	m_btnUseDefault.SetTooltipText(_T("�ָ�Ĭ�ϵ��趨..."), TRUE);
	m_btnUseDefault.OffsetColor(CButtonST::BTNST_COLOR_BK_IN, shBtnColor);

	//������ɫ��ť��ɫ��
	SetColorButtons();

	//��ʼ������TABת���ɿո񡱣�
	m_checkboxChangeTabToSpace.SetCheck(m_pSCCDlg->m_nChangeTabToSpace);

	//��ʼ�������ո�ת����&nbsp����
	m_checkboxChangeSpaceToNbsp.SetCheck(m_pSCCDlg->m_nChangeSpaceToNbsp);

	//��ʼ�������س�ת����<br>����
	m_checkboxChangeCRLFToBr.SetCheck(m_pSCCDlg->m_nChangeCRLFToBr);

	//��ʼ��TAB_SPACE Spin��
	m_spinTabSpace.SetRange(1, 16);
	m_spinTabSpace.SetBase(10);
	m_spinTabSpace.SetPos(m_pSCCDlg->m_nTabSpace);

	//��ʼ��Line_Num_Indent Spin��
	m_spinLineNumIndent.SetRange(1, 10);
	m_spinLineNumIndent.SetBase(10);
	m_spinLineNumIndent.SetPos(m_pSCCDlg->m_nLineNumIndent);
	if (!m_pSCCDlg->m_btnShowLineNum.GetCheck())
	{
		m_edtLineNumIndent.EnableWindow(FALSE);
		m_spinLineNumIndent.EnableWindow(FALSE);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CConfigDlg::OnOK() 
{
	// TODO: Add extra validation here

	//������ɫ��
	m_pSCCDlg->m_colorKeyword = m_colorKeyword;
	m_pSCCDlg->m_colorMacro = m_colorMacro;
	m_pSCCDlg->m_colorRegister = m_colorRegister;
	m_pSCCDlg->m_colorQuotation = m_colorQuotation;
	m_pSCCDlg->m_colorComment = m_colorComment;
	m_pSCCDlg->m_colorLineNum = m_colorLineNum;

	//���ء���TABת���ɿո񡱣�
	m_pSCCDlg->m_nChangeTabToSpace = m_checkboxChangeTabToSpace.GetCheck();

	//���ء����ո�ת����&nbsp����
	m_pSCCDlg->m_nChangeSpaceToNbsp = m_checkboxChangeSpaceToNbsp.GetCheck();

	//���ء����س�ת����<br>����
	m_pSCCDlg->m_nChangeCRLFToBr = m_checkboxChangeCRLFToBr.GetCheck();

	//����TAB��ռ�Ŀո�����
	m_pSCCDlg->m_nTabSpace = m_spinTabSpace.GetPos();

	//�����кź�Ŀո�����
	m_pSCCDlg->m_nLineNumIndent = m_spinLineNumIndent.GetPos();

	CDialog::OnOK();
}

void CConfigDlg::OnButtonUseDefault() 
{
	// TODO: Add your control notification handler code here

	//����Ĭ����ɫ��
	m_colorKeyword = RGB(0, 0, 255);		//blue
	m_colorMacro = RGB(255, 0, 0);			//red
	m_colorRegister = RGB(128, 128, 0);		//#808000
	m_colorQuotation = RGB(255, 0, 255);	//#FF00FF  orange
	m_colorComment = RGB(0, 128, 0);		//#008000  green
	m_colorLineNum = RGB(128, 128, 128);	//#808080

	//������ɫ��ť��ɫ��
	SetColorButtons();

	//����Ĭ�ϵġ���TABת���ɿո񡱣�
	m_checkboxChangeTabToSpace.SetCheck(BST_CHECKED);

	//����Ĭ�ϵġ����ո�ת����&nbsp����
	m_checkboxChangeSpaceToNbsp.SetCheck(BST_CHECKED);

	//����Ĭ�ϵġ����س�ת����<br>����
	m_checkboxChangeCRLFToBr.SetCheck(BST_CHECKED);

	//����Ĭ�ϵ�TAB��ռ�Ŀո�����
	m_spinTabSpace.SetPos(4);

	//����Ĭ�ϵ��кź�Ŀո�����
	m_spinLineNumIndent.SetPos(2);
}

void CConfigDlg::SetColorButtons()
{
	CString szColor;

	//������ɫ��ť��
	//�ؼ�����ɫ��
	m_btnColorKeyword.SetColor(CButtonST::BTNST_COLOR_BK_IN, m_colorKeyword);
	m_btnColorKeyword.SetColor(CButtonST::BTNST_COLOR_BK_OUT, m_colorKeyword);
	m_btnColorKeyword.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, m_colorKeyword);
	szColor.Format("#%02X%02X%02X", GetRValue(m_colorKeyword), GetGValue(m_colorKeyword), GetBValue(m_colorKeyword));
	m_edtColorKeyword.SetWindowText(szColor);

	//�궨����ɫ��
	m_btnColorMacro.SetColor(CButtonST::BTNST_COLOR_BK_IN, m_colorMacro);
	m_btnColorMacro.SetColor(CButtonST::BTNST_COLOR_BK_OUT, m_colorMacro);
	m_btnColorMacro.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, m_colorMacro);
	szColor.Format("#%02X%02X%02X", GetRValue(m_colorMacro), GetGValue(m_colorMacro), GetBValue(m_colorMacro));
	m_edtColorMacro.SetWindowText(szColor);

	//�Ĵ�����ɫ��
	m_btnColorRegister.SetColor(CButtonST::BTNST_COLOR_BK_IN, m_colorRegister);
	m_btnColorRegister.SetColor(CButtonST::BTNST_COLOR_BK_OUT, m_colorRegister);
	m_btnColorRegister.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, m_colorRegister);
	szColor.Format("#%02X%02X%02X", GetRValue(m_colorRegister), GetGValue(m_colorRegister), GetBValue(m_colorRegister));
	m_edtColorRegister.SetWindowText(szColor);

	//˫������ɫ��
	m_btnColorQuotation.SetColor(CButtonST::BTNST_COLOR_BK_IN, m_colorQuotation);
	m_btnColorQuotation.SetColor(CButtonST::BTNST_COLOR_BK_OUT, m_colorQuotation);
	m_btnColorQuotation.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, m_colorQuotation);
	szColor.Format("#%02X%02X%02X", GetRValue(m_colorQuotation), GetGValue(m_colorQuotation), GetBValue(m_colorQuotation));
	m_edtColorQuotation.SetWindowText(szColor);

	//ע����ɫ��
	m_btnColorComment.SetColor(CButtonST::BTNST_COLOR_BK_IN, m_colorComment);
	m_btnColorComment.SetColor(CButtonST::BTNST_COLOR_BK_OUT, m_colorComment);
	m_btnColorComment.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, m_colorComment);
	szColor.Format("#%02X%02X%02X", GetRValue(m_colorComment), GetGValue(m_colorComment), GetBValue(m_colorComment));
	m_edtColorComment.SetWindowText(szColor);

	//�к���ɫ��
	m_btnColorLineNum.SetColor(CButtonST::BTNST_COLOR_BK_IN, m_colorLineNum);
	m_btnColorLineNum.SetColor(CButtonST::BTNST_COLOR_BK_OUT, m_colorLineNum);
	m_btnColorLineNum.SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, m_colorLineNum);
	szColor.Format("#%02X%02X%02X", GetRValue(m_colorLineNum), GetGValue(m_colorLineNum), GetBValue(m_colorLineNum));
	m_edtColorLineNum.SetWindowText(szColor);
}
