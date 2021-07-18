#include <iostream>
#include "..\ListNode.h"

using namespace std;
//µÚ¶þ±éË¢Ìâ
void deleteNode(ListNode** head, ListNode* toBeDeleteNode)
{
	if (head == nullptr || toBeDeleteNode == nullptr)
	{
		return;
	}
	if (toBeDeleteNode->m_next != nullptr)
	{
		ListNode* pNext = toBeDeleteNode->m_next;
		toBeDeleteNode->m_value = pNext->m_value;
		toBeDeleteNode->m_next = pNext->m_next;

		delete pNext;
		pNext = nullptr;
		
	}
	else if(*head == toBeDeleteNode)
	{
		*head = nullptr;
		delete toBeDeleteNode;
		toBeDeleteNode == nullptr;
	}
	else
	{
		ListNode* pNode = *head;
		while (pNode->m_next != toBeDeleteNode)
		{
			pNode = pNode->m_next;
		}
		pNode->m_next = nullptr;
		delete toBeDeleteNode;
		toBeDeleteNode = nullptr;
	}
}
int main()
{
	ListNode* head = newList(3);
	ListNode* toBeDelete = head->m_next->m_next;
	deleteNode(&head, toBeDelete);
	printList(head);
	system("pause");
	return 0;
}