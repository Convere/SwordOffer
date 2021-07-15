
#include <iostream>
#include <stack>
#include "BinaryTree.h"
using namespace std;

void printList_zigzag(BinaryTree* node)
{
	if (node == nullptr)
	{
		return;
	}
	stack<BinaryTree* > Q;
	bool leftToRight = true;
	Q.push(node);
	while (!Q.empty())
	{
		int curLevelSize = Q.size();
		for (int i = 0; i < curLevelSize;i++)
		{
			BinaryTree* curNode = Q.top();
			cout << curNode->value << " ";
			if (leftToRight && curNode->right)
				Q.push(curNode);
		}
	}
}
int main()
{
	return 0;
}