#include <iostream>

using namespace std;
bool increment(char* number)
{
	bool isOverFlow = false;
	int nTakeOver = 0;
	int nLength = strlen(number);
	for (int i = nLength - 1; i >= 0; i--)
	{
		int nSum = number[i] - '0' + nTakeOver;
		if (i == nLength - 1)
			nSum++;
		cout << " nsum " << nSum << endl;
		if (nSum >= 10)
		{
			if (i == 0)
				isOverFlow = true;
			else
			{
				nSum -= 10;
				nTakeOver = 1;
				number[i] = '0' + nSum;
			}
		}
		else
		{
			number[i] = '0' + nSum;
			break;
		}
	}
	return isOverFlow;
}

void printNumber(char* number)
{
	bool isBegin0 = true;
	int leng = strlen(number);
	for (int i = 0; i < leng; i++)
	{
		if (isBegin0 && number[i] != '0')
		{
			isBegin0 = false;
		}
		if (!isBegin0)
			printf("%c", number[i]);
	}
	printf("\t");
}
void	print1ToMaxOfDigits(int n)
{
	if (n < 0)
		return;
	char* number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';
	while (!increment(number))
	{
		//printNumber(number);
		int leng = strlen(number);
		for (int i = 0; i < leng; i++)
		{
			cout << number[i];
		}
		cout << endl;
	}
}



int main()
{
	print1ToMaxOfDigits(3);
	system("pause");
	return 0;
}