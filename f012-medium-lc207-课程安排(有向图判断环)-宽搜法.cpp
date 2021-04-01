/*
�ڿ������������ʱ��ֻ�����Ϊ0�ĵ���������С�

�����һ��������������Ӷ���ȡ��������ָ������ж�����ȶ���1.

����ʱ��ĳ�������Ϊ0������������У�����ɿ��������

���е����ȶ�Ϊ0����ͼ�޻��������л���
*/
/*
ʲô�����d��
	��Ⱦ��� ������d�ſΡ�
		���� d�ſ�ָ����
*/
/*
�㷨�ؼ��㣺
	1���� ��� ��¼�����ڵ�ָ���Լ�
	2���� ���� ����
*/
#include <iostream>
#include <queue>
#include <vector>

//ͼ���ڽӱ� ���ݽṹ
struct GraphNode {
	int label; //��ǩֵ
	std::vector<GraphNode *> neighbors; //�ڽӵ�
	GraphNode(int x): label(x) {} //���캯��
};

class Solution {
public:
	bool canFinsh(int numCourses, 
		           std::vector<std::pair<int, int>> &prerequisites) { //����γ������������� ������ϵ��ǰ����������
		std::vector<int> degree; //��ȣ���¼������ָ���Լ�
		std::vector<GraphNode *> Graph;//��� ͼ�Ľڵ�
		std::queue<GraphNode *> Q; //��Žڵ��
		for (int i = 0; i < numCourses; i++) { //װ��Graph�� degreeװ0
			Graph.push_back(new GraphNode(i));
			degree.push_back(0);
		}
		for (int i = 0; i < prerequisites.size(); i++) { //���ߡ�degree��ʼ��
			GraphNode *begin = Graph[prerequisites[i].second];
			GraphNode *end = Graph[prerequisites[i].first];
			begin->neighbors.push_back(end);
			degree[prerequisites[i].first]++;
		}
		for (int i = 0; i < numCourses; i++) {
			if (degree[i] == 0) { // ���Ϊ0�� ��Ѷ�Ӧ�ڵ�push������Q
				Q.push(Graph[i]);
			}
		}
		while (!Q.empty()) { //���������neighbors��degre--����degree=0������С�
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
			delete Graph[i]; //��returnǰ���ͷŶ����ڴ�
		}
		for (int i = 0; i < numCourses; i++) {
			if (degree[i]) { //��ʣ�����л�
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