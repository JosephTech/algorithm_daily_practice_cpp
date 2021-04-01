/*
最近的公共祖先
题目：
	已知二叉树，求二叉树中给定的两个节点的最近公共祖先。
	最近公共祖先： 两节点v与w的最近公共祖先u，满足树上最低（离根最远），
	且v，w两个节点都是u的子孙。

	返回最近公共祖先（节点的指针）
*/
#include <iostream> //pause用的
#include <vector>

// 构建TreeNode。 二叉树的节点 结构体/数据结构
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	//构造函数
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode * lowestCommonAncestor(TreeNode * root, //传入根节点。 两个待查找节点p、q 
									TreeNode * p,
									TreeNode * q){ //返回p、q的公共祖先
		int finish = 0; //初始化finish标志
		std::vector<TreeNode *> temp_path; //声明，临时路径，可回溯的
		std::vector<TreeNode *> p_res_path; 
		std::vector<TreeNode *> q_res_path; //声明，结果路径
		preorder(root, p, temp_path, p_res_path, finish); //递归调用。 找到p_res_path
		finish = 0; //重置
		temp_path.clear(); //重置
		preorder(root, q, temp_path, q_res_path, finish); //递归调用。  找到q_res_path
		// 谁短，len=谁
		int len = 0;
		if (p_res_path.size() < q_res_path.size()) {
			len = p_res_path.size();
		}
		else {
			len = q_res_path.size();
		}
		TreeNode * low_ancestor = 0; //存结果。 先初始化，否则会报代码错误
		// 遍历，找low_ancestor
		for (int i = 0; i < len; i++) {
			if (p_res_path[i] == q_res_path[i]) { //相等，就存，这样不用break。 不等要写break
				low_ancestor = p_res_path[i];
			}
		}
		return low_ancestor;

	}

private:
	//preorder的翻译是先序
	void preorder(TreeNode * node, //当前节点。 （第一轮是根节点root）
						TreeNode * search, //待搜索节点
						std::vector<TreeNode *> &path, // 临时节点路径。要pop_back回溯的
						std::vector<TreeNode *> &result, // 最终结果节点路径
						int &finish) { // 标志是否结束。
		//为何都用引用，因为相当于全局变量
		// c++面向对象，推荐使用引用
		// 而全局变量，一般只有在多线程时候，才使用
		if (!node || finish) { //当没有孩子的时候，或者finish==1的时候递归结束。返回上一层递归
			return; // 找到了，finish==1，就一直返回,退出每层递归
		}
		//前序、node存到path中。 找到search则把path赋值result。 标记finish=1
		path.push_back(node);
		if (node == search) {
			result = path;
			finish = 1;
		}
		preorder(node->left, search, path, result, finish); //中序、左孩子
		preorder(node->right,search, path, result, finish); //右子树
		//后序
		path.pop_back(); //回溯到上一个节点
	}
};

int main() {
	TreeNode a(3);
	TreeNode b(5);
	TreeNode c(1);
	TreeNode d(6);
	TreeNode e(2);
	TreeNode f(0);
	TreeNode x(8);
	TreeNode y(7);
	TreeNode z(4);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.left = &f;
	c.right = &x;
	e.left = &y;
	e.right = &z;

	//实例化、调用函数
	Solution solve;
	TreeNode *result = solve.lowestCommonAncestor(&a, &b, &f);
	printf("lowestCommonAncestor = %d\n", result->val);

	result = solve.lowestCommonAncestor(&a, &d, &z);
	printf("lowestCommonAncestor = %d\n", result->val);

	result = solve.lowestCommonAncestor(&a, &b, &y);
	printf("lowestCommonAncestor = %d\n", result->val); //报错读取冲突

	system("pause");
	return 0;
}