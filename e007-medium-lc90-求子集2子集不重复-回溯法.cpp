/*
已知一组数（其中有重复元素），求这组数可以组成的所有子集。
结果中无重复的子集。

	例如：nums[] = [2,1,2,2]
	结果为：[[], [2], [1,2], [1,2,2], [1,2,2,2], [2],[2,2],[2,2,2]]

	注意：结果中无重复的集合

所以需要去掉重复的结合，比如[1,2,2]和[2,1,2]
*/
/*
思路：
	先对nums[] = [2,1,2,2]排序
	得到[1,2,2,2]

	再使用回溯法找所有子集
*/

#include <vector>
#include <algorithm>
#include <set>

class Solution {
public:
	std::vector<std::vector<int>> subSet(std::vector<int> &nums) { //传引用，避免拷贝构造
		std::vector<int> item; // 集合，里边存储int
		std::vector<std::vector<int>> result; //result里边放的是一个个集合（不重复的集合）
		std::sort(nums.begin(), nums.end()); //排序，之后就不会出现1 2 2 和2 1 2重复了
		std::set<std::vector<int>> res_set; // 去重使用的集合

		result.push_back(item); //空集添加到result中
		//递归调用
		generate(0, nums, item, result, res_set);
		return result;
	}
private:
	void generate(int i, 
					std::vector<int> &nums, 
					std::vector<int> &item,
					std::vector<std::vector<int>> &result,
					std::set<std::vector<int>> &res_set) {   //递归调用
		//递归结束条件
		if (i >= nums.size()) {
			return;
		}

		item.push_back(nums[i]);
		if (res_set.find(item) == res_set.end()) { // 用set判断是否重复，如果不重复，添加到result中
			result.push_back(item);
			res_set.insert(item); //集合用insert插入
		}
		generate(i + 1, nums, item, result, res_set); //要
		//回溯法
		item.pop_back();
		generate(i + 1, nums, item, result, res_set); //不要
	}
};


int main() {
	std::vector<int> nums;
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(2);

	//实例化，调用
	Solution solve;
	std::vector<std::vector<int>> result = solve.subSet(nums);

	// 打印
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			printf("[%d]",result[i][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}