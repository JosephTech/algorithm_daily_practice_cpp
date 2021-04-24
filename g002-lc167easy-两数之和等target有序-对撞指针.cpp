/*
lc167 
����֮��==target,
��������
����ֻ��һ�Խ�
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> twoSumSorted(vector<int> &nums, int target) {  // �������ã���ֹ��������
		vector<int> res;
		int l = 0, r = nums.size() - 1;  // ��ײָ��l,r��  �ֱ�ָ��һ����
		while (l < r) {  // ��ĿҪ�� ���ص�����������ȣ�ÿ����ֻ����һ�Σ�
			if (nums[l] + nums[r] == target) {
				res.push_back(l+1);
				res.push_back(r+1);
				return res;
			}
			else if (nums[l] + nums[r] < target)  // С�ڣ�������
				l++;
			else  // ���ڣ��Ҽ�
				r--;
		}
		throw invalid_argument("the input has no solution");  // �޽�
	}
};

int main() {
	vector<int> nums = { 2, 7, 11, 15 };
	Solution solve;  // ʵ����
	vector<int> res = solve.twoSumSorted(nums, 9);
	for (int i = 0; i < res.size(); i++) {
		printf("���� = %d\n", res[i]);
	}

	system("pause");
	return 0;
}
