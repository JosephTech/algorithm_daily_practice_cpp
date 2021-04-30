/*
��Ŀ��
��������ǰ�����
*/
#include <iostream>  // pause
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;  // �� ��ַ��
	TreeNode* right;  // �� ��ַ��
	TreeNode(int x): val(x), left(NULL), right(NULL) {}  // ���캯��
};

class Solution {
public:
	void preorder(TreeNode *node) {  // ����ڵ�
		if (!node)
			return;  // Ҳ���ԣ�if(node)�����±ߵ�����
		cout <<"ǰ��:" << node->val << endl;  // ǰ��
		preorder(node->left);
		cout << "����:" << node->val << endl;
		preorder(node->right);
		cout << "����:" << node->val <<endl;
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

	Solution solve;  // ʵ����
	solve.preorder(&a);

	system("pause");
	return 0;
}