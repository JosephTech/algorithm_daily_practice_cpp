/*
已知一些孩子和一些糖果，每个孩子有需求因子g，每个糖果有大小s， 当某个糖果
的大小s>=某个孩子的需求因子g时，代表该糖果可以满足该孩子；
求使用这些糖果，最多能满足多少个孩子？ （注意：某个孩子最多只能用一个糖果满足）
*/

/*
例如：
	需求因子数组g = [5, 10, 2, 9, 15, 9];
	糖果大小数组s = [6, 1, 20, 3, 8];
	最多可以满足3个孩子。
	（即1s 谁也不给；  3s给2g；  6s给5g；  8s谁也不给；  20s给9g）
*/
/*
思路：
	先排序 + 再贪心

	贪心：
		遍历孩子需求（从小到大），用最小的糖，给该孩子。（食堂阿姨）

为什么从小到大？
	因为能满足需求小的，就满足她
*/
/*
算法思路：
	1、对需求因子数组g 和 糖果大小数据s 从小到大排序；
	2、按照从小到大的糖果 尝试给某个孩子，若满足，
												就换下一个大孩子。（同时尝试下一个糖果~糖果末尾）
												直到没有孩子 或者 没有糖
*/

#include <iostream> // pause用的
#include <vector>
#include <algorithm> // 里边有std::sort

class Solution {
public:
	// 返回被满足孩子的个数
	int findContentChildren(std::vector<int> &g, std::vector<int> &s) { //传入引用，起别名
		std::sort(g.begin(), g.end()); //排序
		std::sort(s.begin(), s.end());
		int child = 0; //遍历孩子需求g用的
		int cookie = 0; //遍历糖果大小用的
		while (child < g.size() && cookie < s.size()) { // 还有糖 或者 还有孩子时候
			if (g[child] <= s[cookie]) { //该糖果 满足孩子的需求。 (注意是小于等于)
				child++; //下一个孩子。
				// 此处，可以存在一个vector里边
			}
			cookie++; //遍历糖
		}
		return child; // 比如到了child = 3，没有满足，则说明 满足了3个孩子（0  1  2）
	}

};

int main() {
	std::vector<int> g;
	g.push_back(5);
	g.push_back(10);
	g.push_back(2);
	g.push_back(9);
	g.push_back(15);
	g.push_back(9);

	std::vector<int> s;
	s.push_back(6);
	s.push_back(1);
	s.push_back(20);
	s.push_back(3);
	s.push_back(8);

	Solution solve;
	int num = solve.findContentChildren(g, s);
	printf("满足了%d个孩子\n",num);

	system("pause");
	return 0;
}