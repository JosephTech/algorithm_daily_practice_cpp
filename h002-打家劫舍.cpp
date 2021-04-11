/*
lc198 打家劫舍
*/
/*
题目：
	一条直线上有n个房屋，
	每个房屋有不同数量的财宝，
	如果从相邻两个房屋盗取财宝，就会触发警报，
	请问最多可以盗取多少财宝（不能触发警报）
*/
/*
如n=6，每个房屋财宝如下：
[5, 2, 6, 3, 1, 7]

最多可以盗取 5+6+7 = 18个财宝
*/
/*
思路1：
	（暴力搜索）求子集，每个房间都有选、不选 两种可能，时间复杂度是O(2^n)
	选择总和最大的子集

	（先枚举，从1个房间开始，列出来）
*/
/*
思路2：
贪心算法
	不触发警报的同时，每次选择财宝最多的房间
（此方法不可行，换个例子就不行了）
*/
/*
思路3：
动态规划法（dp）
原问题与子问题、状态、边界状态、状态转移方程
*/
/*
dp状态转移方程：
dp[i] = max(dp[i-1], dp[i-2]+nums[i])
*/

#include <iostream>  // pause
#include <vector>  // std::vector
#include <algorithm>

class Solution {
public:
	int houseRobber(std::vector<int> &nums) {
		if (nums.size() == 0)
			return 0;
		if (nums.size() == 1)
			return nums[0];
		std::vector<int> dp(nums.size(), 0);  // 这么多个0
		dp[0] = nums[0];
		dp[1] = std::max(nums[0], nums[1]);  // 前面俩数
		for (int i = 2; i < nums.size(); i++) {
			dp[i] = std::max(dp[i-2]+nums[i], dp[i - 1]);
		}
		return dp[nums.size() - 1];
	}
};


int main() {
	std::vector<int> nums = { 5, 2, 6, 3, 1, 7 };

	Solution solve;
	int res = solve.houseRobber(nums);
	printf("%d\n", res);

	system("pause");
	return 0;
}
