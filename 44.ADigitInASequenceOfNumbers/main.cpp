#include <iostream>

using namespace std;
//求几位数对应了多少个数字
int countOfIntegers(int digit)
{
	if (digit == 1)
	{
		return 10;
	}
	int number = (int)std::pow(10, digit - 1);
	return 9 * number;
}
//几位数的开始数字
int beginNumber(int digit)
{
	if (digit == 1)
	{
		return 0;
	}
	return (int)std::pow(10, digit - 1);
}
//找到对应的区间，求出索引指向的数字
int digitAtIndex(int index, int digits)
{
	int number = beginNumber(digits) + index / digits;
	int digitFromRight = digits - (index % digits);
	for (int i = 1;i < digitFromRight;i++)
	{
		number /= 10;
	}
	return number % 10;
}
//主流程
int digitAtIndex(int index)
{
	if (index < 10)
	{
		return index;
	}
	int digits = 1;
	while (true)
	{
		int number = countOfIntegers(digits);
		if (index < number)
		{
			return digitAtIndex(index, digits);
		}
		index -= digits*number;
		digits++;
	}
	return -1;
}

int main()
{
	cout << digitAtIndex(1) << endl;
	system("pause");
}