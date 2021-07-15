#include <iostream>
#include <stack>
#include <assert.h>
using namespace std;

template <typename T> class MyStack
{
	public:
		MyStack(){}
		T min()
		{
			assert(stack1.size() > 0 && stack2.size() > 0);
			return stack2.top();
		}
		void push(T value)
		{
			if (stack2.empty())
			{
				stack2.push(value);
			}
			else
				stack2.push(value < stack2.top() ? value : stack2.top());
			stack1.push(value);
		}
		void pop()
		{
			assert(stack1.size() > 0 && stack2.size() > 0);//数组的弹出前要判断数组是否为空
			stack1.pop();
			stack2.pop();
		}
	private:
		stack<T> stack1;
		stack<T> stack2;
};

int main()
{
	MyStack<int> stack;
	stack.push(5);
	stack.push(2);
	stack.push(8);
	stack.push(7);
	cout << stack.min() << endl;
	system("pause");
}