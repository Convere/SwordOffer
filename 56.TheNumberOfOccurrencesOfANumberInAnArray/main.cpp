#include <iostream>

using namespace std;


int findFirstIndexOf1(int &num)
{
	if (num == 0)
	{
		return 0;
	}
	unsigned int stl = 0;
	while (!(num & 1))
	{
		num = num >> 1;
		stl++;
	}
	return stl;
}
bool isBit1(int num, int index)
{
		num = num >> index;
	return (num & 1);
}
void findNumsAppearOnce(int* data, int length, int* num1, int* num2)
{
	if (data == nullptr || length <= 0)
	{
		return;
	}
	//1.找出异或后的数字
	int result = 0;
	for (int i = 0; i < length;i++)
	{
		result ^= data[i];
	}
	//2.找出异或结果的第一个为1的位置
	unsigned int indexOf1 = findFirstIndexOf1(result);
	cout << indexOf1 << endl;
	//3.分组查找最后结果
	for (int i = 0; i < length;i++)
	{
		if (isBit1(data[i], indexOf1))
			*num1 ^= data[i];
		else
			*num2 ^= data[i];
	}
}

int main()
{
	int* data = new int[6]{ 1,2,3,5,2,1 };
	int num1 = 0, num2 = 0;
	findNumsAppearOnce(data, 6, &num1, &num2);
	cout << num1 << " " << num2 << endl;
	system("pause");
}