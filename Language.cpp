#include "stdafx.h"
#include "Language.h"

/********************************************
//函数名：CLanguage
//作用：类CLanguage的构造函数
//参数说明：无
********************************************/
CLanguage::CLanguage(CString stxFileName)
{
	//关键字表和宏表定义：
	CStdioFile stxFile;

	if (!stxFile.Open(stxFileName, CFile::modeRead))
	{
		MessageBox(NULL, "打开stx文件出错！", "SCC", MB_OK | MB_ICONHAND);
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
//函数名：IsLetter
//作用：检查字符是否为字母
//参数说明：ch 待检查的字符
********************************************/
bool CLanguage::IsLetter(char ch)
{
	return ((ch >= 0x41 && ch <= 0x5a) || (ch >= 0x61 && ch <= 0x7a) || (ch == '#')) ? true : false;
}


/********************************************
//函数名：IsHNumber
//作用：检查字符是否为十六进制数字
//参数说明：ch 待检查的字符
********************************************/
bool CLanguage::IsHNumber(char ch)
{
	return ((ch >= 0x61 && ch <= 0x66) || (ch >= 0x41 && ch <= 0x46) || (ch >= 0x30 && ch <= 0x39)) ? true : false;
}


/********************************************
//函数名：IsONumber
//作用：检查字符是否为八进制数字
//参数说明：ch 待检查的字符
********************************************/
bool CLanguage::IsONumber(char ch)
{
	return (ch >= 0x30 && ch <= 0x37) ? true : false;
}


/********************************************
//函数名：IsNumber
//作用：检查字符是否为十进制数字
//参数说明：ch 待检查的字符
********************************************/
bool CLanguage::IsNumber(char ch)
{
	return (ch >= 0x30 && ch <= 0x39) ? true : false;
}


/********************************************
//函数名：IsWhite
//作用：检查字符是否为空白字符
//参数说明：ch 待检查的字符
********************************************/
bool CLanguage::IsWhite(char ch)
{
	//return (ch == 0x0a || ch == 0x0d || ch == 0x09 || ch == 0x20) ? true : false;
	return ((ch == '\r') || (ch == '\n')) ? true : false;
}


/********************************************
//函数名：IsKeyword
//作用：检查字符串是否为关键字
//参数说明：str 待检查的字符串指针
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
//函数名：IsMacro
//作用：检查字符串是否为关键字
//参数说明：str 待检查的字符串指针
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