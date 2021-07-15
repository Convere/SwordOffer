
#include <stack>	
#include <iostream>
#include <queue>

using namespace std;
//两个栈实现队列
template <typename T> class CQueue
{
public:
	CQueue(void) {}
	~CQueue(void) {}

	void appendTail(const T &node)
	{
		stack1.push(node);
	}
	T deleteHead()
	{
		if (stack2.size() <= 0)
		{
			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		if (stack2.size() == 0)
			throw new exception("queue is empty!");
		T head = stack2.top();
		stack2.pop();
		return head;
	}

private:
	stack<T> stack1;
	stack<T> stack2;
};
//两个队列实现栈
template <typename T> class CStack
{
public:
	CStack() {}
	~CStack() {}

	void push(T &node)
	{
		queue1.push(node);
	}
	T pop()
	{
		if (queue1.empty() && queue2.empty())
		{
			throw new exception("CStack is empty!");
		}
		if (!queue1.empty())
		{
			while (queue1.size() != 1)
			{
				queue2.push(queue1.front());
				queue1.pop();
			}
			T res = queue1.front();
			queue1.pop();
			return res;
		}
		else if (!queue2.empty())
		{
			while (queue2.size() != 1)
			{
				queue1.push(queue2.front());
				queue2.pop();
			}
			T res = queue2.front();
		
			queue2.pop();
			return res;
		}
	}
private:
	queue<T> queue1;
	queue<T> queue2;
};

int main()
{
	CQueue<int> queue1;
	int i = 0;
	while (i < 10)
	{
		queue1.appendTail(i);
		i++;
	}
	cout << queue1.deleteHead() << endl;
	CStack<int> cStack;
	//int j = 0;
	//while (j < 10)
	//{
	//	cStack.push(j);
	//	j++;
	//}
	cout << cStack.pop() << endl;
	system("pause");
	return 0;
}