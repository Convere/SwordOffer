#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main()
{
	BinaryTree* newtree;
	CreatBiTree(&newtree);
	PreOrderTraverse(newtree);
}