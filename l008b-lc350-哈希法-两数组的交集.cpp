#include <iostream>
#include <unordered_map>  // ��ϣ��
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> intersectionOfTwoArrays(vector<int> &nums1, vector<int> &nums2) {  // �������ã���ֹ��������
		vector<int> res_vec;  // ��Ž��
		unordered_map<int, int> record_map;  // ����nums1������ֵ�Ǽ���
		for (int i = 0; i < nums1.size(); i++)
			record_map[nums1[i]]++;  // ���ʾ͸�0�ˣ�Ȼ��Ϳ���++��
		for (int i = 0; i < nums2.size(); i++)
			if (record_map[nums2[i]] > 0) { // >0ʱ��˵���ظ�,��ŵ�res_vec��
				record_map[nums2[i]]--;  // ������һ
				res_vec.push_back(nums2[i]);
			}
		return res_vec;
	}
};

int main() {
	vector<int> nums1 = { 1, 8, 3, 6, 6, 6, 9 }, nums2 = {88, 6, 6, 6, 11};
	Solution solve;  // ʵ����
	vector<int> res = solve.intersectionOfTwoArrays(nums1, nums2);
	for (int i = 0; i < res.size(); i++)
		printf("%d\n", res[i]);

	system("pause");
	return 0;
}