/*
��Ŀ��Դ��
	��ָoffer27
��Ŀ��
	����һ�������������ҷ�ת
*/
/*
˼·1��
	���ѷ�dfs��
	�ݹ飬ǰ��ʱ�򽻻�ÿ���ڵ�� ����ָ��  ��ע���ǽ���ָ�룩
*/
/*
˼·2��
	���ѷ���
*/
/*
�ο����ϣ�
	ţ���������������ľ���C++��python��
	https://blog.csdn.net/qq_27060423/article/details/93923358?utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-1.control&dist_request_id=1328769.80483.16177594942453045&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-1.control
*/
#include <iostream>  // pause
#include <queue>  //  std::queue

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}  // ���캯��
};


class Solution {
public:
	void mirror(TreeNode * root) {  // ������ڵ�ָ�롣
		if (!root)
			return;  // �Ͻ���
		dfs(root);  // ����
	}
private:
	void dfs(TreeNode *node) {  // ���ѣ��ݹ�
		if (!node)
			return;
		std::swap(node->left, node->right);  // ǰ�򽻻�ָ�룬 ָ����һ������
		//TreeNode *p = node->left;
		//TreeNode *q = node->right;
		//node->left = q;
		//node->right = p;
		dfs(node->left);
		dfs(node->right);
	}
};

void preorder(TreeNode *node) {  // dfs��ӡ
	if (!node)
		return;
	printf("%d\n", node->val);
	preorder(node->left);
	preorder(node->right);
}

int main() {
	TreeNode a(8), b(6), c(10), d(5), e(7), f(9), g(11);

	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.left = &f;
	c.right = &g;

	Solution solve;
	solve.mirror(&a);

	TreeNode *head = &a;
	
	preorder(&a);

	system("pause");
	return 0;
}