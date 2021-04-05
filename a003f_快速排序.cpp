/*
快速排序：
	最流行的排序算法、速度最快的排序算法

算法思路：
	选一个枢轴（例如最右边的）， 
		从左边开始，选一个大于枢轴的，
		从右边开始，选一个小于枢轴的，交换。
		通过l指针和r指针，不断l++, r++，多次交换。 while l<r时候

		把枢轴换到中间

	递归实现
*/
#include <iostream>  // pause
#include <vector>  // std::vector

class Solution {
public:
	void quick_sort(std::vector<int> &nums, int l, int r) {  // 左指针、右指针、枢轴
		if (l >= r)
			return; // 递归结束条件，维护闭区间[l, r]， 虽然l==r是合法的，但是没必要交换。也可以套在 下面代码的外边
		int i = l, j = r;  // i和j分别从左右开始 动。 维护[l, r] 左闭右闭。 r是枢轴
		int pivot = nums[r]; // 选右作为枢轴。  因为是左闭右闭，所以选nums[r] 
		// 把<枢轴的，放在枢轴的左边
		// >枢轴的，放在枢轴的右边
		while (i < j){
			while (nums[i] < pivot && i < j)  // 当小于枢轴，就向右移动i，为了i指向大于枢轴的
				i++;
			while (nums[j] >= pivot && i < j)  // 当大于等于枢轴，就左移j。  为了j指向小于枢轴的
				j--;
			if (i < j)
				std::swap(nums[i], nums[j]);  // 若 指针i<j， 则交换
		}  // 当i < j时候，就不断交换
		std::swap(nums[r], nums[j]);  // 交换枢轴到 中间  （交换的是值，不是指针）。 从[j, r]是>=pivot的

		quick_sort(nums, l, j - 1);  // 小于枢轴的 递归。 维护[l, r]左闭右闭
		quick_sort(nums, j + 1, r);  // 大于等于枢轴的 递归。 维护[l, r]左闭右闭
		// 注意j是已经排序好的，所以不用再动了
	}
};


int main() {
	std::vector<int> nums = { 8, 1, 9, 2, 6, 0, 7, 3, 5, 4 };
	Solution solve;

	int r = nums.size()-1;  // 维护左闭右闭[l, r]
	solve.quick_sort(nums, 0, r);
	
	for (int i = 0; i < nums.size(); i++) {
		printf("%d ", nums[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}