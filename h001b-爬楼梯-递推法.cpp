/*
思考：
	第i阶楼梯 与 前面的 （哪些些阶楼梯爬法数量） 是直接相关的？
	怎么递推出第i阶有几种爬法？

答案：
	第i阶爬法数量 = （第i-1阶爬法数量） + （第i-2阶爬法数量）
	第3阶爬法数量 = （第1阶爬法数量）+ （第2阶爬法数量）
	第4阶爬法数量 = （第3阶爬法数量） + （第2阶爬法数量）
*/
#include <iostream>
#include <vector>  // 尽量用vector， 默认数组贼难用

class Solution {
public:
	int climbStairs(int n) {  // 一共n阶楼梯
		std::vector<int> vec(n+3, 0);  // n+3个0  数组
		vec[0] = 1;
		vec[1] = 2;
		for (int i = 2; i < n; i++) {
			vec[i] = vec[i - 2] + vec[i - 1];
			//printf("%d\n",vec[i]);
		}
		return vec[n - 1];  // 最后一个元素
	}
};

int main() {
	Solution solve;  // 实例化
	int res = solve.climbStairs(10);

	printf("%d\n", res);

	system("pause");
	return 0;
}