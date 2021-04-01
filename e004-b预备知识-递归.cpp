/*
题目：
	给定数组nums = [1, 2, 3]  (使用vector存储)
	使用递归，将子集[1]  [1,2]   [1,2,3] 添加到数组result中 （使用vector存储）
*/

#include <iostream> //pause用
#include <vector>

void generate(int i, std::vector<int> &nums,
	std::vector<int> &item, std::vector<std::vector<int>> &result) { // 引用方式传入，直接操作原始数据。 所以返回值可以void
	
	if (i >= nums.size()) { //递归结束条件
		return;
	}
	item.push_back(nums[i]);
	result.push_back(item);
	generate(i+1, nums, item, result);

}

int main() {
	std::vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);

	std::vector<int> item; //空的
	std::vector<std::vector<int>> result; //空的
	int i = 0;
	generate(i, nums, item, result); //递归调用

	//打印
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			printf("[%d]", result[i][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}