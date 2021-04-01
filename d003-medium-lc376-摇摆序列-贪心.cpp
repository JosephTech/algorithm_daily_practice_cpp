/*
摇摆序列 medium leetcode376

	一个整数序列，如果两个相邻元素的差恰好正负（负正）交替出现，则该序列被称为摇摆序列。
	一个小于两个元素的序列直接被称为摇摆序列

（即波浪形的）

例如：
	序列[1，7，4，9，2，5]是摇摆序列，差（6, -3, 5, -7, 3）
	序列[1，4，7，2，5]不是摇摆序列，差（3, 3, -5, 3）
	序列[1, 7, 4, 5, 5]不是摇摆序列,差（6, -3, 1, 0）

	注意：两元素相等不是摇摆序列
*/
/*
题目：
	给一个随机序列，求满足摇摆序列的最长子序列的长度。
	如[1, 7, 4, 9, 2, 5]的最长摇摆子序列 长度为6。 即不用删除元素，就是摇摆序列

	如[1, 2, 3, 3, 4, 5, 6, 7, 8, 9]最长摇摆子序列长度是2
*/

/*
举例子：
	[1, 17, 5, 10, 13, 15, 10, 5, 16, 8]
当序列有一段连续上升或者下降时
	连续递减阶段，选最小（在该阶段最后一个）
	连续递增阶段，选最大（在该阶段最后一个）
*/
/*
思路:
	自动状态机
*/

#include <iostream>
#include <vector>

class Solution {
public:
	int wiggleMaxLength(std::vector<int> &nums) { //引用方式传入
		if (nums.size() < 2) { //序列数小于2直接认为是摇摆序列
			return nums.size(); 
		}
		static const int BEGIN = 0;
		static const int UP = 1;
		static const int DOWN = 2;
		int max_len = 1; //摇摆序列最少是第一个元素。 暂不考虑序列无元素
		int STATE = BEGIN; //初始化状态STATE。 大写是为了代码规范
		for (unsigned int i = 1; i < nums.size(); i++) 
		{ //从i=1开始看升降。默认i=0在摇摆序列第一个
			switch (STATE) 
			{
			case BEGIN: //如果当前元素nums[i]=上一个，则仍在本STATE
				if (nums[i-1] < nums[i]) {
					STATE = UP; //转换状态
					max_len++; //记录状态转换，每转换一次，就多一个元素
				}
				else if (nums[i - 1] > nums[i]) {
					STATE = DOWN;
					max_len++;
				}
				break; //switch要有break退出本轮for循环
			case UP://如果当前元素nums[i] = nums[i-1]，则仍在本STATE. 上升也是在本STATE
				if (nums[i-1] > nums[i]) {
					STATE = DOWN;
					max_len++;
				}
				break;
			case DOWN: //若等，仍在本STATE;  若下降，仍在本STATE
				if (nums[i-1] < nums[i]) {
					STATE = UP;
					max_len++;
				}
				break;
			}
		}
		return max_len;
	}
};

int main() {
	// 构造、添加
	std::vector<int> nums;
	nums.push_back(1);
	nums.push_back(17);
	nums.push_back(5);
	nums.push_back(10);
	nums.push_back(13);
	nums.push_back(15);
	nums.push_back(10);
	nums.push_back(5);
	nums.push_back(16);
	nums.push_back(8);

	Solution solve;
	printf("max lenth of wiggle 序列 = %d\n", solve.wiggleMaxLength(nums));

	system("pause");
	return 0;
}

//总结：
// 本题是求最长子序列的长度
// 若每次状态转换时候，把元素push_back进去，就是求最长子序列了