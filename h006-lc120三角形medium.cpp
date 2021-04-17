/*
二维数组，里边保存了一个三角形

第一行1个元素
第二行2个元素
第三行3个元素
第四行4个元素
。。。

求 顶端 到 底端 各个数字和 最小的路径。（每次只能向下、或者向右下走一步）
（就是 只能往下边的两个位置走一步 ）
返回 最小和
*/
#include <iostream>  // pause
#include <vector>  // std::vector
#include <algorithm>  // std::min

class Solution {
public:
	int minimumTotal(std::vector<std::vector<int>> &triangle) {  // 传入三角形
		std::vector<std::vector<int>> dp;  // 构建dp矩阵
		for (int i = 0; i < triangle.size(); i++) {
			dp.push_back(std::vector<int> ());  // 匿名？  秀啊
			for (int j = 0; j < triangle[i].size(); j++) {
				dp[i].push_back(0);
			}
		}
		// 自下而上，边界
		for (int j = 0; j < triangle.size(); j++) {  // 有几行，最后一行就有几个元素，秀啊
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
