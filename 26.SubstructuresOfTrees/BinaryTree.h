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

void CreatBiTree(BinaryTree **T) /* BiTree *T�ȼ��� struct node **T    */
{
	char ch;
	scanf_s("%c", &ch);
	if (ch == '#')    /* ������#ʱ�������Ľ��ΪNULL���Ӷ������÷�֧�ĵݹ� */
	{
		*T = NULL;
	}
	else
	{
		*T = (BinaryTree*)malloc(sizeof(BinaryTree));
		if (*T == NULL)
		{
			printf("�ڴ����ʧ��");
			exit(0);
		}
		(*T)->value = ch;        /* ���ɽ�� */
		CreatBiTree(&(*T)->left);    /* ���������� */
		CreatBiTree(&(*T)->right);    /* ���������� */
		/* ������Ҫע�����->�����ȼ���&�ߣ�����&(*T)->lchild�õ�����lchild�ĵ�ַ */
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