#include <iostream>
#include "CMyString.h"
using namespace std;

int main()
{
	char* data = new char[5]{ 'h','e','l','l','o' };
	CMyString m_String(data);
	system("pause");
	return 0;
}