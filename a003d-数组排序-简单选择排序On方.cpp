/*
选择排序算法：简单选择排序
时间复杂度O(n^2),   空间复杂度O(1)
*/
/*
算法思路：
从数据中选出一个最大（或最小）的一个元素，存放在序列的起始位置。

第一次，把下标为0的元素 和后边的所有元素比较，找出最小或者最大，放在下标为0的位置

第二次，从下标为1的开始比较，查询剩下的最大或者最小值，放在下标为1的位置。

...
直到全部排完

参考：https://zhuanlan.zhihu.com/p/76799311
*/
#include <iostream>
#include <vector> //装数组

void select_sort(std::vector<int> &nums) { //传入数组的引用
	for (int i = 0; i < nums.size(); i++) {
		int min_index = i; //取第i作为最小
		for (int j = i+1; j < nums.size(); j++) { //逐个比较第i+1到最后，小了就换
			if (nums[j] < nums[min_index]) {
				min_index = j;
			}
		}
		if (min_index != i){ //更小，就交换两者的值
			int tmp = nums[i];
			nums[i] = nums[min_index];
			nums[min_index] = tmp;
		}
	}
} //不用返回，因为是引用，直接改的原始数据

int main() {
	std::vector<int> nums;
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(88);
	nums.push_back(6);
	nums.push_back(3);
	nums.push_back(99);

	select_sort(nums); //调用函数

	//打印
	for (int i = 0; i < nums.size(); i++) {
		printf("%d\n",nums[i]);
	}

	system("pause");
	return 0;
}