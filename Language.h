class CLanguage
{
public:
	//���캯����
	CLanguage(CString stxFileName);

	//�ַ��б���������
	bool IsLetter(char ch);
	bool IsHNumber(char ch);
	bool IsONumber(char ch);
	bool IsNumber(char ch);
	bool IsWhite(char ch);
	bool IsKeyword(LPCTSTR str);
	bool IsMacro(LPCTSTR str);

	//�ؼ��ֱ�ͺ���壺
	CStringArray m_Keyword;
	CStringArray m_Macro;
};
