class CLanguage
{
public:
	//构造函数：
	CLanguage(CString stxFileName);

	//字符判别函数声明：
	bool IsLetter(char ch);
	bool IsHNumber(char ch);
	bool IsONumber(char ch);
	bool IsNumber(char ch);
	bool IsWhite(char ch);
	bool IsKeyword(LPCTSTR str);
	bool IsMacro(LPCTSTR str);

	//关键字表和宏表定义：
	CStringArray m_Keyword;
	CStringArray m_Macro;
};
