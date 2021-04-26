#include <iostream>  // pause
#include <vector>  // std::vector
#include <unordered_set>  // 哈希表  实现的set
using namespace std;

class Solution {
public:
	bool containDuplicate(vector<int>& nums, int k) {  // k是最大窗口
		unordered_set<int> record_set;
		for (int i = 0; i < nums.size(); i++) {
			if (record_set.find(nums[i]) != record_set.end())  // 找到了，return true, 否则，添加到set中
				return true;
			else
				record_set.insert(nums[i]);
			if (record_set.size() == k + 1)   // 左闭右闭，所以k+1时候，去掉窗口最左边的，预留一个，查找下一个元素
				record_set.erase(nums[i-k]);  // 如i=9， k=9，则擦掉nums[0]			
		}
		return false;  // 不存在区间k。最右端也不会有特殊情况了
	}
};


int main() {
	vector<int> nums = {3, 4, 5, 6, 7, 8, 9, 5 };
	Solution solve;  // 实例化
	printf("%d\n", solve.containDuplicate(nums, 6));

	system("pause");
	return 0;
}