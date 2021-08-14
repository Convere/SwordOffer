#include <iostream>

struct BinaryTreeNode
{
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};

void mirrorCopy(BinaryTreeNode* root)
{
	if (root == nullptr)
	{
		return ;
	}
	if (root->left == nullptr && root->right == nullptr)
	{
		return;
	}
	BinaryTreeNode* temp = root->left;
	root->left = root->right;
	root->right = temp;

	if (root->left)
	{
		mirrorCopy(root->left);
	}
	if (root->right)
	{
		mirrorCopy(root->right);
	}
}
int main()
{
	system("pause");
	return 0;
}