
#include <iostream>
#include <array>
#include <algorithm>

#define duplicat 0
#define getDuplicat 1
using namespace std;
//�������ظ�������
bool duplicate(int numbers[], int length, int* dumplication)
{
	if (numbers == nullptr || length <= 0)
		return false;
	for (int i = 0; i < length; i++)
	{
		if (numbers[i] > length)
			return false;
	}
	for (int i = 0; i < length; i++)
	{
		while (numbers[i] != i)
		{
			if (numbers[i] == numbers[numbers[i]])
			{
				*dumplication = numbers[i];
				return true;
			}
			//������ �򽻻�
			int temp = numbers[i];
			numbers[i] = numbers[temp];
			numbers[temp] = temp;
		}
	}
	return false;
}
//���ı����飬�ҳ��ظ�������
int countRange(const int* numbers, int length, int start, int end)
{
	if (numbers == nullptr)
		return 0;
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (numbers[i]>= start && numbers[i] <= end ) 
		{
			count++;
		}
	}
	return count;
}
int getDuplication(const int* numbers, int length)
{
	//�ж������Ƿ�Ϊ�գ�
	if (numbers == nullptr || length <= 0)
		return -1;
	//�ж����ִ�С�Ƿ�Խ��
	for (int i = 0; i < length; i++)
	{
		if (numbers[i] >= length)
			return -1;
	}
	//���ֲ��ң��ֽ�
	int start = 1;
	int end = length - start;
	while (start <= end)
	{
		int middle = (end - start) / 2 + start;
		int count = countRange(numbers, length, start, middle);
		if (end == start)
		{
			if (count > 1)
				return start;
			else
				break;
		}
		if (count > (middle - start + 1))
			end = middle;
		else
			start = middle + 1;
	}
	return -1;
}
int main()
{
	//int number[7] = { 2,3,1,0,2,5,3 };
	int number[8] = { 2,3,5,4,3,2,6,7 };
	int length = sizeof(number) / sizeof(number[0]);
#if duplicat
	int* duplication = new int();
	bool result = duplicate(number, length, duplication);
	cout << "��ѯ����ǣ� " << result << endl;
	if (result)
		cout << "�ظ��ĵ�һ�������ǣ� " << *duplication;
#endif // duplicat

#if getDuplicat
	int res = getDuplication(number, length);
	cout << "�ظ��������� " << res;
#endif
	cout << endl;
	system("pause");
	return 0;
}