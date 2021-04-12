/*
lc53最大子段和
*/

#include <iostream>  // pause
#include <vector>  // std::vector
#include <algorithm>  // std::max


class Solution {
public:
	int maxSubArray(std::vector<int> &nums) {  // 最大子数组
		if (nums.size() == 0) {
			return 0;  // 严谨了
		}
		std::vector<int> dp(nums.size(), 0);  // 这么多个0
		int max_sum = nums[0];
		dp[0] = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			dp[i] = std::max(nums[i], nums[i] + dp[i - 1]);
			if (dp[i] > max_sum)
				max_sum = dp[i];
		}
		return max_sum;
	}
};

int main() {
	std::vector<int> nums = { 2, 1, -3, 4, -1, 2, 1, -5, 4 };
	Solution solve; // 实例化
	int res = solve.maxSubArray(nums);
	printf("%d\n", res);

	system("pause");
	return 0;
}