#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
using namespace  std;

//找滑动窗口中的最大值 时间复杂度 O(1)
vector<int> maxValueInWindow(vector<int> num, int size)
{
	vector<int> maxValueWindow;
	if (num.size()>=size &&size >0)
	{
		deque<int> index;
		for (unsigned int i = 0; i < size; i++)
		{
			while (!index.empty()&&num[i]>=num[index.back()])
			{
				index.pop_back();
			}
			index.push_back(i);
		}
		for (int i = size; i < num.size();i++)
		{
			maxValueWindow.push_back(num[index.front()]);

			while (!index.empty()&&num[i] >= num[index.back()])
			{
				index.pop_back();
			}
			while (!index.empty() && index.front() <= (int)(i - size))
				index.pop_front();

			index.push_back(i);
		}
		maxValueWindow.push_back(num[index.front()]);
	}
	return maxValueWindow;
}

//具有Max()函数且时间复杂度为O(1)的队列
template <typename T> class QueueWithMax
{
public:
	QueueWithMax():curIndex(0){}
	void push_back(T number)
	{
		while (!maximums.empty()&& number >= maximums.back().number)
		{
			maximums.pop_back();
		}
		InternalData interNumber = { curIndex,number };
		data.push_back(interNumber);
		maximums.push_back(interNumber);
		
		++curIndex;
	}
	void pop_front()
	{
		if (maximums.empty())
		{
			throw new exception("queue is empty!");
		}
		if (maximums.front().iedex == curIndex)
			maximums.pop_front();

		data.pop_front();
	}
	T max() const
	{
		if (maximums.empty())
		{
			throw new exception("queue is empty!");
		}

		return maximums.front().number;
	}
private:
	struct InternalData
	{
		int iedex;
		T number;
	};
	deque<InternalData> data;
	deque<InternalData> maximums;
	int curIndex;
};


int main()
{
	string str;
	vector<int> data;
	QueueWithMax<int> data2;
	while (getline(cin, str, ','))
	{
		data.push_back(stoi(str.c_str()));
		data2.push_back(stoi(str.c_str()));
	}
	vector<int> res;
	res = maxValueInWindow(data, 3);
	for_each(res.begin(), res.end(), [](int &a) {cout << a << " "; });
	cout << endl;

	cout << data2.max() << endl;
	system("pause");
}