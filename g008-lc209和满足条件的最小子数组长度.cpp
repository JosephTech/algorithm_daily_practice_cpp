#include <iostream>  // pause
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	// ע������ ��if  else  д�����߼���̫����
public:
	int minSubArrayLen(vector<int> &nums, int s) {  // ��>=s�����������
		int sum = 0, l = 0, r = -1, res_len = nums.size() + 1;  // [l,r]����ұ�Ϊ����
		while (l < nums.size()) {  // ֻ�� ��ָ����С� =size()������Խ��
			if (r + 1 < nums.size() && sum < s)  // =nums.size()������Խ��
				sum += nums[++r];  // ���ƶ�ָ�룬�ٸ��º�
			else  // ��Խ�磬�� sum>=s
				sum -= nums[l++];  // ���ºͣ���ָ���ƶ�
			if (sum >= s) {
				res_len = min(res_len, r - l + 1);
			}
		}
		if (res_len == nums.size() + 1)
			return 0;  // res_lenû�и���,�쳣�� �����鳤��Ϊ0
		return res_len;
	}
};


int main() {
	vector<int> nums = { 2, 3, 1, 2, 4, 3 };
	Solution solve;  // ʵ����
	printf("res = %d\n", solve.minSubArrayLen(nums, 7));

	system("pause");
	return 0;
}