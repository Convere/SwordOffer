#include <iostream>
#include "ListNode.h"

using namespace std;

ListNode* mergeTwoList(ListNode* l1, ListNode* l2)
{
	ListNode* phead = l2;
	while (l1 != nullptr ||l2 != nullptr)
	{
		while (l1 != nullptr && l2!= nullptr)
		{
			if (l1->m_value <= l2->m_value)
			{
				l1->m_next;
			}
		}
	}
	return l1;
}

int main()
{
	return 0;
}