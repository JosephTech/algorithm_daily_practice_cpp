#include <iostream>  // pause
#include <vector>  // std::vector
using namespace std;

class Solution {
public:
	int binSearch(vector<int> &nums, int target) {  // 返回索引
		int l = 0, r = nums.size();  // 前闭后开
		while (l < r) {  // 前闭后开， 如[42,42)非法，无元素
			int mid = l + (r - l) / 2;
			if (target == nums[mid])
				return mid;
			else if (target < nums[mid])
				r = mid;  // 左闭右开
			else
				l = mid + 1;  // 左闭右开
		}
		return -1;  // nums.size() == 0，返回-1。 找不到 ，返回-1
	}
};

int main() {
	std::vector<int> nums = {3, 4, 55, 88};
	Solution solve;
	printf("res = %d\n", solve.binSearch(nums, 55));

	system("pause");
	return 0;
}