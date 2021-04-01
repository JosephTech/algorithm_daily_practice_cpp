/*
基础知识：图的 宽度优先搜索 breadth-first search
	个人理解：
			选一个（未被访问过的）顶点出发，先访问-1层，再访问-2层
	重复以上步骤，直至图中所有顶点都被访问到为止
*/
/*
用队列去维护 节点们，  复杂度O(n)
*/

#include <iostream> //puase用的
#include <queue> //图的宽搜，维护一个队列
#include <vector> // 存放图的 邻接点

struct GraphNode { //图节点 数据结构
	int label;
	std::vector<GraphNode *> neighbors;
	GraphNode(int x): label(x) {} //构造函数. 只用给label赋值
};

void BFS_search(GraphNode *node, int visit[]) { //传入节点*,   传入visit[label]，访问过则标记为1
	std::queue<GraphNode *> Q;
	Q.push(node);
	visit[node->label] = 1; //入队列时候，标记为1
	while (!Q.empty()) { //队列不空，就访问label、弹出、把neighbor放到队列里
		GraphNode * node2 = Q.front(); //又新建一个node变量
		printf("%d ", node2->label);  //访问label
		Q.pop();
		for (int i = 0; i < node2->neighbors.size(); i++) {
			if (visit[node2->neighbors[i]->label] == 0) { //如果没访问过，就放到Queue里
				Q.push(node2->neighbors[i]);
				visit[node2->neighbors[i]->label] = 1; //入队列时候，标记为1
			}
		}
	}
}
int main() {
	const int MAX_N = 5; //创建图的顶点，堆区new
	GraphNode *Graph[MAX_N];
	for (int i = 0; i < MAX_N; i++) {
		Graph[i] = new GraphNode(i);
	}

	//连接
	Graph[0]->neighbors.push_back(Graph[4]);
	Graph[0]->neighbors.push_back(Graph[2]);
	Graph[1]->neighbors.push_back(Graph[0]);
	Graph[1]->neighbors.push_back(Graph[2]);
	Graph[2]->neighbors.push_back(Graph[3]);
	Graph[3]->neighbors.push_back(Graph[4]);
	Graph[4]->neighbors.push_back(Graph[3]);

	//宽搜bfs
	int visit[MAX_N] = { 0 }; //全0数组
	for (int i = 0; i < MAX_N; i++) {
		if (visit[i] == 0) { //未访问的时候，以该节点为顶点，从该点宽搜
			printf("从label（%d）开始访问：", Graph[i]->label);
			BFS_search(Graph[i], visit);
			printf("\n");
		}
	}

	//删除
	for (int i = 0; i < MAX_N; i++) {
		delete Graph[i];
	}
	system("pause");
	return 0;
}
// 注意：printf  scanf要比cin  cout这种流形的性能快很多
// iostream是以流形式 定义的输入输出 对象
// stdio.h是包含了  printf scanf等函数
// 