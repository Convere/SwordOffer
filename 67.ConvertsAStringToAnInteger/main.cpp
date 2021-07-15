#include <iostream>
#include <string>

using namespace std;

enum Status
{
	kValid = 0,
	kInValid
};
Status g_nValue = kValid;

long long StrToIntCore(const char* str, bool minus)
{
	long long sum = 0;
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9' )
		{
			int flag = minus ? -1 : 1;
			sum = sum * 10 + flag*  (*str - '0');

			if ((!minus &&sum > 0x7FFFFFFF) || (minus&&sum < (signed int)0x80000000))
			{
				sum = 0;
				break;
			}
			str++;
		}
		else
		{
			//sum = 0;
			break;
		}
	}
	if (*str == '\0')
		g_nValue = kValid;
	return sum;
}
int StrToInt(const char* str)
{
	g_nValue = kInValid;
	long long num = 0;
	if (str != nullptr && *str != '\0')
	{
		bool minus = false;
		if (*str == '+')
			str++;
		if (*str == '-')
		{
			str++;
			minus = true;
		}
		if (*str != '\0')
		{
			num = StrToIntCore(str, minus);
		}
	}
	return (int)num;
}

int main()
{
	string str;
	getline(cin, str);
	const char* nums = str.c_str();
	cout << StrToInt(nums) << endl;
	cout << sizeof(int) << endl; 
	system("pause");
}