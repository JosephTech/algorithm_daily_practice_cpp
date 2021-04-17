/*
类似于贪心、又有点像栈
*/
#include <iostream>  // pause
#include <vector>  // std::vector

class Solution{
// nlog(n)  + n 还是nlogn
public:
	int lengthofLIS(std::vector<int> &nums) {  // longest increasing subsequence
		std::vector<int> stack_vec;
		stack_vec.push_back(nums[0]);  // 先放进去一个
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] > stack_vec.back()) {  // .back()返回最后一个元素的引用
				stack_vec.push_back(nums[i]);
			}
			else if (nums[i] <= stack_vec.back()) {
				int index = binSearch(stack_vec, nums[i]);
				stack_vec[index] = nums[i];
			}
		}
		return stack_vec.size();
	}
private:
	int binSearch(std::vector<int> &nums, int target) {
		int begin = 0;
		int end = nums.size() - 1;
		int index = -1;
		while (index == -1) {
			int mid = begin + (end - begin) / 2;
			if (target == nums[mid]) {
				index = mid;
			}
			else if (target < nums[mid]) {
				if (mid == 0 || target >nums[mid-1]) {
					index = mid;  // 往右放
				}
				end = mid - 1;  // 在前一半查找
			}
			else if (target > nums[mid]) {
				if (mid == nums.size()-1 || target < nums[mid+1]) {
					index = mid + 1;
				}
				begin = mid + 1;  // 在后一半查找
			}
		}
		return index;
	}
};

int main() {
	std::vector<int> nums = {1, 3, 2, 3, 1, 4, 5, 9, 10, 22};
	Solution solve;  // 实例化
	printf("res = %d\n", solve.lengthofLIS(nums));

	system("pause");
	return 0;
}