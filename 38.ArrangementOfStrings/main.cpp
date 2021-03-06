#include <iostream>

using namespace std;

void Permutation(char* pStr, char* pBegin)
{
	if (*pBegin == '\0')
	{
		cout << *pStr << endl;
		//printf("%s\n", pStr);
	}
	else
	{
		for (char* pCh = pBegin; *pCh != '\0'; pCh++)
		{
			char temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;

			Permutation(pStr, pBegin + 1);

			temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;
		}
	}
}

void Permutation(char* pStr)
{
	if (pStr == nullptr)
	{
		return;
	}

	Permutation(pStr, pStr);
}
int main()
{
	char* str = new char[5]{ 'a','b','c','d','v' };
	Permutation(str);
	system("pause");
}