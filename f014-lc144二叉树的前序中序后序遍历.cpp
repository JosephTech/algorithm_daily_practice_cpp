/*
题目：
二叉树的前序遍历
*/
#include <iostream>  // pause
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;  // 左 地址域
	TreeNode* right;  // 右 地址域
	TreeNode(int x): val(x), left(NULL), right(NULL) {}  // 构造函数
};

class Solution {
public:
	void preorder(TreeNode *node) {  // 传入节点
		if (!node)
			return;  // 也可以，if(node)套着下边的三行
		cout <<"前序:" << node->val << endl;  // 前序
		preorder(node->left);
		cout << "中序:" << node->val << endl;
		preorder(node->right);
		cout << "后序:" << node->val <<endl;
	}
};

int main() {
	TreeNode a(1), b(2), c(5), d(3), e(4), f(6) , g(7);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.left = &f;
	c.right = &g;

	Solution solve;  // 实例化
	solve.preorder(&a);

	system("pause");
	return 0;
}