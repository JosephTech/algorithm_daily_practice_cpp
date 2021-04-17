/*
题目：
骑士只能 往右、往下走
*/
#include <iostream>  // pause
#include <vector>  // std::vector
#include <algorithm>

class Solution {
public:
	int calculateMinimumHP(std::vector<std::vector<int>> &dungeon) {  // dungeon地牢、hp：hit point
		if (dungeon.size()==0) {
			return 0;  // 严谨了
		}
		int row = dungeon.size();
		int col = dungeon[0].size();
		std::vector<std::vector<int>> dp(row, std::vector<int>(col, 0));
		dp[row - 1][col - 1] = std::max(1, 1-dungeon[row - 1][col - 1]);  // 初始 边界
		for (int j = col-2; j >= 0; j--) {
			dp[row - 1][j] = std::max(1, dp[row-1][j+1] - dungeon[row-1][j]);  // 边界条件，最下边一行
		}
		for (int i = row-2; i >= 0; i--) {  // 一定要倒着写
			dp[i][col - 1] = std::max(1, dp[i+1][col-1] - dungeon[i][col-1]);  // 边界，最后一列
		}
		for (int i = row-2; i >= 0; i--) {  // 一定要倒过来写，否则不行，太好玩了
			for (int j = col-2; j >= 0; j--) {
				int dp_min = std::min(dp[i+1][j], dp[i][j+1]);
				dp[i][j] = std::max(1, dp_min - dungeon[i][j]);
			}
		}
		return dp[0][0];  // 注意是返回dp[0][0]。  dp左上角的第一个元素
	}
};

int main() {
	std::vector<std::vector<int>> dungeon = { {-2, -3, 3}, 
												{-5,-10,1},
												{10, 30,-5} };
	Solution solve;
	printf("res = %d\n",solve.calculateMinimumHP(dungeon));
	system("pause");
	return 0;
}