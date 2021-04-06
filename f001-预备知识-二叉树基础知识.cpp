/*
����n (n>=0)���ڵ�����޼��� ����Щ�ڵ��������¹�ϵ��
	1�����ҽ���һ���ڵ�û�и��ڵ㣬�ýڵ��Ϊ���ĸ�
	2�������⣬����ÿ���ڵ㶼���ҽ���һ�����ڵ�
	3������ÿһ���ڵ� ������һ������Ϊ������
	4����������������������ʱ����������������
	ÿ���ڵ�������������ӣ�������������������������֮�֣����򲻿ɵߵ�
*/
// Ԥ��֪ʶ���������Ĺ���

#include <iostream>

// �ṹ�塣 ���ڵ�
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	//���캯��
	TreeNode(int x) : val(x), left(NULL), right(NULL) {} //Ĭ��NULL����ֹ��
};

void preorder_print(TreeNode *node, int layer) {
	if (!node) { //�ݹ������
		return;
	}
	for (int i = 0; i < layer; i++) {
		printf("----"); //��0�㲻��ӡ����1���ӡ----����2���ӡ-------- 
	}
	printf("[%d]\n", node->val);
	preorder_print(node->left, layer + 1); //�ݹ����
	preorder_print(node->right, layer + 1);
}

int main() {
	TreeNode a(10);
	TreeNode b(20);
	TreeNode c(50);
	TreeNode d(30);
	TreeNode e(40);
	TreeNode f(60);

	a.left = &b;
	a.right = &c;

	b.left = &d;
	b.right = &e;

	c.right = &f;

	preorder_print(&a, 0); //�ݹ����

	system("pause");
	return 0;
}