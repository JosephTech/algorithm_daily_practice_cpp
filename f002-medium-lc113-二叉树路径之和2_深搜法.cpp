/*
给定一个二叉树与整数sum， 找出所有从根节点到叶节点的路径，
这些路径上的节点值累加和为sum
*/

/*
比较规范的代码，一般都不会用using namespace std;
一般都会把命名空间写出来std::vector
*/   

#include <iostream> //pause用
#include <vector> //当做栈用

//构建二叉树的节点
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	//构造函数
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	std::vector<std::vector<int>> pathEqualSum(TreeNode * root,int sum) { //传入和sum。 传入根节点指针root
		std::vector<std::vector<int>> result; // result是一串一串的 path
		int value_sum = 0; //是path的和。注意一定要初始化为0
		std::vector<int> path; //是一串路径path。栈的方式
		preorder(root, value_sum, sum, path, result); //递归调用
		return result; //返回结果
	}
private:
	void preorder(TreeNode *node, 
					int &value_sum, 
					int sum,
					std::vector<int> &path, 
					std::vector<std::vector<int>> &result) { //注意是引用的方式传入value_sum
		if (!node) { //递归结束条件。 如果空， 返回上层递归
			return;
		}
		//前序。将node->val压倒栈里、value累加上、是否等于sum,等于则push_back到result
		value_sum += node->val;
		path.push_back(node->val);
		if (value_sum == sum && !node->left && !node->right) {
			result.push_back(path);
		}
		preorder(node->left, value_sum, sum, path, result);
		preorder(node->right, value_sum, sum, path, result);
		//后序 (相当于回溯到上层节点，想象两层的二叉树，再想象三层的二叉树)
		value_sum -= node->val;
		path.pop_back();
	}
};

int main() {
	TreeNode a(5);
	TreeNode b(4);
	TreeNode c(8);
	TreeNode d(11);
	TreeNode e(13);
	TreeNode f(4);
	TreeNode g(7);
	TreeNode h(2);
	TreeNode x(5);
	TreeNode y(1);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	c.left = &e;
	c.right = &f;
	d.left = &g;
	d.right = &h;
	f.left = &x;
	f.right = &y;

	Solution solve;
	std::vector<std::vector<int>> result = solve.pathEqualSum(&a, 22);

	//打印
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			printf("[%d]", result[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}