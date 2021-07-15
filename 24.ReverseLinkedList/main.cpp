#include <iostream>
#include "ListNode.h"

using namespace std;

ListNode* reverseList1(ListNode* head) {
	if (!head || !head->m_next) {
		return head;
	}
	ListNode* newHead = reverseList1(head->m_next);
	head->m_next->m_next = head;
	head->m_next = nullptr;
	return newHead;
}

ListNode* reverseList(ListNode* list)
{
	if (list == nullptr)
		return nullptr;
	//printList(list);
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
			printList(reverseHead);
		}
		curNode->m_next = preNode;
		preNode = curNode;
		curNode = nextNode;
	}
	printList(reverseHead);
	return reverseHead;
}
ListNode* reverseListR(ListNode* head) {
	if (!head || !head->m_next) {
		return head;
	}
	ListNode* newHead = reverseListR(head->m_next);
	head->m_next->m_next = head;
	head->m_next = nullptr;
	return newHead;
}

ListNode* reverseList_t(ListNode* pHead)
{
	ListNode* pReverseHead = nullptr;
	ListNode* pNode = pHead;
	ListNode* pPre = nullptr;
	while (pNode != nullptr)
	{
		ListNode* pNext = pNode->m_next;
		if (pNext == nullptr)
		{
			pReverseHead = pNode;
		}
		pNode->m_next = pPre;
		pPre = pNode;
		pNode = pNext;
	}

	return pReverseHead;
}

int main()
{
	printList(newList(5));
	printList(reverseListR(newList(5)));
	printList(reverseList_t(newList(5)));
	system("pause");
	return 0;
}