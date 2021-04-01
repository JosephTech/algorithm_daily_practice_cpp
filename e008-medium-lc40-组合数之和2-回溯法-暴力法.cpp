/*
题目：
	已知一组数（其中有重复元素），求这组数可以组成的所有子集中，
	子集中各个元素和为整数target的子集，结果中无重复的子集。

	例如：
		nums[] = [10, 1, 2, 7, 6, 1, 5]
	(和为8)结果为：
		[[1,7],  [1,2,5],  [2,6],  [1,1,6]]
*/

/*
暴力法：
	1、(使用回溯法 或者 位运算法)构造出所有子集,这些子集不重复（用std::set）
	2、从中找到元素和为8的子集

存在问题：
	算法复杂度巨高
	超出事件限制
*/
#include <iostream> // pause用的
#include <vector>
#include <set>
#include <algorithm> //sort用的

class Solution {
public:
	std::vector<std::vector<int>> combinationSum2(int target, std::vector<int> &nums) { //传入引用，防止拷贝构造
		std::vector<int> item; // 子集，里边存储了int
		std::vector<std::vector<int>> result; // 存放最终结果，里边存储的是子集
		std::set<std::vector<int>> res_set; //集合，里边放的是不重复的子集。 新来的item不再res_set中，再往result放
		// 为啥不把set作为最终结果，因为得到vector套vector最合适
		result.push_back(item); //空集 添加进去
		std::sort(nums.begin(),nums.end()); //从小到大排序，防止一会出现[1,7]和[7,1]这种相同集合
		generate(0, nums, item, result, res_set); //递归调用

		// 暴力算result中 和等于8的子集
		std::vector<std::vector<int>> target_result;
		for (int i = 0; i < result.size(); i++) {
			int sum = 0;
			for (int j = 0; j < result[i].size(); j++) {
				sum += result[i][j]; //计算各个子集的和
			}
			if (sum == target) { //若和==target,就把这个子集放到target_result中
				target_result.push_back(result[i]);
			}
		}
		return target_result;
	}

private:
	void generate(int i, 
					std::vector<int> &nums,
					std::vector<int> &item, 
					std::vector<std::vector<int>> &result, 
					std::set<std::vector<int>> &res_set) {
		if (i >= nums.size()) { //递归结束条件
			return;
		}
		item.push_back(nums[i]);
		if (res_set.find(item) == res_set.end()) { //如果没找到，就放到set里，并且放到最终结果里
			res_set.insert(item); 
			result.push_back(item);
		}
		generate(i+1, nums, item, result, res_set);
		item.pop_back(); //回溯法
		generate(i+1, nums, item, result, res_set);
	}
};

int main() {
	//构造 数组nums
	std::vector<int> nums;
	nums.push_back(10);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(6);
	nums.push_back(1);
	nums.push_back(5);

	// 实例化，调用
	Solution solve;
	std::vector<std::vector<int>> target_result = solve.combinationSum2(8, nums);

	//打印
	for (int i = 0; i < target_result.size(); i++) {
		for (int j = 0; j < target_result[i].size(); j++) {
			printf("[%d]", target_result[i][j]);
		}
		printf("\n");
	}



	system("pause");
	return 0;
}

