#include <iostream>
#include "ListNode.h"
using namespace std;

int main()
{
	ListNode* l1 = newList(7);
	printList(l1);
	ListNode* l2 = nullptr;
	l2 = l1;
	printList(l1);
	printList(l2);
	l2 = l2->m_next;
	ListNode* l3 = l2->insert(l2, 7);
	printList(l1);
	printList(l2);
	printList(l3);
	
	system("pause");
	return 0;
}