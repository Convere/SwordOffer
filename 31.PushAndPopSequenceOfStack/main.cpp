#include <iostream>
#include <stack>

using namespace std;

bool isPopOrder(const int* order1, const int* order2, int length)
{
	stack<int> inStack;
	int inOrder = 0;
	inStack.push(order1[0]);
	for (int i =0 ;i < length;i++)
	{
		if (inOrder < length )
		{
			while (order2[i] != inStack.top()|| inStack.empty())
			{
				if (inOrder >= length)
					return false; 
				inOrder++;
				inStack.push(order1[inOrder]);
			}
		}
		if (order2[i] != inStack.top())
		{
			return false;
		}
		inStack.pop();
	}
	return true;
}

int main()
{
	int* inSort = new int[5]{ 2 };
	int* outSort = new int[5]{ 2 };
	cout << isPopOrder(inSort, outSort, 5) << endl;
	system("pause");
	return 0;
}