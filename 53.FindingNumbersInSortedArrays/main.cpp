#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int getFirstK(int* data, int k, int start, int end)
{
	if (start >end)
	{
		return -1;
	}
	int middleIdnex = (start + end) / 2;
	int middleData = data[middleIdnex];
	if (middleData == k)
	{
		if ((middleIdnex > 0 && data[middleIdnex - 1] != k) || middleIdnex == 0)
		{
			return middleIdnex;
		}
		else
		{
			end = middleIdnex - 1;
		}
	}
	else if (data[middleIdnex] > k)
		end = middleIdnex - 1;
	else
	{
		start = middleIdnex + 1;
	}
	return getFirstK(data, k, start, end);
}
int getLastK(int* data, int length,int k, int start, int end)
{
	if (start > end)
	{
		return -1;
	}
	int middleIdnex = (start + end) / 2;
	int middleData = data[middleIdnex];
	if (middleData == k)
	{
		if ((middleIdnex < length-1 && data[middleIdnex + 1] != k) || middleIdnex == length - 1)
		{
			return middleIdnex;
		}
		else
		{
			start = middleIdnex + 1;
		}
	}
	else if (data[middleIdnex] > k)
		end = middleIdnex - 1;
	else
	{
		start = middleIdnex + 1;
	}
	return getLastK(data, length,k, start, end);
}

int getNumberOfK(int* data, int length, int k)
{
	if (data == nullptr)
	{
		return 0;
	}
	int number = 0;
	int first = getFirstK(data, k, 0, length - 1);
	int last = getLastK(data, length, k, 0, length - 1);
	if (first > -1&& last >-1)
	{
		number = last - first + 1;
	}
	return number;
}
int main()
{
	vector<string> input;
	string line,word;
	getline(cin, line);
	stringstream sstring(line);
	while (sstring >> word)
		input.push_back(word);
	const int length = input.size();
	int* data = new int[length];
	for (int i = 0; i < length;i++)
	{
		data[i] = stoi(input[i].c_str());
	}
	cout << getNumberOfK(data, length, 3) << endl;
	system("pause");
	return 0;
}