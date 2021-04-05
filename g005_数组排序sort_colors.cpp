/*
题目：
	给定一个有n个元素的数组，数组中元素的取值只有0、1、2三种可能。
	为这个数组排序。
*/

/*
解题思路：
	使用O(nlogn)的排序方法也能解决问题，被accepted，但是没有用上全部条件。。。
*/
/*
更好的解题思路：
	计数排序counting sort
	统计0、1、2的个数，
	放相应数量的0/1/2即可
*/
/*
参考资料：
	Leetcode 75 颜色分类 C++
	https://blog.csdn.net/qq_43387999/article/details/86982438?utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7Edefault-6.control&dist_request_id=&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7Edefault-6.control
	liubobo 算法真题课， 第三章
*/

#include <iostream>  // pause
#include <vector>  // std::vector
#include <cassert>  // 断言

class Solution {
public:
	void sort_colors(std::vector<int> &nums) {  // 传入引用
		int count[3] = { 0 };  // 计数数组，count[0] 记录nums[i] = 0个数。。。
		for (int i = 0; i < nums.size(); i++) {
			assert (nums[i] >= 0 && nums[i] <= 2);  // 断言nums中元素是0/1/2，异常处理
			count[nums[i]]++;  // 计数
		}
		int index = 0;
		for (int i = 0; i < count[0]; i++)  // [)  左闭右开
			nums[index++] = 0;  // 之后递增
		for (int i = 0; i < count[1]; i++)  // 左闭右开， count[1]个1
			nums[index++] = 1;
		for (int i = 0; i < count[2]; i++)  // 左闭右开，count[2]个2
			nums[index++] = 2;
	}

	void sort_colors2(std::vector<int> &nums) {  // 另一种写法，100种数，总不至于写100个for循环吧？
		int count[3] = { 0 };  // 全0数组
		for (int i = 0; i < nums.size(); i++) {
			assert(nums[i] >= 0 && nums[i] <=2);  // 断言，在[0,2]
			count[nums[i]]++;  // 计数
		}
		int index = 0;
		for (int i = 0; i <= 2; i++)
			for (int j = 0; j < count[i]; j++)
				nums[index++] = i;  // 太秀了。  外圈循环count[i]的i，  内圈给count[i]个元素赋值i  
	}
};

int main() {
	std::vector<int> nums = { 1, 2, 0, 1, 0, 2, 0, 2, 0, 1, 1, 0, 0 };

	Solution solve;
	solve.sort_colors2(nums);  // 传入引用

	for (int i = 0; i < nums.size(); i++)
		printf("%d ", nums[i]);
	printf("\n");
	system("pause");
	return 0;
}


