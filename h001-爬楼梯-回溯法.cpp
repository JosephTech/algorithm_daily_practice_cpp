/*
leetcode 70 climbing stairs
爬楼梯
*/
/*
题目：
	在爬楼梯时候，每次可以上1阶台阶，或者2阶台阶， 请问n阶楼梯有多少种上楼方式
*/
/*
思路1：
	暴力搜索法： 回溯
*/

#include <iostream>

class Solution {
public:
	int climbStairs(int n){  //  传入n阶楼梯
		if (n == 1 || n == 2)
			return n;   // 1阶楼梯有1中走法， 2阶楼梯有2种走法
		return climbStairs(n - 1) + climbStairs(n - 2);  // 递归爬剩下的n-1阶，递归爬剩下的n-2阶
	}
};

/*
注意：
	这种方法超时
*/


int main(){
	Solution solve;
	int n = solve.climbStairs(10);
	printf("%d\n", n);

	system("pause");
	return 0;
}