/*
跳跃游戏2：
	一个数组存储了非负整型数据，数组中的第i个元素nums[i]，代表了可以从数组第i个位置最多
	向前跳跃nums[i]步；已知数组各元素的情况下，确认可以从第0位置跳跃到数组最后一个位置，
	【求最少需跳跃几次？】
	（注意：0是确认能跳到最后的。 中间的位置i也能跳到最后）
*/
/*
贪心思路：
	跳越远越好.
*/
/*
思考：
	如果希望最少跳跃达到终点，则需明确何时进行跳跃是最合适的。

	如果提早跳跃，则可能增加跳跃次数。

贪心规律：
	到达某点前若一直不跳跃，发现从该点不能跳到更远的地方了，在这之前肯定有次必要的跳跃

结论：
	尽量不跳，
	直到无法到达更远的地方时，在这之前，找个位置，跳到一个更远地方
	就能保证跳的次数最少了
*/

#include <iostream>
#include <vector>

// 
class Solution {
public:	// 作用域
	int lessJumpTimes(std::vector<int> &nums) { //传入nums的引用。  nums是数组，用vector存
		if (nums.size() < 2) { //元素个数0或1,就不用跳，返回0次
			return 0;
		}
		int jump_times = 1; //最少跳跃次数，初始化
		int current_max_jump = nums[0]; //当前最远跳跃到哪个位置j。 初始化
		int pre_max_max_jump = nums[0]; //遍历从当前位置i到最远位置j，记录下次跳到最远位置。初始化
		for (int i = 0; i < nums.size(); i++) {
			if (i > current_max_jump) { // 尽量不跳，直到i>j，其中j=current_max_jump。 就跳下一次，直接跳到i~j的最远记录pre
				current_max_jump = pre_max_max_jump;
				jump_times++;
			}
			if (pre_max_max_jump < nums[i] + i ) { //若nums[i] + i大，说明下次能跳更远，更新pre
				pre_max_max_jump = nums[i] + i;
			}
		}
		return jump_times;
	}
};

int main() {
	// 构建、 添加2 3 1 1 4
	std::vector<int> nums;
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(4);

	// 实例化、打印
	Solution solve;
	printf("less jump times = %d\n", solve.lessJumpTimes(nums));

	system("pause");
	return 0;
}
// warning 有符号无符号不匹配，不用管，只是warning