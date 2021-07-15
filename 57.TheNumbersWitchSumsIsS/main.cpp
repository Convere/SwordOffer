#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

bool findTwoNumbers(int* nums, int length,int target,int* num1,int* num2)
{
	if (nums == nullptr || length <= 0)
	{
		return nullptr;
	}
	int ahead = 0;
	int behind = length - 1;
	while (behind > ahead)
	{
		long long curSum = nums[ahead] + nums[behind];
		if (curSum == target)
		{
			*num1 = nums[ahead];
			*num2 = nums[behind];
			return true;
		}
		else if (curSum > target)
			behind--;
		else
			ahead++;
	}
	return false;
}
int sumKToM(int s, int e)
{
	if (s == e)
	{
		return 0;
	}
	int sum = s;
	while (s < e)
	{
		s += 1;
		sum += s;
	}
	return sum;
}
void printKToM(int s, int e)
{
	while (s <= e)
	{
		cout << s << " " ;
		s += 1;
	}
	cout << endl;
}
void findSerials(int target)
{
	if (target<= 2)
	{
		return ;
	}
	int ahead = 1;
	int behind = 2;
	while (ahead <= (target / 2))
	{
		if (sumKToM(ahead,behind)== target)
		{
			printKToM(ahead, behind);
			behind++;
		}
		else if (sumKToM(ahead, behind) > target)
		{
			ahead++;
		}
		else
			behind++;
	}
}

int main()
{
	string str,res;
	vector<int> data;
	while (getline(cin, res, ','))
	{
		data.push_back(stoi(res.c_str()));
	}
	const int length = data.size();
	int *nums = new int[length];
	int i = 0;
	while (i < length)
	{
		nums[i] = data[i];
		i++;
	}
	int num1 =0;
	int num2 = 0;
	
	//cout << findTwoNumbers(nums, length, 5, &num1, &num2) << " " << num1 << " " << num2 << endl;
	findSerials(9);
	system("pause");
}