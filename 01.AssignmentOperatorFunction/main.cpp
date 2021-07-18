#include <iostream>
#include <algorithm>
#include "CMyString.h"
using namespace std;
int main()
{
	char* data = "hello";
	CMyString m_String(data);
	CMyString str;
	str = m_String;
	str.printString();
	system("pause");
	return 0;
}