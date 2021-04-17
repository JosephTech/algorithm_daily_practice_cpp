/*
题目：给一个序列，求其最长上升子序列的长度

只用返回长度
*/
/*
思路一：
暴力枚举法，不考虑
*/
/*
思路二：
动态规划法，最差是O(n^2)
*/
#include <iostream>  // puase
#include <vector>  // std::vector

class Solution {
public:
	int lengthofLIS(std::vector<int> &nums) {  // longest increasing subsequence
		if (nums.size() == 0) {
			return 0;  // 严谨了
		}
		std::vector<int> dp(nums.size(), 0);  // 这么多个0, 注意，不能写这么多个1，是错的，nums会= {1, 2, 3, 4,...}
		int max_length = 1;
		dp[0] = 1;
		for (int i = 1; i < nums.size(); i++) {  // 注意从1开始。以nums[i] 结尾的 最长上升序列
			dp[i] = 1;  // 最短也是1
			for (int j = 0; j < i; j++) {  // 若大于之前所有的nums[j]  且dp[j]+1更大，就更新  
				// 注意：要从0到i-1左闭右闭
				if (nums[i] > nums[j] && dp[j] + 1 > dp[i]) {
					dp[i] = dp[j] + 1;
				}
			}
			if (dp[i] > max_length) {
				max_length = dp[i];
			}
		}
		return max_length;
	}
};


int main() {
	std::vector<int> nums = {1, 3, 2, 3, 1, 4, 6, 7 };
	Solution solve;  // 实例化
	printf("res = %d\n", solve.lengthofLIS(nums));

	system("pause");
	return 0;
}