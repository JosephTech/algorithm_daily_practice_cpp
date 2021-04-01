/*
已知一组数（其中有重复元素），求这组数可以组成的所有子集中，
子集中各个元素和为整数target的子集，结果中无重复的子集。

例如：
	nums[] = [10, 1, 2, 7, 6, 1, 5], target = 8
	结果为：
	[[1,7], [1,2,5], [2,6], [1,1,6]]
*/
/*
上一种方法，数据量小，可以通过，但是leetcode会报超时。因为回溯法和位运算法的复杂度是2^n，
当n很大时，根本算不完

所以  需要使用剪枝法

例如：
	nums[] = [10, 1, 2, 7, 6, 1, 5]
	target= 8;

	去掉10这种情况，就能少一半的时间复杂度，例如原来是O(2^n)
	现在变成O(2^(n-1))

	此外，当>8，就剪枝，可进一步减少算法的时间复杂度
*/

#include <iostream> //pause用的
#include <set> //去除 重复子集用的
#include <algorithm> //sort用的。 sort后，子集中元素是从小到大的
#include <vector> // 哪哪都用，存集合用的

class Solution {
public:
	std::vector<std::vector<int>> combinationSum2(int target, std::vector<int> &candidates) { //传入target和数组
		std::vector<int> item; // 某个子集
		std::vector<std::vector<int>> result; //结果，集合套集合
		std::set<std::vector<int>> res_set; //去除重复集合用的
		std::sort(candidates.begin(), candidates.end()); //从小到大排序。 排序后找子集，子集元素也是从小到大的。 不会同时出现[1, 7] 和 [7,1] 
		// result.push_back(item); //不放空集，因为空集不满足和=target
		//递归调用
		generate(0, candidates,item, result, res_set, 0, target); //第一个0是i。  第二个0是sum
		return result; //返回结果
	}

private:
	void generate(int i,
					std::vector<int> &candidates,
					std::vector<int> &item,
					std::vector<std::vector<int>> &result,
					std::set<std::vector<int>> &res_set,
					int sum,
					int target) { //i sum target一个数，直接传值就行了
		if (i >= candidates.size() || sum > target) { //剪枝 + 递归结束。 大于等于是因为i从0开始索引的
			return;
		}
		sum += candidates[i]; //递归 求和
		item.push_back(candidates[i]); //放到item集合中
		if (sum == target && res_set.find(item) == res_set.end() ) { //当 和==target，并且res_set(没找到)不重复。 放到result中，放到res_set中
			res_set.insert(item); // set用insert
			result.push_back(item); //放到最终结果result中
		}
		generate(i + 1, candidates, item, result, res_set, sum, target); //递归调用
		//回溯
		sum -= candidates[i];
		item.pop_back();
		generate(i + 1, candidates, item, result, res_set, sum, target); //递归调用
	}
};

int main() {
	std::vector<int> nums;
	nums.push_back(10);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(6);
	nums.push_back(1);
	nums.push_back(5);

	//实例化、调用函数
	Solution solve;
	std::vector<std::vector<int>> result = solve.combinationSum2(8, nums);

	// 打印result
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			printf("[%d]", result[i][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}