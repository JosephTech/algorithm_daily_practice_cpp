/*
知识点：二叉树 宽度优先搜索
*/
/*
lc199-medium
题目：侧面观察二叉树
给定一个二叉树，假设从该二叉树的右侧观察它，将观察到的节点按照从上到下
的顺序输出
（输出为std::vector）
*/
/*
思路分析：
右侧观察，就是求层次遍历二叉树时候，每一层的最后一个节点
*/
/*
算法思路：
	层次遍历时候，将节点与层数 绑定为pair。 
	压入队列时，将节点和层数同时压入队列，并记录每一层中出现的最后一个节点

	在层次遍历中，每一层中的最后一个节点最后遍历到，随时更新每层的最后一个节点
	存在vector里。 （view[0]代表第0层...）
*/

#include <iostream> //pause用的
#include <queue> //队列用的
#include <vector> //数组用的

// 二叉树，数据结构
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	//构造函数
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	std::vector<int> rightSideView(TreeNode *root) { //传入 根节点的指针
		std::queue<std::pair<TreeNode *, int>> Q; //维护一个队列，队列里边装的是 <节点的指针，层号>
		std::vector<int> right_view; //每个位置代表当前层最右侧节点
		if (root) {
			Q.push(std::make_pair(root, 0)); //push进去
		}
		while (!Q.empty()) { //非空，就取出来，弹出来。 left和right塞进队列
			TreeNode *node = Q.front().first; //当前节点
			int depth = Q.front().second; //当前层数
			Q.pop(); //弹出，说明这个节点利用完了
			if (depth == right_view.size()) { //层数 等于 数组长度。 把当前层push进去
				right_view.push_back(node->val); //size 0,depth 0
			}
			else { //更新右侧节点
				right_view[depth] = node->val;
			}
			if (node->left) { //左节点 放到队列里
				Q.push(std::make_pair(node->left, depth+1));
			}
			if (node->right) { //右节点，放到队列里
				Q.push(std::make_pair(node->right, depth + 1));
			} 
			//注意： 二叉树，每个节点就left和right俩分叉，所以，push到队列里，
		}
		return right_view; 
	}
};

int main() {
	TreeNode a(1), b(2), c(5), d(3), e(4), f(6);
	a.left = &b;
	a.right = &c;

	b.left = &d;
	b.right = &e;

	c.right = &f;
	//实例化、调用、打印
	Solution solve;
	std::vector<int> result= solve.rightSideView(&a);
	for (int i = 0; i < result.size(); i++) {
		printf("%d\n", result[i]);
	}

	system("pause");
	return 0;
}



