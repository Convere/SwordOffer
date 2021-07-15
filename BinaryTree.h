#pragma once
#include <vector>
#include <queue>

using namespace std;
struct BinaryTree
{
	BinaryTree(int a ):value(a){}
	BinaryTree() {}
	int value;
	BinaryTree* left = nullptr;
	BinaryTree* right = nullptr;

};
BinaryTree* CreatBiTree()
{
	vector<BinaryTree*> biTv;
	biTv.push_back(new BinaryTree(0));
	biTv.push_back(new BinaryTree(1));
	biTv.push_back(new BinaryTree(2));
	biTv.push_back(new BinaryTree(3));
	biTv.push_back(new BinaryTree(4));
	biTv.push_back(new BinaryTree(5));
	biTv.push_back(new BinaryTree(6));
	biTv.push_back(new BinaryTree(7));
	biTv.push_back(new BinaryTree(8));
	biTv.push_back(new BinaryTree(9));
	biTv.push_back(new BinaryTree(10));
	biTv.push_back(new BinaryTree(11));
	BinaryTree* node8 = biTv.at(8);
	node8->left = biTv[6];
	node8->right = biTv[10];
	biTv[6]->left = biTv[5];
	biTv[6]->right = biTv[7];
	biTv[10]->left = biTv[9];
	biTv[10]->right = biTv[11];
	return node8;
}

void levelTraversal(BinaryTree* root)
{
	vector<vector<int>> ret;
	if (root == nullptr)
	{
		return;
	}
	queue<BinaryTree*> Q;
	Q.push(root);
	while (!Q.empty())
	{
		int curLevelSize = Q.size();
		ret.push_back(vector<int>());
		for (int i = 0; i < curLevelSize; i++)
		{
			BinaryTree* node = Q.front();
			ret.back().push_back(node->value);

			if (node->left)
			{
				Q.push(node->left);
			}
			if (node->right)
			{
				Q.push(node->right);
			}
			Q.pop();
		}
	}
	for (int i = 0; i < ret.size(); i++)
	{
		cout << "[";
		for (int j = 0; j < ret[i].size(); j++)
		{
			if (j == ret[i].size() - 1)
			{
				cout << ret[i][j];
			}
			else
				cout << ret[i][j] << ",";
		}
		cout << "]" << endl;
	}
}

void preorderTraversal(BinaryTree* root)//ÏÈÐò±éÀú
{
	if (root == nullptr)
	{
		return;
	}
	cout << root->value << " ";
	preorderTraversal(root->left);
	preorderTraversal(root->right);
	cout << endl;
}