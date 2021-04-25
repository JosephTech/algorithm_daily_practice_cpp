/*
���룺[1,2,2,1]��[2,2,3]
return :
	[2, 2]

(����ֵ���ظ�Ԫ�أ�������map, �����ַ���ֵ�Ǽ���)
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	vector<int> intersectionOfTwoArrays(vector<int> &nums1, vector<int> &nums2) {
		vector<int> res_vec;  // ����
		map<int, int> record_map;  // ���ʵ�ʱ��ֵĬ�ϸ�0
		for (int i = 0; i < nums1.size(); i++)
			record_map[nums1[i]] ++;  // ������ ��Ĭ�ϸ�0�� ��++��
		for (int i = 0; i < nums2.size(); i++) {
			if (record_map[nums2[i]] > 0) {  // ������ڣ��ͷŽ������
				res_vec.push_back(nums2[i]);
				record_map[nums2[i]]--;  // ����
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
	printf("-----------\n");  // ÿ��ʹ�� �������ʵ�ʱ�򣬾͸�ֵ�� ��ʼֵ0

	vector<int> nums1 = { 1, 3, 5, 7 }, nums2 = { 3, 5, 66, 88 };
	Solution solve;  // ʵ����
	vector<int> res = solve.intersectionOfTwoArrays(nums1, nums2);
	for (int i = 0; i < res.size(); i++) {
		printf("%d\n", res[i]);
	}


	system("pause");
	return 0;
}