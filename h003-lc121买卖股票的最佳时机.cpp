/*
参考链接：
https://blog.csdn.net/weixin_41888257/article/details/107291520
*/

/*
只能买卖一次：
股票每天的价格prices = [7, 1, 5, 3, 6, 4]
先买后卖，
返回最大利润maxprofit
*/

#include <iostream>  // pause
#include <vector>
#include <algorithm>  // std::max

class Solution {
public:
	int stock_max_profit(std::vector<int> &prices) {
		if (prices.size() == 0  || prices.size() == 1)
			return 0;
		std::vector<int> dp(prices.size(), 0);  // 这么多个0, dp[0]默认是0
		int minprice = prices[0];
		for (int i = 1; i < prices.size(); i++) {
			minprice = std::min(minprice, prices[i]);
			dp[i] = std::max(prices[i] - minprice, dp[i-1]);
		}
		return dp[prices.size() - 1];  // 注意这里是-1
	}
};

int main() {
	std::vector<int> prices = { 7, 1, 5, 3, 6, 4 };
	Solution solve;
	int res = solve.stock_max_profit(prices);

	printf("%d\n", res);

	system("pause");
	return 0;
}
