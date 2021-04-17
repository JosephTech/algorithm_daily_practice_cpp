/*
��Ŀ��
��ʿֻ�� ���ҡ�������
*/
#include <iostream>  // pause
#include <vector>  // std::vector
#include <algorithm>

class Solution {
public:
	int calculateMinimumHP(std::vector<std::vector<int>> &dungeon) {  // dungeon���Ρ�hp��hit point
		if (dungeon.size()==0) {
			return 0;  // �Ͻ���
		}
		int row = dungeon.size();
		int col = dungeon[0].size();
		std::vector<std::vector<int>> dp(row, std::vector<int>(col, 0));
		dp[row - 1][col - 1] = std::max(1, 1-dungeon[row - 1][col - 1]);  // ��ʼ �߽�
		for (int j = col-2; j >= 0; j--) {
			dp[row - 1][j] = std::max(1, dp[row-1][j+1] - dungeon[row-1][j]);  // �߽����������±�һ��
		}
		for (int i = row-2; i >= 0; i--) {  // һ��Ҫ����д
			dp[i][col - 1] = std::max(1, dp[i+1][col-1] - dungeon[i][col-1]);  // �߽磬���һ��
		}
		for (int i = row-2; i >= 0; i--) {  // һ��Ҫ������д�������У�̫������
			for (int j = col-2; j >= 0; j--) {
				int dp_min = std::min(dp[i+1][j], dp[i][j+1]);
				dp[i][j] = std::max(1, dp_min - dungeon[i][j]);
			}
		}
		return dp[0][0];  // ע���Ƿ���dp[0][0]��  dp���Ͻǵĵ�һ��Ԫ��
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