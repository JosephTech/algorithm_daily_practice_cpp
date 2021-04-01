#include <stdio.h>
#include <vector>

struct GraphNode {
	int label; //图的顶点的值
	std::vector<GraphNode *> neighbors;
	GraphNode(int x) : label(x) {};
};

int main() {
	const int MAX_N = 5;
	GraphNode *Graph[MAX_N]; //新建一个数组，里边放的GraphNode*
	for (int i = 0; i < MAX_N; i++) {
		Graph[i] = new GraphNode(i); //在堆区新建，返回地址，放到数组里
	}
	//push_back进neighbors<>里边,
	//即 连接
	Graph[0]->neighbors.push_back(Graph[2]);
	Graph[0]->neighbors.push_back(Graph[4]);
	Graph[1]->neighbors.push_back(Graph[0]);
	Graph[1]->neighbors.push_back(Graph[2]);
	Graph[2]->neighbors.push_back(Graph[3]);
	Graph[3]->neighbors.push_back(Graph[4]);
	Graph[4]->neighbors.push_back(Graph[3]);

	printf("Graph");
	for (int i = 0; i < MAX_N; i++) {
		printf("label(%d) : ", i);
		for (int j = 0; j < Graph[i]->neighbors.size(); j++) {
			printf("%d ", Graph[i]->neighbors[j]->label);
		}
		printf("\n");
	}
	for (int i = 0; i < MAX_N; i++) {
		delete Graph[i]; //释放堆区数据
	}

	system("pause");
	return 0;
}