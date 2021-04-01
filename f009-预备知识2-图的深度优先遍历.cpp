/*
Ԥ��֪ʶ��ͼ��������ȱ���

�����ܷ��ʾͷ��ʣ����ʲ����ͻ��ˣ��������ʣ�
���ж���δ�����ʵ����ʹ��Ǹ���������������������㣬ֱ�����ж��㶼�����ʵ���
*/
/*
���壺
	��ͼ��ĳ������v���������ȷ��ʸö��㣬Ȼ������ĸ���δ�����ʵ��ڽӵ������
	���������������ͼ��ֱ��ͼ�����к�v·����ͬ��δ�����ʵĶ��㶼�����ʵ���
	����ʱ������������δ�����ʵ�������ѡһ��δ�����ʵĶ�����Ϊ��ʼ�㣬
	�ظ��������̣�ֱ��ͼ�����ж��㶼�����ʵ�Ϊֹ��
*/
/*
˼·������
	��Ҫ��¼ĳ���ڵ㻹û�б����ʵ���
	��Ϊ ·�������л�

���Ƕ������Ͳ������ĳ���ڵ�δ�����ʵ����������Ϊ�ǵ����
*/

#include <iostream> //pause�õ�
#include <vector>

struct GraphNode { //����ͼ���ڽӱ����ݽṹ
	int label;
	std::vector<GraphNode *> neighbors; //����� �ڵ�
	GraphNode (int x): label(x){} //���캯��,ֻ�ø�label��ֵ
};

//ͼ��������ȱ���DFS,  (����label��ֵ) 
void DFS_Graph(GraphNode *node, int visit[]) { //����ڵ�*   ����visit���飬���ʹ���visit[label]=1
	visit[node->label] = 1; //���ʹ������Ϊ1
	printf("%d ", node->label); //���ʵ�ǰ�ڵ�
	for (int i = 0; i < node->neighbors.size(); i++) { //�������ڽڵ�
		if (visit[node->neighbors[i]->label] == 0) { //û���ʹ����͵ݹ����
			DFS_Graph(node->neighbors[i], visit); //ȫ���ݹ�ݹ��꣬���Զ������ˣ����Բ���дreturn
		}
	}
}

int main() { 
	//����ͼ�Ķ���
	const int MAX_N = 5; //������
	GraphNode *Graph[MAX_N]; //���飬װ5��ͼ�ڵ�*
	for (int i = 0; i < MAX_N; i++) {
		Graph[i] = new GraphNode(i); //�����½������ص�ַ���Ž�ȥ
	}
	//����
	Graph[0]->neighbors.push_back(Graph[4]);
	Graph[0]->neighbors.push_back(Graph[2]);
	Graph[1]->neighbors.push_back(Graph[0]);
	Graph[1]->neighbors.push_back(Graph[2]);
	Graph[2]->neighbors.push_back(Graph[3]);
	Graph[3]->neighbors.push_back(Graph[4]);
	Graph[4]->neighbors.push_back(Graph[3]);

	int visit[MAX_N] = { 0 }; // ȫ��0������
	for (int i = 0; i < MAX_N; i++) {
		if (visit[i] == 0) { //visit[label] = 1Ϊ�ýڵ��Ѿ�����ǣ����Ѿ����ʹ�
			printf("from lable (%d):", visit[i]);
			DFS_Graph(Graph[i], visit);
			printf("\n");
		}
	}

	system("pause");
	return 0;
}