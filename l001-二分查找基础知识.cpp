/*
题目：
	查到 返回true
	没查到 返回false
*/
/*
例如：arr = [-1, 2, 5, 20, 90, 100, 207, 800]
待搜索数字target == 2, 200
*/
/*
思路：
	等于target怎么办？ 返回true
	小于target怎么办?  查询前面一半[0,mid-1]
	大于target怎么办？ 查询后边一半[mid+1, arr.size()-1]
*/
#include <iostream>  // pause
#include <vector>  // std::vector

// 递归写法
class Solution {
public:
	bool binSearch(std::vector<int> &nums, int target, int begin, int end) {  // 传入待查找元素target，传入数组。返回bool型
		if (begin > end)  // 左闭右闭，所以begin == end是合法的
			return false;
		int mid = begin + (end - begin) / 2;
		if (target == nums[mid]) {
			return true;
		}
		else if (target < nums[mid]) {
			return binSearch(nums, target, begin, mid-1);
		}
		else if (target > nums[mid]) {
			return binSearch(nums, target, mid+1, end);
		}


	}
};

int main() {
	std::vector<int> nums = {-1, 2, 5, 20, 90, 100, 207, 800};
	Solution solve;  // 实例化

	std::vector<int> targets = { 0,-1, 2, 3, 5, 7, 20,30, 90, 100, 200, 207,300, 800 };
	
	for (int i = 0; i < targets.size(); i++) {
		int res = solve.binSearch(nums, targets[i], 0, nums.size() - 1);
		printf("%d\n", res);
	}

	system("pause");
	return 0;
}
