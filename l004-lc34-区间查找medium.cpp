/*
题目：
已排序数组（有重复元素），
若找到target，返回 左右端点下标 [左端点，右端点]
若未找到target, 返回 [-1, -1]
*/
#include <iostream>  // pause
#include <vector>

class Solution {
public:
	std::vector<int> searchRange(std::vector<int> &nums, int target) {
		std::vector<int> result;
		int left = binSearchLeft(nums, target);
		int right = binSearchRight(nums, target);
		result.push_back(left);
		result.push_back(right);
		return result;
	}
private:
	int binSearchLeft(std::vector<int> &nums, int target) {
		int index = -1;  // 区间左端点
		int begin = 0;
		int end = nums.size()-1;  // 左闭右闭
		while (begin <= end) {
			int mid = begin + (end - begin) / 2;
			if (nums[mid] == target ) {
				if (mid == 0 || nums[mid - 1] < nums[mid]) {  // 找到左端点
					index = mid;
					break;
				}
				else {
					end = mid-1;  // 继续搜索 左边一半
				}
			}
			else if (target < nums[mid]) {
				end = mid - 1;  // 继续搜索 左边一半
			}
			else if (target > nums[mid]) {
				begin = mid + 1; // 继续搜索 右边一半
			}
		}
		return index;
	}

	int binSearchRight(std::vector<int> &nums, int target) {
		int index = -1;
		int begin = 0;
		int end = nums.size() - 1;  // 左闭右闭
		while (begin <= end) {
			int mid = begin + (end - begin) / 2;
			if (nums[mid] == target) {
				if (mid == nums.size()-1 || nums[mid+1] > nums[mid]) {  // 右端点，或者右边大
					index = mid;
					break;
				}
				else {  // 继续搜索 右边一半  (因为右端点 还在右边)
					begin = mid + 1;
				}
			}
			else if (target < nums[mid]) {
				end = mid - 1;  // 继续搜索左边一半
			}
			else if(target > nums[mid]){
				begin = mid + 1;
			}
		}
		return index;
	}
};

int main() {
	std::vector<int> nums = { 5, 7, 7, 8, 8, 8, 8, 10 };
	std::vector<int> targets = { 5, 7, 7, 8, 8, 8, 8, 10, 0, -1, 6, 9 };
	Solution solve;
	for (int i = 0; i < targets.size(); i++) {
		std::vector<int> res = solve.searchRange(nums, targets[i]);
		for (int j = 0; j < res.size(); j++) {
			printf("%d ", res[j]);
		}
		printf("\n");
	}
	
	system("pause");
	return 0;
}