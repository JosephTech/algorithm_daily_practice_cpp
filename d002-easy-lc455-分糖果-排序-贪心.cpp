/*
��֪һЩ���Ӻ�һЩ�ǹ���ÿ����������������g��ÿ���ǹ��д�Сs�� ��ĳ���ǹ�
�Ĵ�Сs>=ĳ�����ӵ���������gʱ��������ǹ���������ú��ӣ�
��ʹ����Щ�ǹ��������������ٸ����ӣ� ��ע�⣺ĳ���������ֻ����һ���ǹ����㣩
*/

/*
���磺
	������������g = [5, 10, 2, 9, 15, 9];
	�ǹ���С����s = [6, 1, 20, 3, 8];
	����������3�����ӡ�
	����1s ˭Ҳ������  3s��2g��  6s��5g��  8s˭Ҳ������  20s��9g��
*/
/*
˼·��
	������ + ��̰��

	̰�ģ�
		�����������󣨴�С���󣩣�����С���ǣ����ú��ӡ���ʳ�ð��̣�

Ϊʲô��С����
	��Ϊ����������С�ģ���������
*/
/*
�㷨˼·��
	1����������������g �� �ǹ���С����s ��С��������
	2�����մ�С������ǹ� ���Ը�ĳ�����ӣ������㣬
												�ͻ���һ�����ӡ���ͬʱ������һ���ǹ�~�ǹ�ĩβ��
												ֱ��û�к��� ���� û����
*/

#include <iostream> // pause�õ�
#include <vector>
#include <algorithm> // �����std::sort

class Solution {
public:
	// ���ر����㺢�ӵĸ���
	int findContentChildren(std::vector<int> &g, std::vector<int> &s) { //�������ã������
		std::sort(g.begin(), g.end()); //����
		std::sort(s.begin(), s.end());
		int child = 0; //������������g�õ�
		int cookie = 0; //�����ǹ���С�õ�
		while (child < g.size() && cookie < s.size()) { // ������ ���� ���к���ʱ��
			if (g[child] <= s[cookie]) { //���ǹ� ���㺢�ӵ����� (ע����С�ڵ���)
				child++; //��һ�����ӡ�
				// �˴������Դ���һ��vector���
			}
			cookie++; //������
		}
		return child; // ���絽��child = 3��û�����㣬��˵�� ������3�����ӣ�0  1  2��
	}

};

int main() {
	std::vector<int> g;
	g.push_back(5);
	g.push_back(10);
	g.push_back(2);
	g.push_back(9);
	g.push_back(15);
	g.push_back(9);

	std::vector<int> s;
	s.push_back(6);
	s.push_back(1);
	s.push_back(20);
	s.push_back(3);
	s.push_back(8);

	Solution solve;
	int num = solve.findContentChildren(g, s);
	printf("������%d������\n",num);

	system("pause");
	return 0;
}