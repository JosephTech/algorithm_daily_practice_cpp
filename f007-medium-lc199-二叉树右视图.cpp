/*
֪ʶ�㣺������ �����������
*/
/*
lc199-medium
��Ŀ������۲������
����һ��������������Ӹö��������Ҳ�۲��������۲쵽�Ľڵ㰴�մ��ϵ���
��˳�����
�����Ϊstd::vector��
*/
/*
˼·������
�Ҳ�۲죬�������α���������ʱ��ÿһ������һ���ڵ�
*/
/*
�㷨˼·��
	��α���ʱ�򣬽��ڵ������ ��Ϊpair�� 
	ѹ�����ʱ�����ڵ�Ͳ���ͬʱѹ����У�����¼ÿһ���г��ֵ����һ���ڵ�

	�ڲ�α����У�ÿһ���е����һ���ڵ�������������ʱ����ÿ������һ���ڵ�
	����vector� ��view[0]�����0��...��
*/

#include <iostream> //pause�õ�
#include <queue> //�����õ�
#include <vector> //�����õ�

// �����������ݽṹ
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	//���캯��
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	std::vector<int> rightSideView(TreeNode *root) { //���� ���ڵ��ָ��
		std::queue<std::pair<TreeNode *, int>> Q; //ά��һ�����У��������װ���� <�ڵ��ָ�룬���>
		std::vector<int> right_view; //ÿ��λ�ô���ǰ�����Ҳ�ڵ�
		if (root) {
			Q.push(std::make_pair(root, 0)); //push��ȥ
		}
		while (!Q.empty()) { //�ǿգ���ȡ�������������� left��right��������
			TreeNode *node = Q.front().first; //��ǰ�ڵ�
			int depth = Q.front().second; //��ǰ����
			Q.pop(); //������˵������ڵ���������
			if (depth == right_view.size()) { //���� ���� ���鳤�ȡ� �ѵ�ǰ��push��ȥ
				right_view.push_back(node->val); //size 0,depth 0
			}
			else { //�����Ҳ�ڵ�
				right_view[depth] = node->val;
			}
			if (node->left) { //��ڵ� �ŵ�������
				Q.push(std::make_pair(node->left, depth+1));
			}
			if (node->right) { //�ҽڵ㣬�ŵ�������
				Q.push(std::make_pair(node->right, depth + 1));
			} 
			//ע�⣺ ��������ÿ���ڵ��left��right���ֲ棬���ԣ�push�������
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
	//ʵ���������á���ӡ
	Solution solve;
	std::vector<int> result= solve.rightSideView(&a);
	for (int i = 0; i < result.size(); i++) {
		printf("%d\n", result[i]);
	}

	system("pause");
	return 0;
}



