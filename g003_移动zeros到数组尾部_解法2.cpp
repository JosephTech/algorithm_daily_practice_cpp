/*
思路2：
	引入一个指针k
	使用i指针遍历nums的每个元素
	当i遍历到非0元素的时候，就放到k位置，k+=1
*/

#include <iostream>  // puase
#include <vector>  // std::vector

class Solution {
public:
	// 时间复杂度O(n)
	// 空间复杂度O(1) 没有使用任何辅助空间
	void move_zeros(std::vector<int> &nums) {
		int k = 0;  // nums中, [0,k)的元素均为非0元素
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i]) {  // 若i指向非0元素，则 赋值给nums[k] 。 k++
				nums[k] = nums[i];
				k++;  //可以写上边
			}
		}
		for (int i = k; i < nums.size(); i++) {  // 若k还剩余，就全赋值为0
			nums[i] = 0;
		}
	}
};


int main() {
	int arr[] = { 0, 1, 0, 3, 12 };
	std::vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));  // 传入首尾指针。根据arr创建vec

	//std::vector<int> nums = {0, 1, 0, 3, 12};
	Solution solve;
	solve.move_zeros(nums);  // 传入引用

	for (int i = 0; i < nums.size(); i++) {
		printf("%d ",nums[i]);
	}
	printf("\n");
	
	system("pause");
	return 0;
}