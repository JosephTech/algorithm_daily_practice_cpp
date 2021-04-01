/*
��������α���������
*/


#include <queue> //����
#include <iostream> // pause�õ�

//�������͡�����������ڵ�
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	//���캯��
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void BTS_wide_print(TreeNode *root) { //������ڵ�
	std::queue<TreeNode *> Q; //��������
	Q.push(root); //�Ѹ��ڵ�Ž�����
	while (!Q.empty()) { //���в��յ�ʱ��
		TreeNode *node = Q.front(); //������ǰ��
		printf("[%d]\n", node->val); //��ӡ
		Q.pop(); //����
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

