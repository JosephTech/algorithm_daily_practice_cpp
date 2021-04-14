/*
传入一个数组，
若找到，返回位置索引
若没找到，返回插入位置，
*/
#include <iostream>  // pause
#include <vector>  // std::vector

class Solution {
public:
	int binSearch(std::vector<int> &nums, int target) {  // 传入一个数组nums，传入待查找元素target
		int begin = 0;
		int end = nums.size() - 1;  // 右端点
		int index = -1;  // 位置索引
		while (index == -1) {
			int mid = begin + (end - begin) / 2;
			if (target == nums[mid]) {
				index = mid;   // index值改变，while循环结束，所以不用break
			}
			else if (target < nums[mid]) {
				if (mid == 0 || nums[mid-1] < target) {
					index = mid;  // 往右放
				}
				end = mid - 1;
			}
			else if (target > nums[mid]) {
				if (mid == nums.size() - 1 || target < nums[mid + 1]) {
					index = mid + 1;  // 往右放
				}
				begin = mid + 1;
			}
		}
		return index;
	}
};

int main() {
	std::vector<int> nums = {-1, 2, 5, 20, 90, 100, 207, 800};
	std::vector<int> targets = { -1, 2, 5, 20, 90, 100, 207, 800, -2, 3, 14, 80, 95,150,300, 900};
	Solution solve;  // 实例化
	for (int i = 0; i < targets.size(); i++) {
		int res = solve.binSearch(nums, targets[i]);
		printf("%d\n", res);
	}

	system("pause");
	return 0;
}