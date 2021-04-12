/*
leetcode 322
����Ǯ
medium
*/
/*
��Ŀ��
	������ֵ�����������������Ҫ���ţ�

���ӣ�
	��ֵ��[1, 2, 5]
	��11 = 5 + 5 + 1
	��Ҫ3��

���ӣ�
	��ֵ��[2]
	���: 3
	�޷���ɣ�����-1

���ӣ�
	��ֵ: [1, 2, 5, 7, 10]
	�� 14 = 7 + 7
	��Ҫ2��
*/

#include <vector>  // std::vector
#include <iostream>  // pause

class Solution {
public:
	int coinChange(std::vector<int> coins, int amount) {  // ������ֵ��������ճɵĽ���������
		std::vector<int> dp(amount + 1, -1);  // dp[i]��ʾi�����Ҫ���ų�Ʊ�� ��ô���-1
		dp[0] = 0;  // С���ɣ� ��ֵ��0�� �糮Ʊ��ֵ7�� ��dp[7] = dp[7 - 7] + 1�� 
		for (int i = 1; i <= amount; i++) {  // ע����<=�� ��Ϊi��ʾ�� dp[i]���ܴչ�i���
			for (int j = 0; j < coins.size(); j++) {  // д����if���߼�������
				if (i-coins[j] >=0 && dp[i-coins[j]] != -1) {  // �� ��i-coins[j] >=0,(��dp[����]û��������)��������ϵdp[i - coins[j]] != -1
					if (dp[i] == -1 || dp[i-coins[j]] + 1 < dp[i]) {  // dp[i] != -1�� ��-1����
						dp[i] = dp[i - coins[j]] + 1;  // ����
					}
				}
			}
		}
		return dp[amount];
	}
};


int main() {
	std::vector<int> coins = {1, 2, 5, 7, 10};
	Solution solve;
	for (int i = 0; i < 15; i++) {
		int res = solve.coinChange(coins, i);
		printf("%d\n", res);
	}
	system("pause");
	return 0;
}
