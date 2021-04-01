/*
题目：
	一个数组存储了非负整型数据， 数组中第i个元素nums[i]，代表了可以从数组
	第i个位置【最多】向前跳跃nums[i]步； 已知数组各元素的情况下，
	求是否可以从数组第0个位置跳跃到数组最后一个元素位置？

	（注意是最多，比如最多跳3步， 则跳1、2、3步都行）
例如：
	nums = [2, 3, 1, 1, 4]， 可以从nums[0] = 2跳跃至 nums[4] = 4;
	nums = [3, 2, 1, 0, 4]， 不可以从nums[0] = 3跳跃至 nums[4] = 4;
*/
/*
贪心思路：
	1计算最远可跳到哪
		位置i:						[0, 1, 2, 3, 4]
		最远跳跃nums[i]:			[2, 3, 1, 1, 4]
		最远可达到的位置index[i]:	[2, 4, 3, 4, 8]
	2)jump记录当前位置，初始化为0
	3)max_index记录 0~jump位置，最远位置。初始化为index[0]。

	4)利用jump扫描index数组，直到jump达到index数组尾部或【jump超过max_index】，扫描过程中，更新max_index
	5)若最终jump为数组长度，则返回true，否则返回false

一句话：jump只能走到max_index
*/

#include <iostream>
#include <vector>

class Solution {
public:
	bool canJump(std::vector<int> &nums) {//引用方式传入数组
		std::vector<int> index; //nums的位置i可以跳到哪个位置
		for (int i = 0; i < nums.size(); i++) {
			index.push_back(i+nums[i]); //vector只能push_back。  i+nums[i]是该位置最多能跳多远
		}
		int jump = 0; // 位置，可以动
		int max_jump = index[0]; // 最大能走到哪
		while (jump <= max_jump && jump < index.size()) {
			if (index[jump] > max_jump) { // 若扫描到更远的，就更新max_jump
				max_jump = index[jump];
			}
			jump++; //移动扫描
		}
		if (jump == nums.size()) { //走到最后，可以
			return true;
		}
		return false;
	}
};

// 另一种解法，差不多
class Solution2 {
public:
	bool canJump(std::vector<int> &nums) {//引用方式传入数组
		std::vector<int> index; //nums的位置i可以跳到哪个位置
		for (int i = 0; i < nums.size(); i++) {
			index.push_back(i + nums[i]); //vector只能push_back。  i+nums[i]是该位置最多能跳多远
		}
		int jump = 0; // 位置，可以动
		int max_jump = index[0]; // 最大能走到哪
		while (jump <= max_jump && max_jump < index.size()) {
			if (index[jump] > max_jump) { // 若扫描到更远的，就更新max_jump
				max_jump = index[jump];
			}
			jump++; //移动扫描
		}
		if (max_jump >= nums.size()) { //走到最后，可以
			return true;
		}
		return false;
	}
};


int main() {
	std::vector<int> nums;
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(4);

	// Solution写的更直观，推荐使用
	//Solution solve;
	Solution2 solve;
	printf("%d\n", solve.canJump(nums));

	system("pause");
	return 0;
}


