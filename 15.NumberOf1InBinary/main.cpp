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
	int n = -9;
	cout << n << " жага " << numberOf1(n) << " Иі1" << endl;
	system("pause");
	return 0;
}