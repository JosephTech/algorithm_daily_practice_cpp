/*
题目：
	-1, 1, -1, ..., (-1)^n求和
*/

#include <iostream>  // pause, cout
#include <vector>  // std::vector

int getSum(std::vector<int> &nums) {
	int sum;
	if (nums.size() % 2 == 0) {  // 余数是0，则sum为0
		sum = 0;
	}else sum = -1;
	return sum;
}


int main04() {
	std::vector<int> nums = { -1, 1, -1, 1, -1, 1, -1 };
	
	int res = getSum(nums);
	printf("%d\n ", res);

	system("pause");
	return 0;
}