/*
回溯法 又称 试探法
	当探索到某一步时，发现原来选择达不到目标，就退回一步重新选择，
	这种走不通就退回再走的技术为回溯法

例如：
	有向无环图
*/ 
/*
例1： 求子集
	已知一组数（其中无重复元素），求这组数可以组成的所有子集。
	结果中不可有 重复的子集。

例如：
	nums[] = [1,2,3]
	结果为：
		[[], [1], [2], [3], [1,2], [1,3], [2,3], [1,2,3]]
*/
/*
利用回溯法生成子集，即对于每种元素，都有试探 放入和不放入集合 这两种选择
*/
/*
从逻辑上理解：
	每次调用递归函数generate()，都是选择放入nums[i] 或者不放入nums[i]

理解第i=1调用
	如item = [1],i=1时，
	将nums[1]添加到item中变成[1,2]
	[1,2]push_back到result中，
		i=2,放不放nums[2]
	弹出，item变成[1]
		i=2,放不放nums[2]=3;   // 结果是[1],[1,3]，其中[1]已经push_back过了，所以只用弹出，不用push_back

理解最后一次调用：
	如item = [1,2],  i=2时，
		将nums[2]添加到item中变成[1,2,3]
		[1,2,3]push_back到result中
			i=3,  此时i >= nums.size()，则return
		弹出，item变成[1,2]
			i=3, 此时i>=nums.size()，则return

*/
#include <iostream>
#include <vector>

class Solution {
public: // 类里边的主函数subset()
	std::vector<std::vector<int>> subSet(std::vector<int> &nums) {
		std::vector<int> item; // item是子集， 存放整型
		std::vector<std::vector<int>> result; // 存放子集
		result.push_back(item); //空集
		generate(0, nums, item, result); //第一层调用，传入i=0。要不要nums[0]
		return result;

	}
private: //递归函数放这里边
	void generate(int i,
		std::vector<int> &nums,
		std::vector<int> &item,
		std::vector<std::vector<int>> &result) { // 返回 集合套集合
		if (i >= nums.size()) { //递归结束
			return;
		}
		// 有nums[i]
		item.push_back(nums[i]); // item是个集合，里边放的是 整型数字
		result.push_back(item); //result放的是集合
		generate(i + 1, nums, item, result);
		// 无nums[i]
		item.pop_back();
		generate(i + 1, nums, item, result);
	}
};

int main() {
	std::vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);

	Solution solve;
	std::vector<std::vector<int>> result = solve.subSet(nums);

	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			printf("[%d]", result[i][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}