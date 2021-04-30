/*
返回
[
[3],
[9,20],
[15, 7]
]

第一层一个数组，第二层一个数组。。。
vector<vector<int>>
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}  // 构造函数
};

class Solution {
public:
	vector<vector<int>> BFS(TreeNode* root) {  // 传入根节点
		vector<vector<int>> res;

		if (!root)
			return res;  // 异常处理, 注意是return res，否则类型不匹配
		
		queue<pair<TreeNode *, int>> Q;
		Q.push(make_pair(root, 0));
		while (!Q.empty()) {  // Q不空的时候，Q.empty是false，所以！就是true
			TreeNode* node = Q.front().first;
			int layer = Q.front().second;
			Q.pop();

			if (layer == res.size())  // size为0，layer为0则添一个。 size为1,layer为1,则添一个
				res.push_back(vector<int>() );  // 匿名
			
			res[layer].push_back(node->val);  // 注意是在if外边的，放到对应的数组里

			if (node->left)
				Q.push(make_pair(node->left, layer+1));
			if (node->right)
				Q.push(make_pair(node->right, layer+1));  // 放进队列里
		}
		return res;
	}
};

int main() {
	TreeNode a(3), b(9), c(20), d(15), e(7);
	a.left = &b;
	a.right = &c;
	c.left = &d;
	c.right = &e;

	Solution solve;  // 实例化
	vector<vector<int>> res = solve.BFS(&a);

	for (int i = 0; i < res.size(); i++) {
		printf("[");
		for (int j = 0; j < res[i].size(); j++) {
			printf("%d,", res[i][j]);
		}
		printf("]\n");
	}

	system("pause");
	return 0;
}