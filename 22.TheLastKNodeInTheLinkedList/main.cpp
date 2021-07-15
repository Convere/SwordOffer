#include <iostream>
#include <vector>
#include "ListNode.h"

using namespace std;

vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
	int total_jumbo = 0;
	int total_small = 0;
	vector<int> res;
	if ((4 * cheeseSlices - tomatoSlices) % 2 == 0)
	{
		total_small = (4 * cheeseSlices - tomatoSlices) / 2;
		cout << total_small << endl;
	}
	else
		return res;
	total_small = cheeseSlices - total_jumbo;
	res.push_back(total_jumbo);
	res.push_back(total_small);
	return res;
}
ListNode* findKthToTail(ListNode* list,int k)
{
	printList(list);
	if (list == nullptr|| k ==0)
		throw new exception("list is empty!");
	int length = 0;
	ListNode* curlist = new ListNode();
	curlist = list;
	while (list->m_next!= nullptr)
	{
		list = list->m_next;
		++length;
	}
	if (length < k)
		throw new exception("list is empty!");
	int target = length - k + 1;
	while (target > 1)
	{
		curlist = curlist->m_next;
		target--;
	}
	return curlist;
}
int main()
{
	//printList(findKthToTail(newList(5), 2));
	vector<int> res = numOfBurgers(16, 7);
	for (auto a: res)
	{
		cout << a << endl;
	}
	system("pause");
	return 0;
}