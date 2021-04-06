/*
����һ��������������sum�� �ҳ����дӸ��ڵ㵽Ҷ�ڵ��·����
��Щ·���ϵĽڵ�ֵ�ۼӺ�Ϊsum
*/

/*
�ȽϹ淶�Ĵ��룬һ�㶼������using namespace std;
һ�㶼��������ռ�д����std::vector
*/   

#include <iostream> //pause��
#include <vector> //����ջ��

//�����������Ľڵ�
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	//���캯��
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	std::vector<std::vector<int>> pathEqualSum(TreeNode * root,int sum) { //�����sum�� ������ڵ�ָ��root
		std::vector<std::vector<int>> result; // result��һ��һ���� path
		int value_sum = 0; //��path�ĺ͡�ע��һ��Ҫ��ʼ��Ϊ0
		std::vector<int> path; //��һ��·��path��ջ�ķ�ʽ
		preorder(root, value_sum, sum, path, result); //�ݹ����
		return result; //���ؽ��
	}
private:
	void preorder(TreeNode *node, 
					int &value_sum, 
					int sum,
					std::vector<int> &path, 
					std::vector<std::vector<int>> &result) { //ע�������õķ�ʽ����value_sum
		if (!node) { //�ݹ���������� ����գ� �����ϲ�ݹ�
			return;
		}
		//ǰ�򡣽�node->valѹ��ջ�value�ۼ��ϡ��Ƿ����sum,������push_back��result
		value_sum += node->val;
		path.push_back(node->val);
		if (value_sum == sum && !node->left && !node->right) {
			result.push_back(path);
		}
		preorder(node->left, value_sum, sum, path, result);
		preorder(node->right, value_sum, sum, path, result);
		//���� (�൱�ڻ��ݵ��ϲ�ڵ㣬��������Ķ�����������������Ķ�����)
		value_sum -= node->val;
		path.pop_back();
	}
};

int main() {
	TreeNode a(5);
	TreeNode b(4);
	TreeNode c(8);
	TreeNode d(11);
	TreeNode e(13);
	TreeNode f(4);
	TreeNode g(7);
	TreeNode h(2);
	TreeNode x(5);
	TreeNode y(1);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	c.left = &e;
	c.right = &f;
	d.left = &g;
	d.right = &h;
	f.left = &x;
	f.right = &y;

	Solution solve;
	std::vector<std::vector<int>> result = solve.pathEqualSum(&a, 22);

	//��ӡ
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			printf("[%d]", result[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}