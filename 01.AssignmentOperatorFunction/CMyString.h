#pragma once
#include <iostream>
class CMyString
{
public:
	CMyString(char* pData = nullptr) { m_pData = nullptr; }
	CMyString(const CMyString& str) { m_pData = str.m_pData; }
	CMyString& operator=(CMyString&);
	void printString();
	~CMyString();

private:
	char* m_pData;
};


inline CMyString & CMyString::operator=(CMyString & str)
{
	// TODO: 在此处插入 return 语句
	delete m_pData;
	m_pData = new char(*(str.m_pData));
	
	return *this;
}

inline void CMyString::printString()
{
	if (m_pData == nullptr)
		return;
	for (int i = 0;i < sizeof(m_pData)/sizeof(m_pData[0]);i++)
	{
		std::cout << m_pData[i] << " ";
	}
	std::cout << std::endl;
}

CMyString::~CMyString()
{
	if (m_pData != nullptr)
	{
		delete m_pData;
		m_pData = nullptr;
	}
}