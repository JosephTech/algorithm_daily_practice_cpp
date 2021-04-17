/*
��Ŀ����һ�����У���������������еĳ���

ֻ�÷��س���
*/
/*
˼·һ��
����ö�ٷ���������
*/
/*
˼·����
��̬�滮���������O(n^2)
*/
#include <iostream>  // puase
#include <vector>  // std::vector

class Solution {
public:
	int lengthofLIS(std::vector<int> &nums) {  // longest increasing subsequence
		if (nums.size() == 0) {
			return 0;  // �Ͻ���
		}
		std::vector<int> dp(nums.size(), 0);  // ��ô���0, ע�⣬����д��ô���1���Ǵ�ģ�nums��= {1, 2, 3, 4,...}
		int max_length = 1;
		dp[0] = 1;
		for (int i = 1; i < nums.size(); i++) {  // ע���1��ʼ����nums[i] ��β�� ���������
			dp[i] = 1;  // ���Ҳ��1
			for (int j = 0; j < i; j++) {  // ������֮ǰ���е�nums[j]  ��dp[j]+1���󣬾͸���  
				// ע�⣺Ҫ��0��i-1����ұ�
				if (nums[i] > nums[j] && dp[j] + 1 > dp[i]) {
					dp[i] = dp[j] + 1;
				}
			}
			if (dp[i] > max_length) {
				max_length = dp[i];
			}
		}
		return max_length;
	}
};


int main() {
	std::vector<int> nums = {1, 3, 2, 3, 1, 4, 6, 7 };
	Solution solve;  // ʵ����
	printf("res = %d\n", solve.lengthofLIS(nums));

	system("pause");
	return 0;
}