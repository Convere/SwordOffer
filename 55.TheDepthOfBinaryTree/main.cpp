#include <iostream>
#include <algorithm>
#include <string>
#include "BinaryTree.h"

using namespace std;

//获取二叉树的最大深度
int getDepth(BinaryTree* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int num = 1;
	return num + max(getDepth(root->left), getDepth(root->right));
}
//判断是否是二叉树 用后序遍历的方式
bool isBalanced(BinaryTree* root, int *pDepth)
{
	if (root == nullptr)
	{
		*pDepth = 0;
		return true;
	}
	int left, right;
	if (isBalanced(root->left,&left) && isBalanced(root->right,&right))
	{
		int diff = left - right;
		if (diff <= 1 && diff >= -1)
		{
			*pDepth = 1 + (left > right ? left : right);
			return true;
		}
	}
	return false;
}
int main()
{
	BinaryTree* root = CreatBiTree();
	int depth = 0;
	cout << getDepth(root) << endl;
	string res = isBalanced(root, &depth) ? "true" : "false";
	int as = 0;
	cout << res << as << endl;
	system("pause");
}