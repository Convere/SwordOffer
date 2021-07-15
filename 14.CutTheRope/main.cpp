#include <iostream>

using namespace std;

//动态规划
int maxProductAfterCutting(int length)
{
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;
	int* products = new int[length + 1];
	products[0] = 0;
	products[1] = 1;
	products[2] = 2;
	products[3] = 3;

	int max = 0;
	for (int i =4;i <= length;i++)
	{
		max = 0;
		for (int j = 1; j<= i/2;j++)
		{
			int product = products[j] * products[i - j];
			if (max < product)
			{
				max = product;
				//cout << i << " " << j << endl;
			}
			
		}
		products[i] = max;
	}
	max = products[length];
	delete[] products;
	return max;
}
int main()
{
	cout << "最大值是： " << maxProductAfterCutting(100) << endl;
	system("pause");
	return 0;
}