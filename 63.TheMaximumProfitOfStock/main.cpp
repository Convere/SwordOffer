#include <iostream>
#include <string>
#include <vector>
using namespace std;

int maxDiff(int* numbers, unsigned int length)
{
	if (numbers == nullptr || length < 2)
	{
		return 0;
	}
	int minPrice = INT_MAX;
	int maxProfit = 0;
	for (int i = 0; i < length; i++)
	{
		if (numbers[i] < minPrice)
			minPrice = numbers[i];
		int curProfit = numbers[i] - minPrice;
		if (curProfit > maxProfit)
			maxProfit = curProfit;
	}
	return maxProfit;
}

int main()
{
	string str;
	vector<int> nums;
	while (getline(cin,str,','))
	{
		nums.push_back(stoi(str.c_str()));
	}
	const int length = nums.size();
	int* numbers = new int[length]; 
	int i = 0;
	while (i < length)
	{
		numbers[i] = nums[i];
		i++;
	}
	cout << maxDiff(numbers, length) << " " << string::npos << endl;
	system("pause");
}