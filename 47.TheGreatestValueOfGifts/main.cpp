#include <iostream>
#include <algorithm>
using namespace std;

int process(int *gift, int m, int n,int line,int col, int curValue)
{
	if (line >= m-1 && col >= n-1)
	{
		return curValue;
	}
	int p1 = curValue;
	if (col + 1 < n-1)
	{
		p1 = process(gift, m, n, line, col + 1, curValue + gift[line*n + col + 1]);
	}
	int p2 = curValue;
	if (line + 1 < m-1)
	{
		p2 = process(gift, m, n, line + 1, col, curValue + gift[(line + 1)*n + col]);
	}
	return max(p1, p2);
}
int maxValue(int* gift, int m, int n)
{
	if (m == 0 && n == 0)
	{
		return 0;
	}
	return process(gift, m, n, 0, 0, 0);
}

int getMaxValue(const int* gift, int rows, int cols)
{
	if (gift == nullptr || rows <= 0 || cols <= 0)
	{
		return 0;
	}
	int** maxValues = new int*[rows];
	for (int i = 0; i < rows;i++)
	{
		maxValues[i] = new int[cols];
	}
	for (int i = 0;i < rows;i++)
	{
		for (int j = 0; j < cols; j++)
		{
			int up = 0;
			int left = 0;
			if (i > 0)
				up = maxValues[i - 1][j];
			if (j > 0)
				left = maxValues[i][j - 1];
			maxValues[i][j] = max(left, up) + gift[i*cols + j];
		}
	}
	int maxValue = maxValues[rows - 1][cols - 1];
	for (int i = 0;i <rows;i++)
	{
		delete[] maxValues[i];
	}
	delete[] maxValues;
	return maxValue;
}
int main()
{
	int* gift = new int[16] { 1,10,3,8,12,2,9,6,5,7,4,11,3,7,16,5 };
	cout << maxValue(gift, 4, 4) << endl;
	cout << getMaxValue(gift, 4, 4) << endl;
	system("pause");
}