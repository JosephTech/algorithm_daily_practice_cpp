/*
一只笔的价格是1元9角， 而班主任给小玉 的钱是a元b角， 能买多少只笔？

a<=10000, b <= 9

输出整数，笔数量
*/
/*
思路：
	统一度量衡，转换为角
*/
#include <iostream>  // pause

int buyPenNum(int a, int b) {
	int total_money = 10 * a + b;
	int num = total_money / 19;  // 取整数部分， python中两个//是取整。 c++中1个/是取整
	return num;
}

int main() {
	int res = buyPenNum(17, 2);
	printf("res = %d\n", res);

	system("pause");
	return 0;
}