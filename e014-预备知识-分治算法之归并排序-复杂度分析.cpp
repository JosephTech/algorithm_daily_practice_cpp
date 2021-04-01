/*
分治算法：
将一个规模为N的问题分解为K个规模较小的子问题，这些子问题相互独立，
且与原问题性质相同。 求出子问题的解后，进行合并，
就可得到原问题的解。

一般步骤：
1、分解，将要解决的问题划分成若干规模较小的同类问题
2、求解，当子问题划分的足够小的时候，用较简单的方法解决
3、合并，按原问题的要求，将子问题的解逐层合并 构成原问题的解
*/
/*
预备知识：归并排序复杂度分析
	设有n个元素，n个元素归并排序的时间T(n)
	总时间 = 分解时间 + 解决子问题时间 + 合并时间

	分解时间：即对原问题拆解为两个子问题的时间，时间复杂度为O(n)
	（当逐个拆成两个vector时候，为O(n); 若使用下标，可以使O(1)）

	解决子问题时间：即解决两个子问题的时间 2T(n/2)

	合并时间：即对两个已排序数组归并的时间，（因为是逐元素添加，即所有元素遍历一遍）复杂度O(n)

T(n) = 
	 = 2T(n/2) + 2*O(n)				//解决两个子问题时间,每个规模少一半，为T(n/2)。
									// 个人理解：而2*O(n)的外边的2,常数倍,仍算作是O(n)
	 = O(n) + 2T(n/2)
	 = O(n + 2n/2 + 4n/4 +... + logn*n/logn)							
									// 放到O里边
									// 2^k = n，所以logn = k 。 (其中logn是以2为底的)
									// 消掉后，相当于logn个n相加了
	 = O(nlogn)						// 个人理解：n趋向无穷，所以单调递增函数logn趋向无穷，所以之前的常数O(n)可以省略
*/

#include <iostream> //pause用的
#include <vector>

void merge_sort_two_vec(std::vector<int> &sub_set1,
						std::vector<int> &sub_set2,
						std::vector<int> &vec) { //传入引用。 其中vec是本次合并结果
	int i = 0; // sub_set1中第i个元素
	int j = 0; // sub_sset2中第i个元素
	while (i < sub_set1.size() && j < sub_set2.size()) { //都不空时候。
		if (sub_set1[i] <= sub_set2[j]) { //谁小 把谁添加到vec中
			vec.push_back(sub_set1[i]);
			i++;
		}
		else {
			vec.push_back(sub_set2[j]);
			j++;
		}
	}
	// 哪个剩下，添加哪个
	for (; i < sub_set1.size(); i++) {
		vec.push_back(sub_set1[i]);
	}
	for (; j < sub_set2.size(); j++) {
		vec.push_back(sub_set2[j]);
	}
}

void merge_sort(std::vector<int> &vec) { //传入引用
	if (vec.size() < 2) { //递归结束条件。 返回上一层递归
		return;
	}
	std::vector<int> subset1; //放前一半
	std::vector<int> subset2; //放后一半
	int mid = vec.size() / 2;
	for (int i = 0; i < mid; i++) {//0~mid-1   前一半放在subset1
		subset1.push_back(vec[i]);
	}
	for (int i = mid; i < vec.size(); i++) {
		subset2.push_back(vec[i]);
	}
	// 递归调用
	merge_sort(subset1); //排前一半
	merge_sort(subset2); //排后一半
	vec.clear(); //清空vec，准备忘里边装排好的
	merge_sort_two_vec(subset1, subset2, vec); //合并成的vec作为上一层的merge_sort(subset) 盗梦空间
												//因为都是引用
}

//// 少量数据，简单测试
//int main() {
//	std::vector<int> vec;
//	int test[] = { 5, -7, 9, 8, 1, 4, -3, 10, 2, 0 };
//	for (int i = 0; i < 10; i++){
//		vec.push_back(test[i]);
//	}
//
//	// 归并排序、打印
//	merge_sort(vec);
//	for (int i = 0; i < vec.size(); i++) {
//		printf("[%d]", vec[i]);
//	}
//	printf("\n");
//
//	system("pause");
//	return 0;
//}

// 大量数据测试
#include <stdlib.h> // 生成随机数组用的
#include <algorithm> // 利用sort测试归并排序是否正确
#include <assert.h>
#include <time.h> //time作为随机数种子

int main() {
	std::vector<int> vec1;
	std::vector<int> vec2;
	srand(time(NULL));
	for (int i = 0; i < 10000; i++) { //rand一万次
		int num = (rand() *  rand()) % 100003; //rand*rand取余数，让它更随机一点
												// 对质数 取余， 能让更分散，更随机
		vec1.push_back(num);
		vec2.push_back(num);
	}
	merge_sort(vec1); //调用归并排序
	std::sort(vec2.begin(), vec2.end()); //调用std自带排序
	assert(vec1.size() == vec2.size()); //断言数组长度相同
	for (int i = 0; i < vec1.size(); i++) { //断言每个元素相同
		assert(vec1[i] == vec2[i]);
	}
	//不报错即通过了
	system("pause");
	return 0;
}