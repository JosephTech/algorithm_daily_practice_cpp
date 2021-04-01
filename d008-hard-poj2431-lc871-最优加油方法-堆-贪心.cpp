/*
最优加油方法：
	已知一条公路上，有一个起点与一个终点，这之间有n个加油站；
	已知从这n个加油站到终点的距离d 
	与各加油站可以加油的量l,
	起点位置与终点距离L
	起始时刻油箱中的油量P

	假设使用一个单位的汽油，即走1个单位的距离，邮箱没有上限
	最少加几次油,可以从起点开到终点? （如果无法到达终点，返回-1）
*/
/*
思考：
	汽车经过n个加油站，对于这n个加油站，应该在哪个加油站停下来加油，
	最终既能到达终点，又使得加油次数最少？

	若按顺序加油，则面临：
		如果在某个加油站加油，可能是没必要的，有可能不进行这次加油也能到达终点

		如果在某个加油站不停下来加油，可能由于汽油不够而无法到达终点， 或者后面要更多次加油才能到达终点
*/
/*
贪心思路：
	当前油量能到的距离，  这之间的加油站，哪个油量最多，就在哪个加

	油用光加油最合适
	油量最多的加油站加油最合适

一句话总结：
	不能走的时候，考虑之前怎么加，加的油量越多越好。
*/
/*
与跳跃游戏不一样的地方：
	加油可以加多次，
	所以需要维护一个最大堆，（存储经过的加油站的汽油量），nlogn快

	每次走一个距离段，距离不够，就从 最大堆取 一个油（可取多次），直到距离够，
*/
#include <iostream> // pause
#include <vector>
#include <algorithm> //sort
#include <queue> // 最大堆priority_queue
#pragma warning(disable:4996)

bool cmp(const std::pair<int, int> &a, const std::pair<int, int> &b) //const防止函数内修改
{
	return a.first > b.first; // 由远到近
}

int get_minimum_stop(int L, int P, //加油站到终点的距离L， 加油站的汽油量P
	std::vector<std::pair<int,int>> &stops)// 站点stops存着 <该加油站到终点距离，该加油站油量> 
{
	std::priority_queue<int> Q; // 最大堆，里边存的油量
	stops.push_back(std::pair<int, int> (0, 0)); //终点站，（0, 0）
	std::sort(stops.begin(), stops.end(), cmp); //距离由远到近 排序
	int result = 0; //加油几次
	// 复用P表示当前油量；  复用L表示前一个站点到终点距离。 现在要到i站点
	for (int i = 0; i < stops.size(); i++) { //i = 0是第一加油站，因为起点没有在stops里
		int dis = L - stops[i].first; // 到i站点的距离段
		while (!Q.empty() && P < dis) { // 栈不空 且 油不够。（栈不空是为了防止报错）一直不够一直加
			P += Q.top(); //加油
			Q.pop(); //弹栈
			result++; //记录加油次数
		}
		if (Q.empty() && P < dis) { //没油了，P还小于距离，凉了
			return -1;
		}
		P -= dis; //走到i站点了，更新油量
		L = stops[i].first; //更新距离
		Q.push(stops[i].second); // 把i站点 的油量 放到最大堆里边
	}
	return result;
}

int main() {
	std::vector<std::pair<int, int>> stops;
	int N;
	int L;
	int P;
	int distance;
	int fuel;
	scanf("%d", &N); // 站点4
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &distance, &fuel); //站点到终点距离,站点油量  4,4;  5,2;  11,5； 15,10; 
		stops.push_back(std::make_pair(distance, fuel));
	}
	scanf("%d  %d", &L, &P); //  25,10 。起点距离，起点油量
	printf("最小加油次数 = %d\n", get_minimum_stop(L, P, stops));

	system("pause");
	return 0;
}
