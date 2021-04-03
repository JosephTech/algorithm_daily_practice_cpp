/*
题目：
	给定一个序列，	
	返回满足条件的索引


例如：nums = [2, 7, 11, 15], target = 9
返回： [0,1]
（可以只返回一组答案，但是统一元素不能使用两边）
（即target=4，不能返回两个2的索引[0,0]）
*/
/*
解法1：
	两层嵌套循环，枚举x,y，看和是不是9
	O(n^2)
解法2：
	只用枚举x，查9-x是否也在这个数组里边
	O(n) 只线性、枚举了一次
*/

#include <iostream>  // pause
#include <unordered_map>  // std::map
#include <vector>  // std::vector


std::vector<int> two_sum(std::vector<int> &nums, int target) {  // 目标
	std::vector<int> ans; // 待会儿存放结果，里边是两个索引
	std::unordered_map<int, int> hashmap;  // hash表， 键是num，值是索引i
	for (int i = 0; i < nums.size(); i++) {
		int tag = target - nums[i];  // 待查找的值 tag
		if (hashmap.find(tag) != hashmap.end()) {  // 如果在hash表里，就把索引添加到ans，返回
			ans.push_back(hashmap[tag]);
			ans.push_back(i);  //这两个数的索引
			break;  // 结束循环
		}
		// 为什么之后再添加，因为不能返回自身的索引，所以就查自己以前的
		// 太秀了
		hashmap[nums[i]] = i; // 键是nums[i]  值是i
	}
	return ans;
}

/*
枚举O(n)
查找O(1)
一共是O(n)
*/

int main() {
	std::vector<int> nums = { 2, 7, 11, 15 };

	std::vector<int> ans = two_sum(nums, 9);
	for (int i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}