#include <iostream>  // pause, cout
#include <vector>  // std::vector

class Solution {
public:
	void bubbleSort(std::vector<int> &nums) {  //传入引用，防止拷贝构造
		int flag = 1;  //标志位，若排好序，循环一次，时间复杂度O(n)
		int length = nums.size();
		for (int i = 0; i < length -1 ; i++) {  // 循环n-1轮，每轮冒一个
			for (int j = 1; j < length - i; j++) { //第一轮比n-1次，第二轮比n-2次...
				if (nums[j - 1] > nums[j]) {  //前>后，交换
					int temp = nums[j - 1];
					nums[j - 1] = nums[j];
					nums[j] = temp;
					flag = 0;
				}
			}
			if (flag) break;  // 如果已经排好序，直接跳出外圈循环
		}
	}
};


int main() {
	std::vector<int> nums = { 8, 1, 6, 9, 7, 5, 2, 3, 4 };
	Solution solve;
	solve.bubbleSort(nums);  //传入引用

	for (int i = 0; i < nums.size(); i++) {
		printf("%d ", nums[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}