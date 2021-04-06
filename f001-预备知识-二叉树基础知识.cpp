/*
树是n (n>=0)个节点的有限集， 且这些节点满足如下关系：
	1、有且仅有一个节点没有父节点，该节点称为数的根
	2、除根外，其余每个节点都有且仅有一个父节点
	3、树中每一个节点 都构成一个以它为根的树
	4、二叉树在满足树的条件时，满足如下条件：
	每个节点最多有两个孩子（子树），这两个子树有左右之分，次序不可颠倒
*/
// 预备知识：二叉树的构造

#include <iostream>

// 结构体。 树节点
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	//构造函数
	TreeNode(int x) : val(x), left(NULL), right(NULL) {} //默认NULL，防止空
};

void preorder_print(TreeNode *node, int layer) {
	if (!node) { //递归结束，
		return;
	}
	for (int i = 0; i < layer; i++) {
		printf("----"); //第0层不打印，第1层打印----，第2层打印-------- 
	}
	printf("[%d]\n", node->val);
	preorder_print(node->left, layer + 1); //递归调用
	preorder_print(node->right, layer + 1);
}

int main() {
	TreeNode a(10);
	TreeNode b(20);
	TreeNode c(50);
	TreeNode d(30);
	TreeNode e(40);
	TreeNode f(60);

	a.left = &b;
	a.right = &c;

	b.left = &d;
	b.right = &e;

	c.right = &f;

	preorder_print(&a, 0); //递归调用

	system("pause");
	return 0;
}