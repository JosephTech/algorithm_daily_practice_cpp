/*
插入排序：
	取一个未排序的数，
	从后往前遍历已排序部分，逐个比较，

	若小， 插入
*/
#include <iostream>  // pause
#include <vector>  // std::vector

void inseration_sort(std::vector<int> &nums) {
	int n = nums.size();
	for (int i = 0; i < n; i++) {  // 从0~n， 共n轮。 每轮插入一个数。
		for (int j = i; j > 0 && nums[j - 1] > nums[j]; j--) {  // 对nums[i], 前>后，就不断交换。 意思就是把nums[i]插入到前面的已排序数组里
			int temp = nums[j - 1];
			nums[j - 1] = nums[j];
			nums[j] = temp;
		}
	}
}


int main() {
	std::vector<int> nums = { 1, 3, 5, 7, 2, 6, 4, 8, 9, 2, 8 };
	inseration_sort(nums);  //传入引用

	for (int i = 0; i < nums.size(); i++) {
		printf("%d ", nums[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}