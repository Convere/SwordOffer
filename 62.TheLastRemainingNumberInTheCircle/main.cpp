#include <iostream>
#include <list>

using namespace std;

int lastRemaining(int n, int m)
{
	if (n < 1 ||m< 1)
	{
		return 0;
	}
	list<int> circle;
	for (int i = 0; i < n; i++)
		circle.push_back(i);
	list<int>::iterator current = circle.begin();

	while (circle.size() > 1)
	{
		for (int i = 1; i < m;i++)
		{
			++current;
			if (current == circle.end())
				current = circle.begin();
		}

		list<int>::iterator next = ++current;
		if (next == circle.end())
			next = circle.begin();

		--current;
		circle.erase(current);
		current = next;
	}
	return *current;
}

int main()
{
	cout << lastRemaining(24,5) << endl;
	int k = -4;
	cout << k % 5 << endl;
	system("pause");
}