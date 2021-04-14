/*
题目描述：
	给定一个 非负整数，求它的开方，向下取整

例如：
	输入8
	根8 = 2.82
	取整后是2
*/
/*
方法一：二分法
方法二：牛顿迭代法，更快
*/
#include <iostream>

class Solution {
public:
	int mySqrt(int a) {  // 求a的平方根
		int left = 1;
		int right = a;  // 左闭右闭
		while (left <= right) {  // 左闭右闭
			int mid = left + (right - left) / 2;
			if (mid == a/mid) {
				return mid;  //  比如3^2 = 9
			}
			else if (mid < a/mid) {
				left = mid + 1;  // 在大的那一半  找 根号a
			}
			else if (mid > a/mid) {
				right = mid - 1;  // 在小的那一半找 根号a
			}
		}
		return right;  // 因为left已经大于right了，返回right即可
	}
};

int main() {
	Solution solve;  // 实例化
	int res = solve.mySqrt(100000);
	printf("%d\n", res);

	system("pause");
	return 0;
}

