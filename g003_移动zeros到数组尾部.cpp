/*
leetcode 283 move zeros

题目：
	给定一个数组nums，写一个函数，将数组中所有0挪到数组的末尾，而维持其他所有
	非0元素的相对位置

举例：
	nums = [0, 1, 0, 3, 12]
	函数运行后，结果为[1, 3, 12, 0, 0]
*/
/*
思路1：
	扫描 得到所有非0元素，
	放回去，将剩余位置补0
*/


#include <iostream>
#include <vector>

class Solution {
public:
	void moveZeros(std::vector<int> &nums) {
		std::vector<int> nonZeroElements;  // 存放非零元素
		for (int i = 0; i < nums.size(); i++) {  // 非零元素，放进nonZeroElements
			if (nums[i]) {  // 若非0
				nonZeroElements.push_back(nums[i]);
			}
		}
		for (int i = 0; i < nonZeroElements.size(); i++){  // 放回去
			nums[i] = nonZeroElements[i];
		}
		for (int i = nonZeroElements.size(); i < nums.size(); i++) {
			nums[i] = 0;
		}
	}
};

int main() {
	int arr[] = { 0, 1, 0, 3, 12 };
	std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));  // 传入首位指针

	Solution solve;
	solve.moveZeros(vec);  // 传入引用

	for (int i = 0; i < vec.size(); i++) {
		printf("%d ", vec[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}