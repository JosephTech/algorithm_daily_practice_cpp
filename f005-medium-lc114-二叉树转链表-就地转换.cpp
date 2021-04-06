/*
真·就地转换
*/
#include <iostream>

struct TreeNode { //构造二叉树节点
	int val;
	TreeNode *left;
	TreeNode *right;
	//构造函数
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void change2list(TreeNode *root) { // 传入 二叉树root。 root是个地址，直接改它的指向
		TreeNode *last = NULL; //last记录最后的一个节点地址，要和下一段相连
		preorder(root, last); //递归调用
	}
private:
	//技巧，想象一个两层的二叉树
	void preorder(TreeNode *node,
					TreeNode *&last) { //指针的引用，因为这个last要一直改变（相当于非面向对象时候的全局变量）
		if (!node) { //递归结束，返回上一层递归
			return;
		}
		if (!node->left && !node->right) { //叶节点，要赋值给last，之后需要连接
			last = node;
			return;
		}
		// 前序、暂存当前节点->left和right。下一步，改变这些连接 当前-左分支-右分支。 
		// 同时更新last，返回上一层盗梦空间
		TreeNode *record_left = node->left;
		TreeNode *record_right = node->right;
		TreeNode *left_last = NULL;
		TreeNode *right_last = NULL; //临时变量，暂存右分叉 最后一个节点
		if (record_left) { //若有左分支
			preorder(record_left, left_last); // left_last会变成左分叉的last节点
			node->left = NULL; //置空
			node->right = record_left; //连接 当前节点-》左分支开始
			last = left_last; //更新last，防止没有右分支
		}
		if (record_right) { //若有右分支
			preorder(record_right, right_last); //right_last会变成右分支的last节点
			if (record_left) {
				left_last->right = record_right; // 连接 左分支的last -》右分支开始
												//注意：last->left肯定都是NULL的
												//为什么现在才连接？ 因为node->right可能是NULL的
												// 连早了的话，last=left_last  
												//相当于last既连接了本层的NULL,又连接上层右分叉，绝壁报错
												//访问内存冲突
			}
			last = right_last; //更新last
		}
	}
};

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

	//实例化、调用
	Solution solve;
	solve.change2list(&a);

	//打印
	TreeNode *head = &a;
	while (head) {
		if (head->left) {
			printf("ERROR\n"); //验证每个node->left都被置NULL了
		}
		printf("[%d]",head->val);
		head = head->right;
	}
	printf("\n");
	system("pause");
	return 0;
}