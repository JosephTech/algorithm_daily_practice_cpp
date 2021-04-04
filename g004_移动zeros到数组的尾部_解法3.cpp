/*
思路：
	指针k 从位置0开始
	[0,k)是非0数组

	使用i遍历数组，当i指向非零时候，就和k指向的数字交换
*/

#include <iostream>
#include <vector>

class Solution {
public:
	// 时间复杂度O(n)   遍历一遍
	// 空间复杂度O(1)   没有申请额外空间，就一个swap    
	void move_zeros(std::vector<int> &nums) {  //传入数组引用。
		int k = 0;  // k指针， [0,k)是非零数组
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i])  // 若非零，交换
				if (i != k)  // 若整个数组都是非零元素，则不需要交换
					std::swap(nums[i], nums[k++]);  // 交换之后，k++
				else  // i==k时候， 说明整个数组都是非零元素，不需要交换
					k++;
		}
	}
};

int main() {
	std::vector<int> nums = { 0, 1, 0, 3, 12 };

	Solution solve;
	solve.move_zeros(nums);  //传入引用

	for (int i = 0; i < nums.size(); i++)
		printf("%d ", nums[i]);

	system("pause");
	return 0;
}