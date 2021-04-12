/*
lc458小猪试毒药
*/

#include <iostream>  // pause

class Solution {
public:
	int poorPigs(int buckets, int minutesToTest, int minutesToDie) {  // 多少桶水， 测试多少分钟，喝到毒药几分钟死亡
		int time = minutesToTest / minutesToDie + 1;  // 一只猪 可以 测试几桶水
		int pigs_num = ceil(log(buckets) / log(time));  // c++中log是以e为底的
		return pigs_num;
	}
};

int main() {
	Solution solve;  // 实例化
	int num = solve.poorPigs(1000, 60, 15);  // 1000桶水（只有一桶有毒）， 60分钟测试时间，猪喝到毒药15分钟死亡
	printf("%d\n", num);

	system("pause");
	return 0;
}
