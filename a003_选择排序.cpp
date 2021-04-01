#include <iostream>  // pause, cout
#include <vector>  // std::vector

class Solution {
public:
	void selectionSort(std::vector<int> &nums) {
		for (int i = 0; i < nums.size(); i++) {
			int min_index = i;  // 已排序末尾，作为i
			for (int j = i + 1; j < nums.size(); j++) {  // 遍历未排序部分
				if (nums[j] < nums[min_index]) {  // 如果小于，记录索引
					min_index = j;
				}
			}
			if (min_index != i) {  // 若最小的 在未排序部分，交换
				int temp = nums[i];
				nums[i] = nums[min_index];
				nums[min_index] = temp;
			}
		}
	}
};

int main() {
	std::vector<int> nums = { 9, 1, 8, 5, 7, 2, 6, 3, 4 };

	Solution solve;
	solve.selectionSort(nums);  // 传入引用

	// 打印
	for (int i = 0; i < nums.size(); i++) {
		printf("%d ", nums[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}