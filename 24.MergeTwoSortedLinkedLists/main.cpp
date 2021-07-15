#include <iostream>
#include "ListNode.h"

using namespace std;

ListNode* reverseList(ListNode* list)
{
	if (list == nullptr)
		return nullptr;
	printList(list);
	//ListNode* preNode, *curNode, *nextNode;
	//curNode = list;
	//preNode = new ListNode(list->m_value);
	//printList(preNode);
	//list = list->m_next;
	//printList(list);
	//while (list->m_next != nullptr)
	//{
	//	list->m_next = preNode;
	//	preNode = curNode;
	//	list = list->m_next;
	//}
	ListNode* preNode = nullptr;
	ListNode* curNode = list;
	ListNode* reverseHead = nullptr;
	while (curNode != nullptr)
	{
		ListNode* nextNode = curNode->m_next;
		if (nextNode == nullptr)
		{
			reverseHead = curNode;
		}
		curNode->m_next = preNode;
		preNode = curNode;
		curNode = nextNode;
	}
	return reverseHead;
}
int main()
{
	printList(reverseList(newList(0)));
	system("pause");
	return 0;
}