/*
����֪ʶ��ͼ�� ����������� breadth-first search
	������⣺
			ѡһ����δ�����ʹ��ģ�����������ȷ���-1�㣬�ٷ���-2��
	�ظ����ϲ��裬ֱ��ͼ�����ж��㶼�����ʵ�Ϊֹ
*/
/*
�ö���ȥά�� �ڵ��ǣ�  ���Ӷ�O(n)
*/

#include <iostream> //puase�õ�
#include <queue> //ͼ�Ŀ��ѣ�ά��һ������
#include <vector> // ���ͼ�� �ڽӵ�

struct GraphNode { //ͼ�ڵ� ���ݽṹ
	int label;
	std::vector<GraphNode *> neighbors;
	GraphNode(int x): label(x) {} //���캯��. ֻ�ø�label��ֵ
};

void BFS_search(GraphNode *node, int visit[]) { //����ڵ�*,   ����visit[label]�����ʹ�����Ϊ1
	std::queue<GraphNode *> Q;
	Q.push(node);
	visit[node->label] = 1; //�����ʱ�򣬱��Ϊ1
	while (!Q.empty()) { //���в��գ��ͷ���label����������neighbor�ŵ�������
		GraphNode * node2 = Q.front(); //���½�һ��node����
		printf("%d ", node2->label);  //����label
		Q.pop();
		for (int i = 0; i < node2->neighbors.size(); i++) {
			if (visit[node2->neighbors[i]->label] == 0) { //���û���ʹ����ͷŵ�Queue��
				Q.push(node2->neighbors[i]);
				visit[node2->neighbors[i]->label] = 1; //�����ʱ�򣬱��Ϊ1
			}
		}
	}
}
int main() {
	const int MAX_N = 5; //����ͼ�Ķ��㣬����new
	GraphNode *Graph[MAX_N];
	for (int i = 0; i < MAX_N; i++) {
		Graph[i] = new GraphNode(i);
	}

	//����
	Graph[0]->neighbors.push_back(Graph[4]);
	Graph[0]->neighbors.push_back(Graph[2]);
	Graph[1]->neighbors.push_back(Graph[0]);
	Graph[1]->neighbors.push_back(Graph[2]);
	Graph[2]->neighbors.push_back(Graph[3]);
	Graph[3]->neighbors.push_back(Graph[4]);
	Graph[4]->neighbors.push_back(Graph[3]);

	//����bfs
	int visit[MAX_N] = { 0 }; //ȫ0����
	for (int i = 0; i < MAX_N; i++) {
		if (visit[i] == 0) { //δ���ʵ�ʱ���Ըýڵ�Ϊ���㣬�Ӹõ����
			printf("��label��%d����ʼ���ʣ�", Graph[i]->label);
			BFS_search(Graph[i], visit);
			printf("\n");
		}
	}

	//ɾ��
	for (int i = 0; i < MAX_N; i++) {
		delete Graph[i];
	}
	system("pause");
	return 0;
}
// ע�⣺printf  scanfҪ��cin  cout�������ε����ܿ�ܶ�
// iostream��������ʽ ������������ ����
// stdio.h�ǰ�����  printf scanf�Ⱥ���
// 