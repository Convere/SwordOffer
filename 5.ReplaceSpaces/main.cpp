#include <iostream>
#include <string>
using namespace std;

//�滻�ַ����еĿո�
void replace(string &str)
{
	int spaceCount = 0;
	for (char a : str)
	{
		if (a == ' ')
			++spaceCount;
	}
	str.reserve(str.size() + spaceCount * 2);
	for (size_t i = 0;i < str.size();i++)
	{

	}
}
int main()
{
	return 0;
}