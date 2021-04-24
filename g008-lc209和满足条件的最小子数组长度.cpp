#include <iostream>  // pause
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	// 注意这题 的if  else  写法，逻辑可太秀了
public:
	int minSubArrayLen(vector<int> &nums, int s) {  // 和>=s，最短子数组
		int sum = 0, l = 0, r = -1, res_len = nums.size() + 1;  // [l,r]左闭右闭为滑窗
		while (l < nums.size()) {  // 只看 左指针就行。 =size()则数组越界
			if (r + 1 < nums.size() && sum < s)  // =nums.size()则数组越界
				sum += nums[++r];  // 先移动指针，再更新和
			else  // 不越界，或 sum>=s
				sum -= nums[l++];  // 更新和，再指针移动
			if (sum >= s) {
				res_len = min(res_len, r - l + 1);
			}
		}
		if (res_len == nums.size() + 1)
			return 0;  // res_len没有更新,异常。 子数组长度为0
		return res_len;
	}
};


int main() {
	vector<int> nums = { 2, 3, 1, 2, 4, 3 };
	Solution solve;  // 实例化
	printf("res = %d\n", solve.minSubArrayLen(nums, 7));

	system("pause");
	return 0;
}