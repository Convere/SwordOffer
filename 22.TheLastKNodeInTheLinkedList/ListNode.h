#pragma once
#include <iostream>
struct ListNode
{
	int m_value;
	ListNode* m_next = nullptr;
	ListNode() { m_value = -1; m_next = nullptr; }
	ListNode(int a, ListNode* ptr) :m_value(a), m_next(ptr) {}
	ListNode(int a) :m_value(a) {}
};


ListNode* newList(int n)
{
	ListNode*  list = new ListNode();
	int i = 0;
	while (i < n)
	{
		ListNode* temp = new ListNode(i, list);
		list = temp;
		i++;
	}
	return list;
}
void printList(ListNode* list)
{
	while (list->m_next != nullptr )
	{
		std::cout << list->m_value << " ";
		list = list->m_next;
	}
	std::cout << std::endl;
}
