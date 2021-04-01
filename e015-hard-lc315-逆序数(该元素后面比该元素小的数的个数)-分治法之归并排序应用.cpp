/*
merge_sort归并排序同时，顺带计数
*/
/*
题目：
	该元素后面比该元素小的元素的个数
*/

#include <iostream>
#include <vector>

class Solution {
public:
	std::vector<int> countSmaller(std::vector<int> &nums) { //传入引用，返回一个vector，每个位置存储了i位置  后小于nums[i]的个数
		std::vector<std::pair<int, int>> vec; //用于存放pair。 pair的first是nums[i]。  pair的second是i
		std::vector<int> count; //存储nums[i]，小于nums[i]的个数。 也是最终返回结果
		//添加
		for (int i = 0; i < nums.size(); i++) {
			vec.push_back(std::make_pair(nums[i], i)); //i记录了原始位置
			count.push_back(0); //初始化，每个位置记录为0个
		}
		merge_sort(vec, count); //递归调用
		return count;
	}

private:
	void merge_sort_two_vec(std::vector<std::pair<int, int>> &sub_vec1,
							std::vector<std::pair<int, int>> &sub_vec2,
							std::vector<std::pair<int, int>> &vec,
							std::vector<int> &count) { //传入引用
		int i = 0; //sub_vec1中第i个元素
		int j = 0; // sub_vec2中第j个元素
		while (i < sub_vec1.size() && j < sub_vec2.size()) { 
			// 谁小，把谁放到vec中。相同，就把sub_set1放到vec中
			// 自己看视频想
			if (sub_vec1[i].first <= sub_vec2[j].first ){
				vec.push_back(sub_vec1[i]); // 按顺序放到vec中
				count[sub_vec1[i].second] += j; // 更新count，自己看视频理解去
				// 注意：count是用于记录原始给定数据 的nums[i]后边有几个small的数
				// 只有放sub_set1时候，才更新count
				// 放sub_set2时候，是给j计数的
				i++;
			}
			else {
				vec.push_back(sub_vec2[j]);
				j++;
			}
		}
		//谁剩 放谁
		for (; i < sub_vec1.size(); i++) { // 注意：这里已经i++过了，不要再画蛇添足，下边i++了
			count[sub_vec1[i].second] += j;
			vec.push_back(sub_vec1[i]);
		}
		for (; j < sub_vec2.size(); j++) {
			vec.push_back(sub_vec2[j]);
		}
	}

	void merge_sort(std::vector<std::pair<int, int>> &vec,
					std::vector<int> &count) { //传入引用
		if (vec.size() < 2) { //递归结束条件。 当拆不成的时候，返回上一层递归
			return;
		}
		//拆开，分治
		int mid = vec.size() / 2;
		std::vector<std::pair<int, int>> sub_vec1;
		std::vector<std::pair<int, int>> sub_vec2;
		for (int i = 0; i < mid; i++) { //前一半
			sub_vec1.push_back(vec[i]);
		}
		for (int i = mid; i < vec.size(); i++) {
			sub_vec2.push_back(vec[i]);
		}
		//递归调用
		merge_sort(sub_vec1, count); //排序前一半。 之后sub_set1变成有序的
		merge_sort(sub_vec2, count); //排序后一半。 之后sub_set2变成有序的
		vec.clear(); //清空vec，这样，合并后vec就变成了有序的。   
		// 盗梦空间： 【注意：此处的vec，就是递归传入merge_sort的sub_set.】
		merge_sort_two_vec(sub_vec1, sub_vec2, vec, count); //合并
	}
};

int main() {
	int test[] = {5, -7, 9, 1, 3, 5, -2, 1};
	std::vector<int> nums;
	for (int i = 0; i < 8; i++) {
		nums.push_back(test[i]);
	}
	//实例化，调用函数
	Solution solve;
	std::vector<int> result = solve.countSmaller(nums);
	
	//打印
	for (int i = 0; i < result.size(); i++) {
		printf("[%d]", result[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}