/*
��Ŀ��
����������Ľ������ظ�Ԫ�� �����һ������
*/
/*
unordered set�ײ��ǹ�ϣʵ�ֵ�

���ҡ����롢ɾ�� һ��Ԫ�أ���ΪO(1)
*/
#include <iostream>
#include <unordered_set>  // ��ϣ ʵ�ֵ�set
using namespace std;

class Solution {
public:
	vector<int> intersectionOfTwoArrays(vector<int> &nums1, vector<int> &nums2) {
		unordered_set<int> record_set(nums1.begin(), nums1.end());
		vector<int> res_vec;  // nums1�ŵ�set�У�Ȼ�������nusm2�е�Ԫ�أ��鵽���Ž�res_vec��
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
		printf("%d\n", res[i]);  // �� �յģ���ʲô�Ͳ���ӡ

	system("pause");
	return 0;
}