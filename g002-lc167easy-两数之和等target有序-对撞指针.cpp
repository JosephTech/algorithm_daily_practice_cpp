/*
lc167 
两数之和==target,
数组有序，
有且只有一对解
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> twoSumSorted(vector<int> &nums, int target) {  // 传入引用，防止拷贝构造
		vector<int> res;
		int l = 0, r = nums.size() - 1;  // 对撞指针l,r，  分别指向一个数
		while (l < r) {  // 题目要求 返回的索引不能相等（每个数只能用一次）
			if (nums[l] + nums[r] == target) {
				res.push_back(l+1);
				res.push_back(r+1);
				return res;
			}
			else if (nums[l] + nums[r] < target)  // 小于，左增，
				l++;
			else  // 大于，右减
				r--;
		}
		throw invalid_argument("the input has no solution");  // 无解
	}
};

int main() {
	vector<int> nums = { 2, 7, 11, 15 };
	Solution solve;  // 实例化
	vector<int> res = solve.twoSumSorted(nums, 9);
	for (int i = 0; i < res.size(); i++) {
		printf("索引 = %d\n", res[i]);
	}

	system("pause");
	return 0;
}
