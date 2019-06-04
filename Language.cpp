#include "stdafx.h"
#include "Language.h"

/********************************************
//��������CLanguage
//���ã���CLanguage�Ĺ��캯��
//����˵������
********************************************/
CLanguage::CLanguage(CString stxFileName)
{
	//�ؼ��ֱ�ͺ���壺
	CStdioFile stxFile;

	if (!stxFile.Open(stxFileName, CFile::modeRead))
	{
		MessageBox(NULL, "��stx�ļ�����", "SCC", MB_OK | MB_ICONHAND);
	}
	else
	{
		CString szTemp;
		while (stxFile.ReadString(szTemp))
		{
			if (szTemp == "[Keyword]")
			{
				break;
			}
		}
		while (stxFile.ReadString(szTemp))
		{
			if (szTemp == "[Macro]")
			{
				break;
			}
			else if (szTemp != "")
			{
				m_Keyword.Add(szTemp);
			}
		}

		stxFile.SeekToBegin();
		while (stxFile.ReadString(szTemp))
		{
			if (szTemp == "[Macro]")
			{
				break;
			}
		}
		while (stxFile.ReadString(szTemp))
		{
			if (szTemp == "[Keyword]")
			{
				break;
			}
			else if (szTemp != "")
			{
				m_Macro.Add(szTemp);
			}
		}

		stxFile.Close();
	}
}


/********************************************
//��������IsLetter
//���ã�����ַ��Ƿ�Ϊ��ĸ
//����˵����ch �������ַ�
********************************************/
bool CLanguage::IsLetter(char ch)
{
	return ((ch >= 0x41 && ch <= 0x5a) || (ch >= 0x61 && ch <= 0x7a) || (ch == '#')) ? true : false;
}


/********************************************
//��������IsHNumber
//���ã�����ַ��Ƿ�Ϊʮ����������
//����˵����ch �������ַ�
********************************************/
bool CLanguage::IsHNumber(char ch)
{
	return ((ch >= 0x61 && ch <= 0x66) || (ch >= 0x41 && ch <= 0x46) || (ch >= 0x30 && ch <= 0x39)) ? true : false;
}


/********************************************
//��������IsONumber
//���ã�����ַ��Ƿ�Ϊ�˽�������
//����˵����ch �������ַ�
********************************************/
bool CLanguage::IsONumber(char ch)
{
	return (ch >= 0x30 && ch <= 0x37) ? true : false;
}


/********************************************
//��������IsNumber
//���ã�����ַ��Ƿ�Ϊʮ��������
//����˵����ch �������ַ�
********************************************/
bool CLanguage::IsNumber(char ch)
{
	return (ch >= 0x30 && ch <= 0x39) ? true : false;
}


/********************************************
//��������IsWhite
//���ã�����ַ��Ƿ�Ϊ�հ��ַ�
//����˵����ch �������ַ�
********************************************/
bool CLanguage::IsWhite(char ch)
{
	//return (ch == 0x0a || ch == 0x0d || ch == 0x09 || ch == 0x20) ? true : false;
	return ((ch == '\r') || (ch == '\n')) ? true : false;
}


/********************************************
//��������IsKeyword
//���ã�����ַ����Ƿ�Ϊ�ؼ���
//����˵����str �������ַ���ָ��
********************************************/
bool CLanguage::IsKeyword(LPCTSTR str)
{
	for(int i = 0; i < m_Keyword.GetSize(); i++)
	{
		if (m_Keyword[i] == str)
			return true;
	}
	return false;
}


/********************************************
//��������IsMacro
//���ã�����ַ����Ƿ�Ϊ�ؼ���
//����˵����str �������ַ���ָ��
********************************************/
bool CLanguage::IsMacro(LPCTSTR str)
{
	for(int i = 0; i < m_Macro.GetSize(); i++)
	{
		if (m_Macro[i] == str)
			return true;
	}
	return false;
}