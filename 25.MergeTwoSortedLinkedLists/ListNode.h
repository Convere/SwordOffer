#pragma once
#include <iostream>
struct ListNode
{
	int m_value;
	ListNode* m_next = nullptr;
	//ListNode() { m_value = -1; m_next = nullptr; }
	//ListNode(int a, ListNode* ptr) :m_value(a), m_next(ptr) {}
	//ListNode(int a) :m_value(a) {}
};


ListNode* newList(int n)
{
	if (n ==0 )
	{
		return nullptr;
	}
	ListNode*  list = new ListNode();
	int i = 1;
	while (i < n)
	{
		ListNode* temp = nullptr;
		temp->m_next = list;
		temp->m_value = i;
		list = temp;
		i++;
	}
	return list;
}
void printList(ListNode* list)
{
	if (list == nullptr)
	{
		std::cout << "打印的列表为空！！" << std::endl;
		return;
	}
	while (list->m_next != nullptr )
	{
		std::cout << list->m_value << " ";
		list = list->m_next;
	}
	std::cout << std::endl;
}
