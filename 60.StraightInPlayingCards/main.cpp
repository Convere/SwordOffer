#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isStrait(int* numbers, int length)
{
	if (numbers == nullptr || length <= 0)
	{
		return false;
	}
	qsort(numbers, length, sizeof(int), [](const void* a1, const void* a2) {return *(int*)a1 - *(int*)a2; });
	int numOfZero = 0;
	int numOfGap = 0;

	for (int i = 0; i < length&&numbers[i] == 0; i++)
		numOfZero++;
	int small = numOfZero; 
	int big = small + 1;
	while (big < length)
	{
		if (numbers[small] == numbers[big])
		{
			return false;
		}
		numOfGap += numbers[big] - numbers[small] - 1;
		small = big;
		big++;
	}
	if (numOfGap > numOfZero)
		return false;
	return numOfGap > numOfZero ? false : true;
}
int main()
{
	string str;
	vector<int> data;
	while (getline(cin, str, ','))
	{
		data.push_back(stoi(str.c_str()));
	}
	const int length = data.size();
	int *numbers = new int[length];
	for (int i = 0; i < length;i++)
	{
		numbers[i] = data[i];
	}
	cout << isStrait(numbers, length) << endl;
	system("pause");
}