/*
题目：课程安排
	一共有n个课程，记为0 ~ n-1，课程之间有依赖关系

	例如：
	希望完成A课程，可能需要先完成B课程。

	已知n个课程的依赖关系，求是否可以把课程全部完成？

	传入 int numCourases课程数量
	传入 std::vector<std::pair<int, int>> &preRequisites  前边int依赖后边int
*/
/*
思路分析：
	三门课作为三个顶点，想象成一个图，

	如果是 有向无环图 ，则可以修完全部课程，否则不能。

	即判断图是否有环，有环，则不能修完
*/

/*
方法一：
	深度优先搜索

	正在搜索某一顶点，又回到了该顶点，则有环
	（正在搜索的意思，就是从该顶点开始，往后搜）
	（注意：不管有没有环。回退，搜索其他顶点，都会再遇到这个顶点）
*/

#include <iostream> //pause用的
#include <vector> //存neighbors用的

struct GraphNode { //构建 邻接表 数据类型
	int label; //节点的值
	std::vector<GraphNode *> neighbors; //邻居
	GraphNode(int x): label(x) {} // 构造函数，只需初始化label
};

class Solution {
public:
	bool canFinish(int numCourses,
					std::vector<std::pair<int,int>> &prerequisites) { 
		//传入课程数numCourses。传入vector套pair<课1， 课2>。课1 依赖 课2。 即课2指向 课1
		std::vector<GraphNode*> Graph; //放节点的 
		std::vector<int> visit; //记录是否访问过，-1未访问，0正在访问，1访问完成
		for (int i = 0; i < numCourses; i++) { // 装进去
			Graph.push_back(new GraphNode(i)); //图  节点要建立在堆区
			visit.push_back(-1);
		}
		for (int i = 0; i < prerequisites.size(); i++) { //连接
			GraphNode *end = Graph[prerequisites[i].first];
			GraphNode *begin = Graph[prerequisites[i].second];
			begin->neighbors.push_back(end);
		}
		for (int i = 0; i < numCourses; i++) { //宽搜
			if (visit[i] == -1 && !DFS_search(Graph[i], visit)) { //当有环，DFS返回了false, !DFS就是ture。 绕啊
				return false; //有环，返回false
			}
		}
		for (int i = 0; i < numCourses; i++) {
			delete Graph[i];
		}
		return true; //返回true,代表无环
	}
private:
	bool DFS_search(GraphNode *node, std::vector<int> &visit) { //深度优先搜索，传入节点* 。  传入visit[label] 
		//-1表示没有访问过。 0表示正在访问。 1表示已经访问完成
		//传入引用，防止拷贝构造，直接修改原visit
		visit[node->label] = 0; //正在访问
		for (int i = 0; i < node->neighbors.size(); i++) {
			if (visit[node->neighbors[i]->label] == -1) { //若没访问过 下个节点，就递归访问。若返回false，就return上一层
				if (DFS_search(node->neighbors[i], visit) == 0) { //递归访问，如果返回了false，就继续返回上一层，说明 有环
					return false;
				}
			}
			else if (visit[node->neighbors[i]->label] == 0) { //真正的 递归结束条件。 当下一个节点，已经标记为0，即访问过的时候
				return false;
			}
		}
		visit[node->label] = 1;// 该顶点访问完成
		return true; //标记完访问完成，再return
	}
};

int main() {
	std::vector<std::pair<int, int>> prerequisites; //pair<课1， 课2>。课2指向课1，即1依赖2
	prerequisites.push_back(std::make_pair(0, 1));
	prerequisites.push_back(std::make_pair(2, 0));
	prerequisites.push_back(std::make_pair(1, 3));
	prerequisites.push_back(std::make_pair(3, 2));

	Solution solve;
	printf("%d\n", solve.canFinish(4, prerequisites));

	system("pause");
	return 0;
}