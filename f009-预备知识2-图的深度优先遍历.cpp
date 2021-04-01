/*
预备知识：图的深度优先遍历

就是能访问就访问，访问不到就回退，继续访问，
还有顶点未被访问到，就从那个顶点出发，访问其它顶点，直到所有顶点都被访问到。
*/
/*
定义：
	从图中某个顶点v出发，首先访问该顶点，然后从它的各个未被访问的邻接点出发，
	深度优先搜索遍历图，直到图中所有和v路径相同且未被访问的顶点都被访问到。
	若此时尚有其它顶点未被访问到，则另选一个未被访问的顶点作为起始点，
	重复上述过程，直到图中所有顶点都被访问到为止。
*/
/*
思路分析：
	需要记录某个节点还没有被访问到。
	因为 路线有来有回

但是二叉树就不会出现某个节点未被访问到的情况，因为是单向的
*/

#include <iostream> //pause用的
#include <vector>

struct GraphNode { //构建图的邻接表数据结构
	int label;
	std::vector<GraphNode *> neighbors; //连向的 节点
	GraphNode (int x): label(x){} //构造函数,只用给label赋值
};

//图的深度优先遍历DFS,  (访问label的值) 
void DFS_Graph(GraphNode *node, int visit[]) { //传入节点*   传入visit数组，访问过则visit[label]=1
	visit[node->label] = 1; //访问过，标记为1
	printf("%d ", node->label); //访问当前节点
	for (int i = 0; i < node->neighbors.size(); i++) { //访问相邻节点
		if (visit[node->neighbors[i]->label] == 0) { //没访问过，就递归访问
			DFS_Graph(node->neighbors[i], visit); //全部递归递归完，就自动返回了，所以不用写return
		}
	}
}

int main() { 
	//创建图的顶点
	const int MAX_N = 5; //顶点数
	GraphNode *Graph[MAX_N]; //数组，装5个图节点*
	for (int i = 0; i < MAX_N; i++) {
		Graph[i] = new GraphNode(i); //堆区新建，返回地址，放进去
	}
	//连接
	Graph[0]->neighbors.push_back(Graph[4]);
	Graph[0]->neighbors.push_back(Graph[2]);
	Graph[1]->neighbors.push_back(Graph[0]);
	Graph[1]->neighbors.push_back(Graph[2]);
	Graph[2]->neighbors.push_back(Graph[3]);
	Graph[3]->neighbors.push_back(Graph[4]);
	Graph[4]->neighbors.push_back(Graph[3]);

	int visit[MAX_N] = { 0 }; // 全是0的数组
	for (int i = 0; i < MAX_N; i++) {
		if (visit[i] == 0) { //visit[label] = 1为该节点已经被标记，即已经访问过
			printf("from lable (%d):", visit[i]);
			DFS_Graph(Graph[i], visit);
			printf("\n");
		}
	}

	system("pause");
	return 0;
}