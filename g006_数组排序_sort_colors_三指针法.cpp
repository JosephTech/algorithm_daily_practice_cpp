/*
（上一个方法对 整个数组 扫描了两边，
第一遍 扫描每个元素
第二遍 放回去）

思路2：
	只扫描一遍，三路快排
	数组分成三份， 小于v， 等于v， 大于v

	之后对 <v 和 >v 的地方 快排即可
*/
#include <iostream>  // pause
#include <vector>  // std::vector
#include <cassert>

class Solution {
public:
	void sort_colors(std::vector<int> &nums) {
		int zero = -1, two = nums.size();  // [0, zero]是0左闭右闭。  [two, n-1]是2,左闭右闭
		// 注意：因为区间[5, 5]是合法的
		for (int i = 0; i < two;) {  //  [zero+1, two是1]。 注意，这里是i < two。 注意：这里不用i++，因为i指针有时候是不动的
			if (nums[i] == 1)
				i++;  // [zero+1, two-n]是1
			else if (nums[i] == 2)
				std::swap(nums[i], nums[--two]);  // two指针左移， 再交换，i不用递增
			else {
				assert( nums[i] == 0);  // 断言，又严谨了
				zero++;
				std::swap(nums[zero], nums[i]); //交换
				i++;  // zero指针右移，交换。 i指向下一个。 这三行可以写在一起。
				// 因为[zero+1, i-1]本来就是1啊， 所以要i++
			}
		}
	}
};


int main() {
	std::vector<int> nums = { 2, 1, 2, 2, 0, 2, 1, 2, 1, 0, 2, 0, 1, 0 };
	Solution solve;
	solve.sort_colors(nums);  // 传入引用

	for (int i = 0; i < nums.size(); i++)
		printf("%d ", nums[i]);
	printf("\n");

	system("pause");
	return 0;
}


