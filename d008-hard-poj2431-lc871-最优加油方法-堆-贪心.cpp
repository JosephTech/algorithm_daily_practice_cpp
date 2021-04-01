/*
���ż��ͷ�����
	��֪һ����·�ϣ���һ�������һ���յ㣬��֮����n������վ��
	��֪����n������վ���յ�ľ���d 
	�������վ���Լ��͵���l,
	���λ�����յ����L
	��ʼʱ�������е�����P

	����ʹ��һ����λ�����ͣ�����1����λ�ľ��룬����û������
	���ټӼ�����,���Դ���㿪���յ�? ������޷������յ㣬����-1��
*/
/*
˼����
	��������n������վ��������n������վ��Ӧ�����ĸ�����վͣ�������ͣ�
	���ռ��ܵ����յ㣬��ʹ�ü��ʹ������٣�

	����˳����ͣ������٣�
		�����ĳ������վ���ͣ�������û��Ҫ�ģ��п��ܲ�������μ���Ҳ�ܵ����յ�

		�����ĳ������վ��ͣ�������ͣ������������Ͳ������޷������յ㣬 ���ߺ���Ҫ����μ��Ͳ��ܵ����յ�
*/
/*
̰��˼·��
	��ǰ�����ܵ��ľ��룬  ��֮��ļ���վ���ĸ�������࣬�����ĸ���

	���ù���������
	�������ļ���վ���������

һ�仰�ܽ᣺
	�����ߵ�ʱ�򣬿���֮ǰ��ô�ӣ��ӵ�����Խ��Խ�á�
*/
/*
����Ծ��Ϸ��һ���ĵط���
	���Ϳ��ԼӶ�Σ�
	������Ҫά��һ�����ѣ����洢�����ļ���վ������������nlogn��

	ÿ����һ������Σ����벻�����ʹ� ����ȡ һ���ͣ���ȡ��Σ���ֱ�����빻��
*/
#include <iostream> // pause
#include <vector>
#include <algorithm> //sort
#include <queue> // ����priority_queue
#pragma warning(disable:4996)

bool cmp(const std::pair<int, int> &a, const std::pair<int, int> &b) //const��ֹ�������޸�
{
	return a.first > b.first; // ��Զ����
}

int get_minimum_stop(int L, int P, //����վ���յ�ľ���L�� ����վ��������P
	std::vector<std::pair<int,int>> &stops)// վ��stops���� <�ü���վ���յ���룬�ü���վ����> 
{
	std::priority_queue<int> Q; // ���ѣ���ߴ������
	stops.push_back(std::pair<int, int> (0, 0)); //�յ�վ����0, 0��
	std::sort(stops.begin(), stops.end(), cmp); //������Զ���� ����
	int result = 0; //���ͼ���
	// ����P��ʾ��ǰ������  ����L��ʾǰһ��վ�㵽�յ���롣 ����Ҫ��iվ��
	for (int i = 0; i < stops.size(); i++) { //i = 0�ǵ�һ����վ����Ϊ���û����stops��
		int dis = L - stops[i].first; // ��iվ��ľ����
		while (!Q.empty() && P < dis) { // ջ���� �� �Ͳ�������ջ������Ϊ�˷�ֹ����һֱ����һֱ��
			P += Q.top(); //����
			Q.pop(); //��ջ
			result++; //��¼���ʹ���
		}
		if (Q.empty() && P < dis) { //û���ˣ�P��С�ھ��룬����
			return -1;
		}
		P -= dis; //�ߵ�iվ���ˣ���������
		L = stops[i].first; //���¾���
		Q.push(stops[i].second); // ��iվ�� ������ �ŵ��������
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
	scanf("%d", &N); // վ��4
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &distance, &fuel); //վ�㵽�յ����,վ������  4,4;  5,2;  11,5�� 15,10; 
		stops.push_back(std::make_pair(distance, fuel));
	}
	scanf("%d  %d", &L, &P); //  25,10 �������룬�������
	printf("��С���ʹ��� = %d\n", get_minimum_stop(L, P, stops));

	system("pause");
	return 0;
}
