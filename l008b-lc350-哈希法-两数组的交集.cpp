#include <iostream>
#include <unordered_map>  // 哈希表
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> intersectionOfTwoArrays(vector<int> &nums1, vector<int> &nums2) {  // 传入引用，防止拷贝构造
		vector<int> res_vec;  // 存放结果
		unordered_map<int, int> record_map;  // 键是nums1的数，值是计数
		for (int i = 0; i < nums1.size(); i++)
			record_map[nums1[i]]++;  // 访问就赋0了，然后就可以++了
		for (int i = 0; i < nums2.size(); i++)
			if (record_map[nums2[i]] > 0) { // >0时候，说明重复,存放到res_vec中
				record_map[nums2[i]]--;  // 计数减一
				res_vec.push_back(nums2[i]);
			}
		return res_vec;
	}
};

int main() {
	vector<int> nums1 = { 1, 8, 3, 6, 6, 6, 9 }, nums2 = {88, 6, 6, 6, 11};
	Solution solve;  // 实例化
	vector<int> res = solve.intersectionOfTwoArrays(nums1, nums2);
	for (int i = 0; i < res.size(); i++)
		printf("%d\n", res[i]);

	system("pause");
	return 0;
}