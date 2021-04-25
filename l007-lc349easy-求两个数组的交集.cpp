#include <iostream>  // pause
#include <vector>  // std::vector
#include <set>
using namespace std;

class Solution {
public:
	vector<int> intersectionOfTwoArrays(vector<int> &nums1, vector<int> &nums2) {
		set<int> record_set;
		for (int i = 0; i < nums1.size(); i++) {
			record_set.insert(nums1[i]);  // set用insert插入
		}
		vector<int> res_vec;
		for (int i = 0; i < nums2.size(); i++) {
			if (record_set.find(nums2[i]) != record_set.end())
				res_vec.push_back(nums2[i]);  // 找到了，说明重复
		}
		return res_vec;
	}
};

int main() {
	vector<int> nums1 = { 5, 1, 3, 7, 9 };
	vector<int> nums2 = { 5, 9, 7, 11, 15 };

	Solution solve;  // 实例化
	vector<int> res = solve.intersectionOfTwoArrays(nums1, nums2);
	for (int i = 0; i < res.size(); i++) {
		printf("%d\n", res[i]);
	}

	system("pause");
	return 0;
}