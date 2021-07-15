#include <iostream>

using namespace std;

//1.找出最高位数字最小的数字，若相同，找次高位最小的数字

//2.
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
const int g_MaxNumberLength = 10;
char* g_StrCombine1 = new char[g_MaxNumberLength * 2 + 1];
char* g_StrCombine2 = new char[g_MaxNumberLength * 2 + 1];

int compare(const void* strNumber1, const void* strNumber2)
{
	strcpy(g_StrCombine1, *(char**)strNumber1);
	strcat(g_StrCombine1, *(char**)strNumber2);

	strcpy(g_StrCombine2, *(char**)strNumber2);
	strcat(g_StrCombine2, *(char**)strNumber1);

	return strcmp(g_StrCombine1, g_StrCombine2);
}

void PrintMinNumber(int* numbers, int length)
{
	if (numbers == nullptr || length <= 0)
	{
		return;
	}
	char** strNumbers = (char**)(new int[length]);
	for (int i = 0;i < length;++i)
	{
		strNumbers[i] = new char[g_MaxNumberLength + 1];
		sprintf(strNumbers[i], "%d", numbers[i]);
	}
	qsort(strNumbers, length, sizeof(char*), compare);
	for (int i = 0 ;i < length;i++)
	{
		printf("%s", strNumbers[i]);
	}
	printf("\n");
	for (int i = 0; i < length; i++)
	{
		delete[] strNumbers[i];
	}
	delete[] strNumbers;
}

int main()
{

	char** numbers = (char**)(new int[2]);
	//PrintMinNumber(numbers,5);
	int g = 0;
	char b = 'k';
	numbers[0] = new char[9]{'a','b','g','t','s','g','t','s','h' };
	//numbers[1] = new char[6]{ 'a','b','g','t','s','h'};
	//numbers[0] = new char[2]{ 'a','b'};
	cout << sizeof(numbers[0]) << " " << sizeof(char*) << " " << sizeof(int*) << " " << sizeof(b) << " " << sizeof(g) << " "
		<< sizeof(numbers[0])/sizeof(*(numbers[0]))  << " "  << endl;
	system("pause");
	return 0;
}