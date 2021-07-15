#include <iostream>

using namespace std;

//在二维数组中查找特定整数
bool find(int* matrix, int rows, int columns, int number)
{
	bool found = false;
	if (matrix != nullptr && rows > 0 && columns > 0)
	{
		int row = 0;
		int column = columns - 1;
		while (row < rows && column >= 0)
		{
			if (matrix[row*columns + column] == number)
			{
				found = true;
				break;
			}
			if (matrix[row*columns + column] > number)
				--column;
			else
				++row;
		}
	}
	return found;
}

int main()
{
	int numbers[16] = { 1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15 };
	int number = 45;
	bool res = find(numbers, 4, 4, number);
	cout << "数字 " << number << "在数组中 " << res << endl;

	//字符串
	char str1[] = "hello world";
	char str2[] = "hello world";

	if (str1 == str2)
		cout << "两个字符串相同" << endl;
	system("pause");
	return 0;
}