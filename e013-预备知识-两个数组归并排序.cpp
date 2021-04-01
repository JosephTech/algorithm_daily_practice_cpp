/*
分治法 用递归实现简单，（也可以改成非递归if else）

回溯法 用递归实现简单，（很难改成非递归If else）

归并排序：merge sort
*/
/*

题目：
	已知两个已排序数组，将这两个数组合并为一个排序数组。

例如：	
	给定 array_A = [2, 5, 8, 10]
		 array_B = [1, 3, 5, 7, 30, 50]
	归并结果：
		[1, 2, 3, 5, 5, 7, 8, 20, 30, 50]
*/
#include <iostream> //pause用的
#include <vector> 

void merge_sort_two_vec(std::vector<int> &subvec1,
						std::vector<int> &subvec2,
						std::vector<int> &resultVec) { //传入引用，直接修改原值。避免拷贝构造
	int i = 0; //subvec1的第i个元素
	int j = 0; //subvec2的第j个元素
	while (i < subvec1.size() && j < subvec2.size()) { //谁小放谁。 相等放subvec1
		if (subvec1[i] <= subvec2[j]) {
			resultVec.push_back(subvec1[i]);
			i++;
		}
		else {
			resultVec.push_back(subvec2[j]);
			j++;
		}
	}
	//剩谁放谁
	for (; i < subvec1.size(); i++) { //注意，这里的;很秀，可以省略
		resultVec.push_back(subvec1[i]);
	}
	for (; j < subvec2.size(); j++) {
		resultVec.push_back(subvec2[j]);
	}
}

int main() {
	int test1[] = { 2, 5, 8, 20 };
	int test2[] = { 1, 3, 5, 7, 30, 50 };

	// 创建
	std::vector<int> sub_vec1;
	std::vector<int> sub_vec2;
	std::vector<int> vec;

	// 放入
	for (int i = 0; i < 4; i++) { //注意是小于。 0 1 2 3
		sub_vec1.push_back(test1[i]);
	}
	for (int i = 0; i < 6; i++) {
		sub_vec2.push_back(test2[i]);
	}
	//调用函数
	merge_sort_two_vec(sub_vec1, sub_vec2, vec);

	//打印
	for (int i = 0; i < vec.size(); i++) {
		printf("[%d]", vec[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}