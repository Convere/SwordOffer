#include <iostream>

using namespace std;

void swap(int* numbers, int start, int last)
{
	int temp = numbers[start];
	numbers[start] = numbers[last];
	numbers[last] = temp;
}
void partion(int* numbers,int start,int last)
{
	int piovt = numbers[start];
	while (start < last)
	{
		while (start < last && (numbers[start] % 2 == 1))
		{
			++start;
		}
		while (start < last && (numbers[last] % 2 == 0))
		{
			--last;
		}
		if (start < last)
			swap(numbers, start, last);
	}
}
int main()
{
	int* number = new int[12]{ 2,4,6,8,45,1,3,4,7,3,8,9 };
	partion(number, 0, 11);
	for (int i = 0; i < 12; i++)
		cout << number[i] << endl;
	system("pause");
	return 0;

}