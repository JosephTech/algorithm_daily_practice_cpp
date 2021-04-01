/*
预备知识：
	c++的sort函数用lamda表达式自定义排序
	https://blog.csdn.net/dong_beijing/article/details/81057918
	sort自定义排序和lambda配合使用
	https://blog.csdn.net/weixin_42714773/article/details/109722485?utm_medium=distribute.pc_relevant.none-task-blog-baidujs_title-1&spm=1001.2101.3001.4242
	C++sort如何使用lambda表达式对一维vector和二维vector进行排序
	https://lishizheng.blog.csdn.net/article/details/112250038
*/

/*
题目：
	最少删除几个区间，让区间不重叠？

例子：
	输入std::vector<std::vector<int>>  [[1,2], [2,4], [1,3]]   每个元素表示表示区间的首尾
	输出： int 1  表示删除1个区间
	（就是删掉[1,3]）
*/

/*
思考：
	优先保留 区间结尾小 且 不重叠的区间
	（即：
	若重叠，则只保留最小的）
*/

/*
算法思路：
	1、按区间尾排序， 得[[1,2], [1,3], [2,4]]
	2、初始化区间[1,2]
	3、重叠，保留[1,2] （即删除[1,3]）
	4、保留[2,4]
*/


#include <iostream>  // pause, cout
#include <vector>   // std::vector
#include <algorithm>  // std::sort


class Solution {
public:
	int eraseOverlapIntervals(std::vector<std::vector<int>> &intervals) {  // 传入引用，防止拷贝构造。区间,例如[[1,3],[1,3],[2,4]]
		if (intervals.empty()) {
			return 0;  //如果空，返回0
		}
		std::sort(intervals.begin(), intervals.end(), [](std::vector<int> a, std::vector<int> b) {
			return a[1] < b[1];
		});  // lambda匿名函数。按区间结尾  从小到大排序
		int total = 0, pre_end = intervals[0][1];  // total记录删除总数，pre_end记录前一个结尾
		for (int i = 1; i < intervals.size(); i++) {
			if (intervals[i][0] < pre_end) {
				total += 1;  // 如果开头 小于 前一个区间结尾，就删这个区间
			}else {
				pre_end = intervals[i][1];  // 如果开头 大于等于 前一个区间结尾，就保留该区间。
			}
		}
		return total;
	}
};

int main() {
	std::vector<std::vector<int>> intervals;
	std::vector<int> in1;
	std::vector<int> in2;
	std::vector<int> in3;

	in1.push_back(1);  // [1,3]
	in1.push_back(3);

	in2.push_back(1);  // [1,2]
	in2.push_back(2);

	in3.push_back(2);  // [2,4]
	in3.push_back(4);



	intervals.push_back(in1);
	intervals.push_back(in2);
	intervals.push_back(in3);

	Solution solve;
	int res = solve.eraseOverlapIntervals(intervals);
	printf("res = %d\n", res);

	system("pause");
	return 0;
}
