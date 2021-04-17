/*
��ά���飬ֻ������ ���� ����

����С·����
*/

#include <iostream>  // pause
#include <vector>  // std::vector
#include <algorithm>  // std::min

class Solution {
public:
	int minPathSum(std::vector<std::vector<int>> &grid) {
		std::vector<std::vector<int>> dp;
		for (int i = 0; i < grid.size(); i++) {
			dp.push_back(std::vector<int>());  // �������㰡
			for (int j = 0; j < grid[0].size(); j++) {
				dp[i].push_back(0);
			}
		}
		dp[0][0] = grid[0][0];
		for (int j = 1; j < dp.size(); j++) {  // �߽�����
			dp[0][j] = dp[0][j - 1] + grid[0][j];
		}
		for (int i = 1; i < dp.size(); i++) {  // �߽�
			dp[i][0] = dp[i - 1][0] + grid[i][0];
		}
		for (int i = 1; i < dp.size(); i++) {
			for (int j = 1; j < dp.size(); j++) {
				dp[i][j] = std::min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
			}
		}
		return dp[grid.size()-1][grid.size()-1];
	}
};

int main() {
	std::vector<std::vector<int>> grid = { {1,3,1},{1,5,1},{4,2,1}};
	Solution solve;  // ʵ����
	printf("res = %d\n", solve.minPathSum(grid));

	system("pause");
	return 0;
}