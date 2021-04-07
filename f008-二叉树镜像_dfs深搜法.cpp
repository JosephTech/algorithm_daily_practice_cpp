/*
题目来源：
	剑指offer27
题目：
	给定一个二叉树，左右翻转
*/
/*
思路1：
	深搜法dfs：
	递归，前序时候交换每个节点的 左右指针  （注意是交换指针）
*/
/*
思路2：
	宽搜法：
*/
/*
参考资料：
	牛客网——二叉树的镜像（C++、python）
	https://blog.csdn.net/qq_27060423/article/details/93923358?utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-1.control&dist_request_id=1328769.80483.16177594942453045&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-1.control
*/
#include <iostream>  // pause
#include <queue>  //  std::queue

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}  // 构造函数
};


class Solution {
public:
	void mirror(TreeNode * root) {  // 传入根节点指针。
		if (!root)
			return;  // 严谨了
		dfs(root);  // 深搜
	}
private:
	void dfs(TreeNode *node) {  // 深搜，递归
		if (!node)
			return;
		std::swap(node->left, node->right);  // 前序交换指针， 指向另一个子树
		//TreeNode *p = node->left;
		//TreeNode *q = node->right;
		//node->left = q;
		//node->right = p;
		dfs(node->left);
		dfs(node->right);
	}
};

void preorder(TreeNode *node) {  // dfs打印
	if (!node)
		return;
	printf("%d\n", node->val);
	preorder(node->left);
	preorder(node->right);
}

int main() {
	TreeNode a(8), b(6), c(10), d(5), e(7), f(9), g(11);

	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.left = &f;
	c.right = &g;

	Solution solve;
	solve.mirror(&a);

	TreeNode *head = &a;
	
	preorder(&a);

	system("pause");
	return 0;
}