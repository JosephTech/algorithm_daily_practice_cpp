/*
输入：[1,2,2,1]和[2,2,3]
return :
	[2, 2]

(返回值有重复元素，所以用map, 键是字符，值是计数)
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	vector<int> intersectionOfTwoArrays(vector<int> &nums1, vector<int> &nums2) {
		vector<int> res_vec;  // 存结果
		map<int, int> record_map;  // 访问的时候，值默认赋0
		for (int i = 0; i < nums1.size(); i++)
			record_map[nums1[i]] ++;  // 计数。 （默认赋0， 再++）
		for (int i = 0; i < nums2.size(); i++) {
			if (record_map[nums2[i]] > 0) {  // 如果存在，就放进结果里
				res_vec.push_back(nums2[i]);
				record_map[nums2[i]]--;  // 减数
			}
		}
		return res_vec;
	}
};

int main() {
	map<int, int> test_map;
	printf("%d\n",test_map[42]);
	test_map.erase(42);
	printf("%d\n", test_map[42]);
	test_map[42]++;
	printf("%d\n", test_map[42]);
	test_map.erase(42);
	printf("-----------\n");  // 每次使用 索引访问的时候，就赋值了 初始值0

	vector<int> nums1 = { 1, 3, 5, 7 }, nums2 = { 3, 5, 66, 88 };
	Solution solve;  // 实例化
	vector<int> res = solve.intersectionOfTwoArrays(nums1, nums2);
	for (int i = 0; i < res.size(); i++) {
		printf("%d\n", res[i]);
	}


	system("pause");
	return 0;
}