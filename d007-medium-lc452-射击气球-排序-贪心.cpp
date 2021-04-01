/*
射击气球
	已知在一个平面上有一定数量的气球，平面可以看做一个坐标系，
	在平面的x轴的不同位置安排弓箭手向y轴方向射箭，弓箭可以向y轴走无穷远；
	给定气球的宽度xstart << x << xend
	问至少需要多少弓箭手，将全部气球打爆？

例如：
	四个气球： [[10,16], [2,8], [1,6], [7,12]]
	至少需要2名弓箭手
*/
/*
贪心思想：
	一只气球至少需要1只弓箭
	在将这只气球击穿的同时，尽可能击穿其他更多的气球！（贪心）
*/
/*
算法思路：
	1、将气球进行排序，按照气球的左端点从小到大排序。
	2、维护一个射击区间，在满足可以将当前气球射穿的情况下，尽可能击穿更多的气球，
		每击穿一个新气球，更新一次射击区间（即保证射击区间可以击穿这些气球）。
	3、如果新的气球没法击穿了，则需要增加一名弓箭手，即维护一个新的射击区间。。。
	
	循环往复指导所有气球遍历完毕
*/

#include <iostream>
#include <vector>
#include <algorithm>

//比较函数
bool cmp(std::pair<int, int> &a, std::pair<int, int> &b) { //传入引用 pair< T,T> &a  ，&b
	return a.first < b.first; //左端点从小到大排序。  此处不考虑左端点重复，一会考虑左端点和 区间右端点重复即可
}

class Solution {
public:
	int findMinArrayShots(std::vector<std::pair<int, int>> &balloons) { //传入vector. 里边pair存的是气球的左右端点
		if (balloons.empty()) { //空的话，就无需射箭手
			return 0;
		}
		std::sort(balloons.begin(), balloons.end(), cmp); //排序
		int shoot_begin = balloons[0].first; //维护一个区间
		int shoot_end = balloons[0].second;
		int num_shots = 1; //记录射箭手 数量
		for (int i = 1; i < balloons.size(); i++) { //从位置索引1开始的气球
			//当下一个的.first <= shoot_end时候，更新shoot_begin。
			if (balloons[i].first <= shoot_end) { //更新左
				shoot_begin = balloons[i].first; //因为之前排序了。所以 新气球的左端点一定大于shoot_begin
				if (balloons[i].second < shoot_end) { //左端点小于等于的同时，右端点也小。更新右
					shoot_end = balloons[i].second;
				}
			}
			else { //维护新区间
				num_shots++; //记录 弓箭手数量
				shoot_begin = balloons[i].first;
				shoot_end = balloons[i].second;
			}
		}
		return num_shots;
	}
};

int main() {
	std::vector<std::pair<int, int>> balloons;
	balloons.push_back(std::make_pair(10, 16));
	balloons.push_back(std::pair<int, int>(2, 8));
	balloons.push_back(std::pair<int, int>(1, 6));
	balloons.push_back(std::pair<int, int>(7, 12));

	Solution solve;
	printf("nums of shots =  %d\n", solve.findMinArrayShots(balloons));

	system("pause");
	return 0;
}