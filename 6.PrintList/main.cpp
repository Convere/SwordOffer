#include <iostream>
#include <stack>

using namespace std;

struct  ListNode
{
	int m_value;
	ListNode* m_next = nullptr;
	ListNode() { m_value = -1; m_next = nullptr; }
	ListNode(int a, ListNode* ptr):m_value(a),m_next(ptr) {}
	ListNode(int a) :m_value(a) {}
}; 

void printList(ListNode* list)
{
	if (list != nullptr)//´¦Àí¿ÕÁ´±í
	{
		if (list->m_next != nullptr)
		{
			//list = list->m_next;
			printList(list->m_next);
		}

		cout << list->m_value << endl;
	}
}
void ptrintListUseStack(ListNode* list)
{
	if (list != nullptr)
	{
		stack<int> printStack;
		while (list != nullptr)
		{
			printStack.push(list->m_value);
			list = list->m_next;
		}
		while (!printStack.empty())
		{
			cout << printStack.top() << endl;
			printStack.pop();
		}
	}
}
int main()
{
	ListNode* list = new ListNode(1);
	list->m_next = new ListNode(2);
	list->m_next->m_next = new ListNode(3);
	ptrintListUseStack(list);

	system("pause");
	return 0;
}