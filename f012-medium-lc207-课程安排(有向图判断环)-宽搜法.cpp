/*
在宽度优先搜索的时候，只将入度为0的点添加至队列。

当完成一个顶点的搜索（从队列取出），它指向的所有顶点入度都减1.

若此时，某顶点入度为0，则添加至队列，若完成宽度搜索后，

所有点的入度都为0，则图无环，否则有环。
*/
/*
什么是入度d？
	入度就是 它依赖d门课。
		就是 d门课指向它
*/
/*
算法关键点：
	1、用 入度 记录几个节点指向自己
	2、用 队列 宽搜
*/
#include <iostream>
#include <queue>
#include <vector>

//图的邻接表 数据结构
struct GraphNode {
	int label; //标签值
	std::vector<GraphNode *> neighbors; //邻接点
	GraphNode(int x): label(x) {} //构造函数
};

class Solution {
public:
	bool canFinsh(int numCourses, 
		           std::vector<std::pair<int, int>> &prerequisites) { //传入课程数、传入引用 依赖关系，前者依赖后者
		std::vector<int> degree; //入度，记录几根线指向自己
		std::vector<GraphNode *> Graph;//存放 图的节点
		std::queue<GraphNode *> Q; //存放节点的
		for (int i = 0; i < numCourses; i++) { //装进Graph。 degree装0
			Graph.push_back(new GraphNode(i));
			degree.push_back(0);
		}
		for (int i = 0; i < prerequisites.size(); i++) { //连线、degree初始化
			GraphNode *begin = Graph[prerequisites[i].second];
			GraphNode *end = Graph[prerequisites[i].first];
			begin->neighbors.push_back(end);
			degree[prerequisites[i].first]++;
		}
		for (int i = 0; i < numCourses; i++) {
			if (degree[i] == 0) { // 入度为0， 则把对应节点push进队列Q
				Q.push(Graph[i]);
			}
		}
		while (!Q.empty()) { //不空则访问neighbors，degre--、若degree=0则入队列、
			GraphNode *node = Q.front();
			Q.pop();
			for (int i = 0; i < node->neighbors.size(); i++) {
				degree[node->neighbors[i]->label] --;
				if (degree[node->neighbors[i]->label] == 0) {
					Q.push(node->neighbors[i]);
				}
			}
		}

		for (int i = 0; i < numCourses; i++) {
			delete Graph[i]; //在return前，释放堆区内存
		}
		for (int i = 0; i < numCourses; i++) {
			if (degree[i]) { //还剩，则有环
				return false;
			}
		}
		return true;
	}
};

int main() {
	std::vector<std::pair<int, int>> prerequisites;
	prerequisites.push_back(std::make_pair(1, 0));
	prerequisites.push_back(std::make_pair(2, 0));
	prerequisites.push_back(std::make_pair(3, 1));
	prerequisites.push_back(std::make_pair(3, 2));

	Solution solve;
	printf("%d\n", solve.canFinsh(4, prerequisites));

	system("pause");
	return 0;
}