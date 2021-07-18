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
//�ݹ������ӡ
void printList(ListNode* list)
{
	if (list != nullptr)//���������
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
//�ڶ���ˢ�⣬����˼·ʵ�ִ��롣������ߣ���˴��룬ջ�е������Ҵ����int ����ô�ListNode*��
void printListWithStack(ListNode* head)
{
	if (head == NULL)
	{
		return;
	}
	stack<ListNode*> S;
	while (head != nullptr)
	{
		S.push(head);
		head = head->m_next;
	}
	while (!S.empty())
	{
		cout << S.top()->m_value << " ";
		S.pop();
	}
	cout << endl;
}
/*
*�����뷴ת����������ͬ��֮�������޸�����ṹ�������Թ�Ҫ�����
*/
void reversePrint(ListNode* head)
{
	if (head == NULL)
	{
		return;
	}
	printList(head);
	ListNode* pNode = head;
	ListNode* pPre = nullptr;
	ListNode* pReverHead = nullptr;
	while (pNode != nullptr)
	{
		ListNode* pNext = pNode->m_next;
		if (pNext == nullptr)
		{
			pReverHead = pNode;
		}
		pNode->m_next = pPre;
		pPre = pNode;
		pNode = pNext;
	}
}
int main()
{
	ListNode* list = new ListNode(1);
	list->m_next = new ListNode(2);
	list->m_next->m_next = new ListNode(3);
	//ptrintListUseStack(list);
	printListWithStack(list);

	system("pause");
	return 0;
}