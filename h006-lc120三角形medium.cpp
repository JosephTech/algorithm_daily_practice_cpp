/*
��ά���飬��߱�����һ��������

��һ��1��Ԫ��
�ڶ���2��Ԫ��
������3��Ԫ��
������4��Ԫ��
������

�� ���� �� �׶� �������ֺ� ��С��·������ÿ��ֻ�����¡�������������һ����
������ ֻ�����±ߵ�����λ����һ�� ��
���� ��С��
*/
#include <iostream>  // pause
#include <vector>  // std::vector
#include <algorithm>  // std::min

class Solution {
public:
	int minimumTotal(std::vector<std::vector<int>> &triangle) {  // ����������
		std::vector<std::vector<int>> dp;  // ����dp����
		for (int i = 0; i < triangle.size(); i++) {
			dp.push_back(std::vector<int> ());  // ������  �㰡
			for (int j = 0; j < triangle[i].size(); j++) {
				dp[i].push_back(0);
			}
		}
		// ���¶��ϣ��߽�
		for (int j = 0; j < triangle.size(); j++) {  // �м��У����һ�о��м���Ԫ�أ��㰡
			dp[triangle.size() - 1][j] = triangle[triangle.size() - 1][j];
		}
		for (int i = triangle.size() - 2; i >= 0; i--) {
			for (int j = 0; j < triangle[i].size(); j++) {
				dp[i][j] = std::min(dp[i+1][j+1], dp[i+1][j]) + triangle[i][j];
			}
		}
		return dp[0][0];
	}
};

int main() {
	std::vector<std::vector<int>> triangle = { {2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3} };
	Solution solve;
	printf("res = %d\n", solve.minimumTotal(triangle));

	system("pause");
	return 0;
}
