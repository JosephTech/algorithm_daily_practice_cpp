#include<iostream>
#include<set>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> intersectionOfTwoArrays(vector<int> &nums1, vector<int> &nums2) {
		set<int> record_set(nums1.begin(), nums1.end());  // ��¼nums1�е�Ԫ��,��Ϊc++�е������Ľӿ�ͨ�ã����Կ�������д
		set<int> res_set;
		for (int i = 0; i < nums2.size(); i++) {  // ��record_set����nums2�е�ÿ��Ԫ��
			if (record_set.find(nums2[i]) != record_set.end())  // ���ҵ��� ��ӵ�res_set��
				res_set.insert(nums2[i]);
		}
		vector<int> res_vec(res_set.begin(),res_set.end());  // ��res_set�е�Ԫ�� �����ӵ�res_vec�У����������������(��Ϊ���ϻ��Զ�����)
		return res_vec;
	}
};

int main() {
	vector<int> nums1 = {7, 8, 9, 10, 11, 12, 13};
	vector<int> nums2 = { 8, 1, 3, 5, 9, 7 };
	
	Solution solve;  // ʵ����
	
	vector<int> res = solve.intersectionOfTwoArrays(nums1, nums2);
	for (int i = 0; i < res.size(); i++) {
		printf("res = %d\n", res[i]);
	}

	system("pause");
	return 0;
}