/*
�桤�͵�ת��
*/
#include <iostream>

struct TreeNode { //����������ڵ�
	int val;
	TreeNode *left;
	TreeNode *right;
	//���캯��
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void change2list(TreeNode *root) { // ���� ������root�� root�Ǹ���ַ��ֱ�Ӹ�����ָ��
		TreeNode *last = NULL; //last��¼����һ���ڵ��ַ��Ҫ����һ������
		preorder(root, last); //�ݹ����
	}
private:
	//���ɣ�����һ������Ķ�����
	void preorder(TreeNode *node,
					TreeNode *&last) { //ָ������ã���Ϊ���lastҪһֱ�ı䣨�൱�ڷ��������ʱ���ȫ�ֱ�����
		if (!node) { //�ݹ������������һ��ݹ�
			return;
		}
		if (!node->left && !node->right) { //Ҷ�ڵ㣬Ҫ��ֵ��last��֮����Ҫ����
			last = node;
			return;
		}
		// ǰ���ݴ浱ǰ�ڵ�->left��right����һ�����ı���Щ���� ��ǰ-���֧-�ҷ�֧�� 
		// ͬʱ����last��������һ����οռ�
		TreeNode *record_left = node->left;
		TreeNode *record_right = node->right;
		TreeNode *left_last = NULL;
		TreeNode *right_last = NULL; //��ʱ�������ݴ��ҷֲ� ���һ���ڵ�
		if (record_left) { //�������֧
			preorder(record_left, left_last); // left_last������ֲ��last�ڵ�
			node->left = NULL; //�ÿ�
			node->right = record_left; //���� ��ǰ�ڵ�-�����֧��ʼ
			last = left_last; //����last����ֹû���ҷ�֧
		}
		if (record_right) { //�����ҷ�֧
			preorder(record_right, right_last); //right_last�����ҷ�֧��last�ڵ�
			if (record_left) {
				left_last->right = record_right; // ���� ���֧��last -���ҷ�֧��ʼ
												//ע�⣺last->left�϶�����NULL��
												//Ϊʲô���ڲ����ӣ� ��Ϊnode->right������NULL��
												// �����˵Ļ���last=left_last  
												//�൱��last�������˱����NULL,�������ϲ��ҷֲ棬���ڱ���
												//�����ڴ��ͻ
			}
			last = right_last; //����last
		}
	}
};

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

	//ʵ����������
	Solution solve;
	solve.change2list(&a);

	//��ӡ
	TreeNode *head = &a;
	while (head) {
		if (head->left) {
			printf("ERROR\n"); //��֤ÿ��node->left������NULL��
		}
		printf("[%d]",head->val);
		head = head->right;
	}
	printf("\n");
	system("pause");
	return 0;
}