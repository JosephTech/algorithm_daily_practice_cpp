/*
给定一个二叉树，将该二叉树就地（in-place）转换为单链表。
单链表中节点顺序为二叉树前序遍历顺序。


（就地的意思就是，不能使用vector这种大的空间，只是定义几个变量没问题）
*/
/*
思考，投机取巧的方法：
	前序遍历二叉树，将节点push进vector， 顺序遍历vector中的节点，连接相邻的节点，形成单链表
	（左指针left置空，右指针right与后面的节点相连）

	该方法虽然可以通过题目，但是不满足就地转换（in-place）的条件。 
*/

#include <iostream>
#include <vector>

// 构造二叉树； 数据结构
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	//构造函数
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void flatten(TreeNode *root) { //传入根节点。 不用返回，直接修改所有节点就行了
		std::vector<TreeNode *> node_vec; //存放所有节点
		preorder(root, node_vec); //递归调用。把所有节点放到node_vec中
		for (int i = 1; i < node_vec.size(); i++) { //连接，前一个的left置空， right连现在这个
			node_vec[i - 1]->left = NULL;
			node_vec[i - 1]->right = node_vec[i];
		}
		//则root是node_vec[i-1]连上了node_vec[i]
	}

private:
	void preorder(TreeNode * node, //不用引用，因为就一个指针而已
					std::vector<TreeNode *> &node_vec) { //引用，因为这个vec要操作原始的node_vec
		if (!node) { //当没有孩子的时候，递归结束，返回上一层递归
			return;
		}
		node_vec.push_back(node); //前序，添加到node_vec
		preorder(node->left, node_vec); //左子树
		preorder(node->right, node_vec); //右子树
	}
};

int main() {
	TreeNode a(10);
	TreeNode b(20);
	TreeNode c(50);
	TreeNode e(30);
	TreeNode f(40);

	a.left = &b;
	a.right = &c;
	b.left = &e;
	b.right = &f;

	//实例化、调用函数
	Solution solve;
	solve.flatten(&a);

	//打印
	TreeNode * head = &a;
	while (head) {
		printf("[%d]", head->val);
		head = head->right;
	}

	system("pause");
	return 0;
}
