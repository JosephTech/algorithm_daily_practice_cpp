#include <iostream>  // pause, cout
#include <vector>  // std::vector

class Solution {
public:
	void bubble(std::vector<int> &nums) {  //传入引用， 防止拷贝构造
		int length = nums.size();
		for (int i = 0; i < length - 1; i++) {  // 循环n-1轮，每轮冒一个最大的
			for (int j = 1; j < length - i; j++) {  // 第一轮比较(交换)n-1次， 第二轮比较n-2次
				if (nums[j - 1] > nums[j]) {  // 前比后大，交换
					int temp = nums[j - 1];
					nums[j - 1] = nums[j];
					nums[j] = temp;
				}
			}
		}
	}
};

int main() {
	std::vector<int> nums = { 7, 8, 1, 9, 5, 4, 6, 2, 3, };
	Solution solve;
	solve.bubble(nums);
	for (int i = 0; i < nums.size(); i++) {
		printf("%d ", nums[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}