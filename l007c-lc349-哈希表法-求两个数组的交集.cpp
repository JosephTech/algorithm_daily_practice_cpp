/*
题目：
求两个数组的交集，重复元素 结果有一个即可
*/
/*
unordered set底层是哈希实现的

查找、插入、删除 一个元素，均为O(1)
*/
#include <iostream>
#include <unordered_set>  // 哈希 实现的set
using namespace std;

class Solution {
public:
	vector<int> intersectionOfTwoArrays(vector<int> &nums1, vector<int> &nums2) {
		unordered_set<int> record_set(nums1.begin(), nums1.end());
		vector<int> res_vec;  // nums1放到set中，然后逐个查nusm2中的元素，查到，放进res_vec中
		for (int i = 0; i < nums2.size(); i++) {
			if (record_set.find(nums2[i]) != record_set.end())
				res_vec.push_back(nums2[i]);
		}
		return res_vec;  
	}
};

int main(){
	vector<int> nums1 = {7, 8, 9, 11, 13};
	vector<int> nums2 = {66, 88 };
	Solution solve;
	vector<int> res = solve.intersectionOfTwoArrays(nums1, nums2);
	for (int i = 0; i < res.size(); i++)
		printf("%d\n", res[i]);  // 若 空的，就什么就不打印

	system("pause");
	return 0;
}