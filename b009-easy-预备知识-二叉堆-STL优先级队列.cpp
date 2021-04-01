/*
 ������ѣ����ֵ�ȳ�����ȫ��������
 ��С����ѣ���Сֵ�ȳ�����ȫ��������
*/
/*
��С����ѡ�������ѣ�
		top()��ʱ�临�Ӷ�O(1)
		�����������ʱ�临�Ӷ� log(n)

������ѵ����ԣ�
		���ѵ��������� �����ѡ���������������

		��С�� �� �Ӷ� ������С��
*/

// ����
// STL���ȼ����У���������
// ����ѣ� ��С����ֵ�ȳ�����ȫ��������Ҳ�������ȼ�����
// ��STL�У����ȼ�������<queue>ͷ�ļ���
#include <stdio.h>
#include <queue>
#include <functional> //������һ�䣬std::greater�Ų��ᱨ��

int main() {
	std::priority_queue<int> big_heap; // Ĭ�Ϲ�������,���Ӵ�С���ӡ� ����Ϊɶ���»��ߣ�
	std::priority_queue<int, std::vector<int>, std::greater<int> > small_heap; //������С�ѡ�����С�������
	std::priority_queue<int, std::vector<int>, std::less<int> > big_heap2; // �������ѡ� ���ӴӴ�С����

	// ����,��ӡһ�仰
	if (big_heap.empty()) {
		printf("big_heap is empty! \n");
	}
	
	// ��������test�� 6�� 10�� 1�� 7�� 99�� 4�� 33
	int test[] = { 6, 10, 1, 7, 99 , 4, 33 };

	// forѭ����push��ȥ
	for (int i = 0; i < sizeof(test) / sizeof(test[0]); i++) {
		big_heap.push(test[i]);
	}

	//��ӡtop
	printf("����ѣ����ֵ�ȳ�����ȫ������(Ҳ�����ȼ�����)��top = %d\n", big_heap.top());

	// .push(1000)����ӡ
	big_heap.push(1000); // push����ʱ�����㸴�Ӷ���log(n), ����n��Ԫ�ظ���
	printf("����� top = %d\n", big_heap.top());

	// pop����
	for (int i = 0; i < 3; i++) {
		big_heap.pop();
	}

	//��ӡtop
	printf("top = %d\n", big_heap.top());

	// ��ӡsize
	printf("size = %d\n", big_heap.size());

	system("pause");
	return 0;
}