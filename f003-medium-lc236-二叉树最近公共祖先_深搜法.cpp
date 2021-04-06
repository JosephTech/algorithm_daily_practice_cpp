/*
����Ĺ�������
��Ŀ��
	��֪����������������и����������ڵ������������ȡ�
	����������ȣ� ���ڵ�v��w�������������u������������ͣ������Զ����
	��v��w�����ڵ㶼��u�����

	��������������ȣ��ڵ��ָ�룩
*/
#include <iostream> //pause�õ�
#include <vector>

// ����TreeNode�� �������Ľڵ� �ṹ��/���ݽṹ
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	//���캯��
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode * lowestCommonAncestor(TreeNode * root, //������ڵ㡣 ���������ҽڵ�p��q 
									TreeNode * p,
									TreeNode * q){ //����p��q�Ĺ�������
		int finish = 0; //��ʼ��finish��־
		std::vector<TreeNode *> temp_path; //��������ʱ·�����ɻ��ݵ�
		std::vector<TreeNode *> p_res_path; 
		std::vector<TreeNode *> q_res_path; //���������·��
		preorder(root, p, temp_path, p_res_path, finish); //�ݹ���á� �ҵ�p_res_path
		finish = 0; //����
		temp_path.clear(); //����
		preorder(root, q, temp_path, q_res_path, finish); //�ݹ���á�  �ҵ�q_res_path
		// ˭�̣�len=˭
		int len = 0;
		if (p_res_path.size() < q_res_path.size()) {
			len = p_res_path.size();
		}
		else {
			len = q_res_path.size();
		}
		TreeNode * low_ancestor = 0; //������ �ȳ�ʼ��������ᱨ�������
		// ��������low_ancestor
		for (int i = 0; i < len; i++) {
			if (p_res_path[i] == q_res_path[i]) { //��ȣ��ʹ棬��������break�� ����Ҫдbreak
				low_ancestor = p_res_path[i];
			}
		}
		return low_ancestor;

	}

private:
	//preorder�ķ���������
	void preorder(TreeNode * node, //��ǰ�ڵ㡣 ����һ���Ǹ��ڵ�root��
						TreeNode * search, //�������ڵ�
						std::vector<TreeNode *> &path, // ��ʱ�ڵ�·����Ҫpop_back���ݵ�
						std::vector<TreeNode *> &result, // ���ս���ڵ�·��
						int &finish) { // ��־�Ƿ������
		//Ϊ�ζ������ã���Ϊ�൱��ȫ�ֱ���
		// c++��������Ƽ�ʹ������
		// ��ȫ�ֱ�����һ��ֻ���ڶ��߳�ʱ�򣬲�ʹ��
		if (!node || finish) { //��û�к��ӵ�ʱ�򣬻���finish==1��ʱ��ݹ������������һ��ݹ�
			return; // �ҵ��ˣ�finish==1����һֱ����,�˳�ÿ��ݹ�
		}
		//ǰ��node�浽path�С� �ҵ�search���path��ֵresult�� ���finish=1
		path.push_back(node);
		if (node == search) {
			result = path;
			finish = 1;
		}
		preorder(node->left, search, path, result, finish); //��������
		preorder(node->right,search, path, result, finish); //������
		//����
		path.pop_back(); //���ݵ���һ���ڵ�
	}
};

int main() {
	TreeNode a(3);
	TreeNode b(5);
	TreeNode c(1);
	TreeNode d(6);
	TreeNode e(2);
	TreeNode f(0);
	TreeNode x(8);
	TreeNode y(7);
	TreeNode z(4);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.left = &f;
	c.right = &x;
	e.left = &y;
	e.right = &z;

	//ʵ���������ú���
	Solution solve;
	TreeNode *result = solve.lowestCommonAncestor(&a, &b, &f);
	printf("lowestCommonAncestor = %d\n", result->val);

	result = solve.lowestCommonAncestor(&a, &d, &z);
	printf("lowestCommonAncestor = %d\n", result->val);

	result = solve.lowestCommonAncestor(&a, &b, &y);
	printf("lowestCommonAncestor = %d\n", result->val); //�����ȡ��ͻ

	system("pause");
	return 0;
}