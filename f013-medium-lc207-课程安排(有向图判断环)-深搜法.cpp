/*
��Ŀ���γ̰���
	һ����n���γ̣���Ϊ0 ~ n-1���γ�֮����������ϵ

	���磺
	ϣ�����A�γ̣�������Ҫ�����B�γ̡�

	��֪n���γ̵�������ϵ�����Ƿ���԰ѿγ�ȫ����ɣ�

	���� int numCourases�γ�����
	���� std::vector<std::pair<int, int>> &preRequisites  ǰ��int�������int
*/
/*
˼·������
	���ſ���Ϊ�������㣬�����һ��ͼ��

	����� �����޻�ͼ �����������ȫ���γ̣������ܡ�

	���ж�ͼ�Ƿ��л����л�����������
*/

/*
����һ��
	�����������

	��������ĳһ���㣬�ֻص��˸ö��㣬���л�
	��������������˼�����ǴӸö��㿪ʼ�������ѣ�
	��ע�⣺������û�л������ˣ������������㣬����������������㣩
*/

#include <iostream> //pause�õ�
#include <vector> //��neighbors�õ�

struct GraphNode { //���� �ڽӱ� ��������
	int label; //�ڵ��ֵ
	std::vector<GraphNode *> neighbors; //�ھ�
	GraphNode(int x): label(x) {} // ���캯����ֻ���ʼ��label
};

class Solution {
public:
	bool canFinish(int numCourses,
					std::vector<std::pair<int,int>> &prerequisites) { 
		//����γ���numCourses������vector��pair<��1�� ��2>����1 ���� ��2�� ����2ָ�� ��1
		std::vector<GraphNode*> Graph; //�Žڵ�� 
		std::vector<int> visit; //��¼�Ƿ���ʹ���-1δ���ʣ�0���ڷ��ʣ�1�������
		for (int i = 0; i < numCourses; i++) { // װ��ȥ
			Graph.push_back(new GraphNode(i)); //ͼ  �ڵ�Ҫ�����ڶ���
			visit.push_back(-1);
		}
		for (int i = 0; i < prerequisites.size(); i++) { //����
			GraphNode *end = Graph[prerequisites[i].first];
			GraphNode *begin = Graph[prerequisites[i].second];
			begin->neighbors.push_back(end);
		}
		for (int i = 0; i < numCourses; i++) { //����
			if (visit[i] == -1 && !DFS_search(Graph[i], visit)) { //���л���DFS������false, !DFS����ture�� �ư�
				return false; //�л�������false
			}
		}
		for (int i = 0; i < numCourses; i++) {
			delete Graph[i];
		}
		return true; //����true,�����޻�
	}
private:
	bool DFS_search(GraphNode *node, std::vector<int> &visit) { //�����������������ڵ�* ��  ����visit[label] 
		//-1��ʾû�з��ʹ��� 0��ʾ���ڷ��ʡ� 1��ʾ�Ѿ��������
		//�������ã���ֹ�������죬ֱ���޸�ԭvisit
		visit[node->label] = 0; //���ڷ���
		for (int i = 0; i < node->neighbors.size(); i++) {
			if (visit[node->neighbors[i]->label] == -1) { //��û���ʹ� �¸��ڵ㣬�͵ݹ���ʡ�������false����return��һ��
				if (DFS_search(node->neighbors[i], visit) == 0) { //�ݹ���ʣ����������false���ͼ���������һ�㣬˵�� �л�
					return false;
				}
			}
			else if (visit[node->neighbors[i]->label] == 0) { //������ �ݹ���������� ����һ���ڵ㣬�Ѿ����Ϊ0�������ʹ���ʱ��
				return false;
			}
		}
		visit[node->label] = 1;// �ö���������
		return true; //����������ɣ���return
	}
};

int main() {
	std::vector<std::pair<int, int>> prerequisites; //pair<��1�� ��2>����2ָ���1����1����2
	prerequisites.push_back(std::make_pair(0, 1));
	prerequisites.push_back(std::make_pair(2, 0));
	prerequisites.push_back(std::make_pair(1, 3));
	prerequisites.push_back(std::make_pair(3, 2));

	Solution solve;
	printf("%d\n", solve.canFinish(4, prerequisites));

	system("pause");
	return 0;
}