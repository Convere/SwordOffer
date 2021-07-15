#include <iostream>
#include <algorithm>
#include "BinaryTree.h"

using namespace std;
vector<int> postVec;
void postOrderTraversal(BinaryTree* tree)
{
	if (tree == nullptr)
		return;
	postOrderTraversal(tree->left);
	postOrderTraversal(tree->right);
	postVec.push_back(tree->value);
}
int main()
{
	BinaryTree* tree = CreatBiTree();
	postOrderTraversal(tree);
	for_each(postVec.begin(), postVec.end(), [](int a) { cout << a << " "; });
	cout << endl;
	system("pause");
	return 0;
}