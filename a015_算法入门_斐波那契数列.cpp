/*
斐波那契数列：
	f(n) = f(n-1) + f(n-2)
	就是一个数 = 它之前两个数的和

例子：
	1,1,2,3,5,8,13...
*/
/*
递归时间复杂度：
	O(2^n)
*/

#include <iostream>  // puase


int fib(int n) {  // n是求斐波那契第n个数的值
	if (n == 0 || n == 1) {  // 递归结束条件
		return 1;
	}
	return fib(n - 1) + fib(n - 2);  // 之前两个数的和
}

int main() {
	int res = fib(6);
	printf("res = %d\n", res);

	system("pause");
	return 0;
}