#pragma once
#include <iostream>

using namespace std;
struct BinaryTree
{
	BinaryTree* left = nullptr;
	BinaryTree* right = nullptr;
	int value;
	BinaryTree(int a, BinaryTree* l, BinaryTree* r) :
		value(a), left(l), right(r) {}
	BinaryTree(int a) :value(a) {}
};

void CreatBiTree(BinaryTree **T) /* BiTree *T等价于 struct node **T    */
{
	char ch;
	scanf_s("%c", &ch);
	if (ch == '#')    /* 当遇到#时，令树的结点为NULL，从而结束该分支的递归 */
	{
		*T = NULL;
	}
	else
	{
		*T = (BinaryTree*)malloc(sizeof(BinaryTree));
		if (*T == NULL)
		{
			printf("内存分配失败");
			exit(0);
		}
		(*T)->value = ch;        /* 生成结点 */
		CreatBiTree(&(*T)->left);    /* 构造左子树 */
		CreatBiTree(&(*T)->right);    /* 构造右子树 */
		/* 这里需要注意的是->的优先级比&高，所以&(*T)->lchild得到的是lchild的地址 */
	}
}
void PreOrderTraverse(BinaryTree* t)
{
	if (t == NULL)
	{
		return;
	}
	printf("data = %c ", t->value);
	PreOrderTraverse(t->left);
	PreOrderTraverse(t->right);
}

void MidOrderTraverse(BinaryTree* t, int level)
{
	if (t == NULL)
	{
		return;
	}
	MidOrderTraverse(t->left, level + 1);
	printf("data = %c level = %d\n ", t->value, level);
	MidOrderTraverse(t->right, level + 1);
}

void PosOrderTraverse(BinaryTree* t, int level)
{
	if (t == NULL)
	{
		return;
	}
	PosOrderTraverse(t->left, level + 1);
	PosOrderTraverse(t->right, level + 1);
	printf("data = %c level = %d\n ", t->value, level);
}