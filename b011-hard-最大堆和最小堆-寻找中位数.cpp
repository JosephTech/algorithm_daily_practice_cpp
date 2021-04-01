/*
Ѱ����λ����
	�ö���һ������Ľⷨ
	�ö�����Ҳ��һ������Ľⷨ
*/
/*
��Ŀ��
	���һ�����ݽṹ�������ݽṹ��̬ά��һ�����ݣ���֧�����²�����
		1�����Ԫ�أ� void addNum(int num),������num��������ݽṹ��
		2���������ݵ���λ���� double findMedium(), ������ά�����ݵ���λ��
	��λ���Ķ��壺
		1�������ݸ���Ϊ����������λ���Ǹ���������� �м������ ����[1��2��3] -��2
		2�������ݸ���Ϊż��������λ���Ǹ�����������н���������ƽ��ֵ�� [1, 2, 3, 4] -> 2.5
*/

/*
//���ݽṹ
class MedianFinder{
public:
	MedianFinder(){
	}
	// �����ݽṹ�� �������
	void addNum(int num){
	}
	// ����(���ݽṹ��ά����)��λ��
	double findMedian(){
	}
};
*/
/*
��ֱ�۵ķ�����
	�洢�ṹʹ�����飬ÿ�� ���Ԫ�� �� ������λ��ʱ�������������ټ�����
ʱ�临�Ӷȣ�
	?1�������Ԫ��ʱ���� addNum���Ӷ���O(n)�� findMedian���Ӷ���O(1)
	?2������ѯ��λ��ʱ����addNum���Ӷ���O(1),findMedian���Ӷ�O(nlogn)

?�� ���Ԫ�� �� ��ѯ��λ���������������n�β�����������˼�룬���帴�Ӷ����ΪO(n^2)����O(n*n)
*/
/*
˼·��
	��̬ά�� һ������ �� һ����С�ѣ� ���Ѵ洢һ�����ݣ���С�Ѵ洢һ�����ݣ�
	ά�� ���ѵĶѶ�������С�ѵĶѶ� С��
	������ ������һ�������ǣ� ��С����һ�������ǣ�
	������ż���� ʱ����λ���� �����Ѷ���ƽ��ֵ
	������������ ʱ����λ���� ��Ķ� �ĶѶ�
*/

#include <queue>
#include <stdio.h>
#include <functional>

// ���ݽṹ
class MedianFinder {
public:
	// ���캯��
	MedianFinder() {
	}
	// ���Ԫ�أ���̬ά���ѣ�
	void addNum(int num) {
		// �գ�ѹ��ȥ��return
		if (big_queue.empty()) {
			big_queue.push(num);
			return;
		}
		// ���һ��size��
		if (big_queue.size() == small_queue.size()) {
			if (num < big_queue.top()) {
				big_queue.push(num);
			}
			else {
				small_queue.push(num);
			}
		}
		// �����������size��
		else if (big_queue.size() > small_queue.size()) {
			if (num > big_queue.top()) {
				small_queue.push(num);
			}
			else {
				small_queue.push(big_queue.top());
				big_queue.pop();
				big_queue.push(num);
			}
		}
		// �����������sizeС
		else if (big_queue.size() < small_queue.size()) {
			if (num < small_queue.top()) {
				big_queue.push(num);
			}
			else {
				big_queue.push(small_queue.top());
				small_queue.pop();
				small_queue.push(num);
			}
		}
	}
	// ������λ��
	double findMedian() { // ˫���ȸ���
		// size�ȣ� ȡtop ƽ��
		if (big_queue.size() == small_queue.size()) {
			//return((big_queue.top() + small_queue.top()) / 2);  //��ǿת�����ͱ�����

			double big_top = (double)big_queue.top(); //ǿת
			double small_top = (double)small_queue.top(); //ǿת
			return ((big_top + small_top) / 2);
		}
		// ˭��ȡ˭
		else if (big_queue.size() > small_queue.size()) {
			return big_queue.top();
		}
		return small_queue.top();
	}
private:
	std::priority_queue<int, std::vector<int>, std::less<int>> big_queue; // ����
	std::priority_queue<int, std::vector<int>, std::greater<int>> small_queue; // ��С��
};

int main() {
	int a = 2;
	int b = 3;
	//double c = (a+b)/2; //��ʽת��������
	double c = ((double)(a + b)) / 2; //ǿת����
	printf("c = %lf\n", c); // %f�Ǹ����� %lf��˫���ȸ�����

	//���Դ���
	MedianFinder M; //ʵ����
	int test[] = { 6, 10, 1, 7, 99, 4, 33 }; //��������test[]
	for (int i = 0; i < sizeof(test) / sizeof(test[0]); i++) {
		M.addNum(test[i]);
		printf("%lf\n", M.findMedian());
	}

	system("pause");
	return 0;
}