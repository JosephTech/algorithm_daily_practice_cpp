/*
题目：
给定nums数组

问是否存在i， j， 使得i和j距离小于等于k，nums[i]和nums[j]的距离小于等于t
*/
/*
思路：
i,j距离，肯定用滑动窗口

把[i, j]都放到 set中

实现：用set.size()<=k+1,就能保证滑窗限制

在滑窗中，set.lower_bound(nums[i] - t)存在 且<=nums[i]+t，就能保证nums[i]和nums[j]的距离限制
*/
#include <iostream>  // pause
#include <vector>  // std::vector
#include <set>  // 有序，要用lower_bound()
using namespace std;

class Solution {
public:
	bool containDuplicates(vector<int> &nums, int t, int k) {  // num[i]和nums[j]距离小于等于t.  i和j距离小于等于k， 则返回ture
		set<int> record_set;  // 记录指针i，i可以动，nums[i]不符合要求，再insert到record_set中。 保持record_set.size()<k+1
		for (int i = 0; i < nums.size(); i++) {
			if (record_set.lower_bound(nums[i] - t) != record_set.end() && *record_set.lower_bound(nums[i] - t) <= nums[i] + t)
				return true;
			record_set.insert(nums[i]);
			if (record_set.size() == k + 1)
				record_set.erase(nums[i - k]);  // 删掉到i距离为k的元素，如i=9，k=9，则删掉nums[0]， 留一个位置，继续下一轮查找
		}
		return false;
	}
};


int main() {
	vector<int> nums = { 10,20,30,40,55,60,90,56 };
	Solution solve; // 实例化
	printf("res = %d\n", solve.containDuplicates(nums, 1, 3) );  // nums[i]和nums[j]距离小于等于1， i和j距离小于等于3


	system("pause");
	return 0;
}