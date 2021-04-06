/*
����һ�������������ö������͵أ�in-place��ת��Ϊ������
�������нڵ�˳��Ϊ������ǰ�����˳��


���͵ص���˼���ǣ�����ʹ��vector���ִ�Ŀռ䣬ֻ�Ƕ��弸������û���⣩
*/
/*
˼����Ͷ��ȡ�ɵķ�����
	ǰ����������������ڵ�push��vector�� ˳�����vector�еĽڵ㣬�������ڵĽڵ㣬�γɵ�����
	����ָ��left�ÿգ���ָ��right�����Ľڵ�������

	�÷�����Ȼ����ͨ����Ŀ�����ǲ�����͵�ת����in-place���������� 
*/

#include <iostream>
#include <vector>

// ����������� ���ݽṹ
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	//���캯��
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void flatten(TreeNode *root) { //������ڵ㡣 ���÷��أ�ֱ���޸����нڵ������
		std::vector<TreeNode *> node_vec; //������нڵ�
		preorder(root, node_vec); //�ݹ���á������нڵ�ŵ�node_vec��
		for (int i = 1; i < node_vec.size(); i++) { //���ӣ�ǰһ����left�ÿգ� right���������
			node_vec[i - 1]->left = NULL;
			node_vec[i - 1]->right = node_vec[i];
		}
		//��root��node_vec[i-1]������node_vec[i]
	}

private:
	void preorder(TreeNode * node, //�������ã���Ϊ��һ��ָ�����
					std::vector<TreeNode *> &node_vec) { //���ã���Ϊ���vecҪ����ԭʼ��node_vec
		if (!node) { //��û�к��ӵ�ʱ�򣬵ݹ������������һ��ݹ�
			return;
		}
		node_vec.push_back(node); //ǰ����ӵ�node_vec
		preorder(node->left, node_vec); //������
		preorder(node->right, node_vec); //������
	}
};

int main() {
	TreeNode a(10);
	TreeNode b(20);
	TreeNode c(50);
	TreeNode e(30);
	TreeNode f(40);

	a.left = &b;
	a.right = &c;
	b.left = &e;
	b.right = &f;

	//ʵ���������ú���
	Solution solve;
	solve.flatten(&a);

	//��ӡ
	TreeNode * head = &a;
	while (head) {
		printf("[%d]", head->val);
		head = head->right;
	}

	system("pause");
	return 0;
}
