#pragma once
#include <iostream>
#include <vector>
struct ListNode
{
	int m_value;
	ListNode* m_next = nullptr;
	ListNode() { m_value = -1; m_next = nullptr; }
	ListNode(int a, ListNode* ptr) :m_value(a), m_next(ptr) {}
	ListNode(int a) :m_value(a) {}

	ListNode* insert(ListNode* head, int newdata)
	{
		ListNode* temp =new ListNode(newdata,nullptr);
		//头插
		//temp->m_next = head->m_next;
		//head->m_next = temp;
#if 1
		//尾插
		ListNode* p; // = (PNODE)malloc(sizeof(NODE)); //相应的这里p不需要申请空间
		p = head;
		while (head->m_next != nullptr)
			head = head->m_next;
		head->m_next = new ListNode(newdata, nullptr);;
		return p;
	}
#endif
};


ListNode* newList(int n)
{
	ListNode*  list = new ListNode();
	std::vector<ListNode*> listVec;
	listVec.push_back(list);
	int i = 0;
	while (i < n)
	{
		ListNode* temp = new ListNode(i, list);
		listVec.push_back(temp);
		list = temp;
		i++;
	}
	 //listVec[0]->m_next = listVec.at(3);
	return list;
}
void printList(ListNode* list)
{
	while (list->m_next != nullptr)
	{
		std::cout << list->m_value << " ";
		list = list->m_next;
	}
	std::cout << std::endl;
}
#pragma once
