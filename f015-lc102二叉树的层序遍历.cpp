/*
����
[
[3],
[9,20],
[15, 7]
]

��һ��һ�����飬�ڶ���һ�����顣����
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
	TreeNode(int x): val(x), left(NULL), right(NULL) {}  // ���캯��
};

class Solution {
public:
	vector<vector<int>> BFS(TreeNode* root) {  // ������ڵ�
		vector<vector<int>> res;

		if (!root)
			return res;  // �쳣����, ע����return res���������Ͳ�ƥ��
		
		queue<pair<TreeNode *, int>> Q;
		Q.push(make_pair(root, 0));
		while (!Q.empty()) {  // Q���յ�ʱ��Q.empty��false�����ԣ�����true
			TreeNode* node = Q.front().first;
			int layer = Q.front().second;
			Q.pop();

			if (layer == res.size())  // sizeΪ0��layerΪ0����һ���� sizeΪ1,layerΪ1,����һ��
				res.push_back(vector<int>() );  // ����
			
			res[layer].push_back(node->val);  // ע������if��ߵģ��ŵ���Ӧ��������

			if (node->left)
				Q.push(make_pair(node->left, layer+1));
			if (node->right)
				Q.push(make_pair(node->right, layer+1));  // �Ž�������
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

	Solution solve;  // ʵ����
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