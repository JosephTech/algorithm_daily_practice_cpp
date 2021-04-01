/*
题目：
	每个孩子至少分一个糖。
	每个孩子有个rating， 若每个孩子rating比 左右的孩子高，则他比左右糖要多。
	求最少共需要多少趟

例如：
	输入：vector<int> ratings   [1,0,2]
	则最少分糖 [2, 1, 2]。 共5个

思考：
	贪心， 越少越好

算法思路：
	左-》右，遍历。 若右rating>左rating， 则 右 = 左+1
	再
	右-》左， 遍历。 若左rating>右rating， 则 左 = 右+1
	最后求和
*/
#include <iostream>  // puase, cout
#include <vector>  // std::vector
#include <numeric>  // std::accumulate


class Solution {
public:
	int candy(std::vector<int> &ratings) {  //传入引用
		int size = ratings.size();
		if (size < 2) {
			return size;  // 若0、1孩子， 每人一个糖即可
		}
		std::vector<int> cookies(size, 1);  // size个1
		for (int i = 1; i < size; i++) {
			if (ratings[i - 1] < ratings[i]) {
				cookies[i] = cookies[i - 1] + 1;  // 右rating大，则右cookie=左+1
			}
		}
		for (int i = size - 1; i > 0; i--) {  //i最小=1，因为i要-1。 i最大=size-1,因为索引0开始
			if (ratings[i - 1] > ratings[i]) {
				cookies[i - 1] = cookies[i] + 1;  //左rating大，则左cookie=右+1
			}
		}
		return std::accumulate(cookies.begin(), cookies.end(), 0);  // 累加的初始值是0
	}
};


int main02() {
	std::vector<int> ratings;
	ratings.push_back(1);
	ratings.push_back(0);
	ratings.push_back(2);
	//ratings.push_back(1);

	Solution solve;
	int res = solve.candy(ratings);
	printf("至少需要%d个糖果\n", res);


	system("pause");
	return 0;
}