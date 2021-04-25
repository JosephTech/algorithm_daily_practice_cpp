#include<iostream>
#include<set>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> intersectionOfTwoArrays(vector<int> &nums1, vector<int> &nums2) {
		set<int> record_set(nums1.begin(), nums1.end());  // 记录nums1中的元素,因为c++中迭代器的接口通用，所以可以这样写
		set<int> res_set;
		for (int i = 0; i < nums2.size(); i++) {  // 在record_set中找nums2中的每个元素
			if (record_set.find(nums2[i]) != record_set.end())  // 若找到， 添加到res_set中
				res_set.insert(nums2[i]);
		}
		vector<int> res_vec(res_set.begin(),res_set.end());  // 把res_set中的元素 逐个添加到res_vec中，这样就是有序的了(因为集合会自动排序)
		return res_vec;
	}
};

int main() {
	vector<int> nums1 = {7, 8, 9, 10, 11, 12, 13};
	vector<int> nums2 = { 8, 1, 3, 5, 9, 7 };
	
	Solution solve;  // 实例化
	
	vector<int> res = solve.intersectionOfTwoArrays(nums1, nums2);
	for (int i = 0; i < res.size(); i++) {
		printf("res = %d\n", res[i]);
	}

	system("pause");
	return 0;
}