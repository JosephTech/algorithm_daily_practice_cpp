/*
leetcode 322
找零钱
medium
*/
/*
题目：
	传入面值、传入金额、返回最少需要几张？

例子：
	面值：[1, 2, 5]
	金额：11 = 5 + 5 + 1
	需要3张

例子：
	面值：[2]
	金额: 3
	无法组成，返回-1

例子：
	面值: [1, 2, 5, 7, 10]
	金额： 14 = 7 + 7
	需要2张
*/

#include <vector>  // std::vector
#include <iostream>  // pause

class Solution {
public:
	int coinChange(std::vector<int> coins, int amount) {  // 传入面值、传入需凑成的金额。返回张数
		std::vector<int> dp(amount + 1, -1);  // dp[i]表示i金额需要几张钞票。 这么多个-1
		dp[0] = 0;  // 小技巧， 赋值成0， 如钞票面值7。 则dp[7] = dp[7 - 7] + 1。 
		for (int i = 1; i <= amount; i++) {  // 注意是<=， 因为i表示金额， dp[i]张能凑够i金额
			for (int j = 0; j < coins.size(); j++) {  // 写两层if，逻辑更清晰
				if (i-coins[j] >=0 && dp[i-coins[j]] != -1) {  // 若 若i-coins[j] >=0,(因dp[负数]没法索引到)；依赖关系dp[i - coins[j]] != -1
					if (dp[i] == -1 || dp[i-coins[j]] + 1 < dp[i]) {  // dp[i] != -1； 把-1换了
						dp[i] = dp[i - coins[j]] + 1;  // 更新
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
