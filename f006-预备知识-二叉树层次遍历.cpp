/*
二叉树层次遍历：宽搜
*/


#include <queue> //队列
#include <iostream> // pause用的

//数据类型。构造二叉树节点
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	//构造函数
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void BTS_wide_print(TreeNode *root) { //传入根节点
	std::queue<TreeNode *> Q; //创建队列
	Q.push(root); //把根节点放进队列
	while (!Q.empty()) { //队列不空的时候
		TreeNode *node = Q.front(); //队列最前端
		printf("[%d]\n", node->val); //打印
		Q.pop(); //弹出
		if (node->left) {
			Q.push(node->left);
		}
		if (node->right) {
			Q.push(node->right);
		}
	}
}

int main() {
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(5);
	TreeNode d(3);
	TreeNode e(4);
	TreeNode f(6);

	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.right = &f;

	BTS_wide_print(&a);

	system("pause");
	return 0;
}

