#include <iostream>
#include <bitset>

using namespace std;

int numberOf1(int n)
{
	int count = 0;
	unsigned int flag = 1;
	while (flag)
	{
		if (n&flag)
		{
			++count;
		}
		flag = flag << 1;
		cout << bitset<32>(flag) << endl;
	}
	return count;
}

//注意复数的二进制表示是补码的形式（即反码+1），-1的表示为0xFFFFFFFF
int numberOf1Better(int n)
{
	int count = 0;
	while (n)
	{
		++count;
		n = n&(n - 1);
	}
	return count;
}

int main()
{
	int n = pow(2,32);
	cout << bitset<32>(n) << endl;
	cout << n << " 中有 " << numberOf1Better(n) << " 个1" << endl;
	system("pause");
	return 0;
}