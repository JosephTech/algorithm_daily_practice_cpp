/*
��Ŀ��
	��֪��1��n���������У� ��˳����ջ�� 
	ÿ��������ջ�󼴿ɳ�ջ��
	Ҳ����ջ��ͣ�����ȴ�����������ջ��ջ�󣬸������ٳ�ջ
	������ֵĳ�ջ�����Ƿ�Ϸ�
*/

#include <iostream>
using namespace std;
#include <stack>
#include <queue>
#pragma warning(disable:4996) //��ֹscanf����

// �жϴ���� ������Ԫ�ص�˳��  �Ƿ�Ϸ�������ջ��
bool check_is_valid_order(std::queue<int> queue_order) { //����һ�����У������һ��˳��
	//����ջ S��  ���ڴ�1~n
	std::stack<int> S; // SΪģ��ջ
	int n = queue_order.size();

	// ��1~n push��ջ�ÿpushһ�κ���while�ж� Sջ�� �� queue_order�Ķ���ͷ  �Ƿ���ͬ����ͬ�򵯳�
	for (int i = 1; i <= n; i++) { //��1��ʼ��ȡ��n
		S.push(i);
		while (!S.empty() && S.top()==queue_order.front()) {
			S.pop();
			queue_order.pop();
		}
	}
	if (!S.empty()) { // �����֡� ֻ��queue_order��S�е���ͬԪ�أ��Ż�һͬpop��Sʣ���У�ջ��Ϊ�գ�����queue_orderҲ��ʣ����
		return false;
	}
	return true;
} //�㷨���帴�Ӷ�O(n) ����Ϊ����Ԫ��ֻ��ջ��ջһ�Ρ� ����Ȼһ������һ��ջ�����ǳɶ������ֵģ�����n*nѭ���ģ�

// poj�������ύ
int main() {
	int n; // n=5,������5��Ԫ��
	int train;

	printf("������Ԫ�ظ�����0���أ���\n");
	scanf("%d", &n); //��ȡ�Ӽ������������
	printf("������Ԫ�ض��У����ÿո�ָ�����0���أ���\n");
	while (n) {
		scanf("%d", &train); //��һ��Ԫ�أ���push��order��
		while (train) {
			std::queue<int> order;
			order.push(train);
			for (int i = 1; i < n; i++) { //��push n-1��Ԫ�� push��order�С�һ��push��n��Ԫ��
				scanf("%d", &train);
				order.push(train);
			}
			// check_is_valid_order�������yes�����ӡyes�������no�����ӡno
			if (check_is_valid_order(order)) {
				printf("Yes\n");
			}
			else {
				printf("No\n");
			}
			printf("������Ԫ�ض��У����ÿո�ָ�����0���أ�~��\n");
			scanf("%d", &train); //����0,��break whileѭ��
		}
		printf("\n������Ԫ�ظ�����0���أ���\n");
		scanf("%d", &n); //����0,��break whileѭ��
		printf("\n������Ԫ�ض��У����ÿո�ָ�����0���أ�~~��\n");
	}

	system("pause");
	return 0;
}
// ע�⣺poj�õ���std::in��std::out�ļ����������  �ļ�һ�������룬��������ļ����д���ļ���
// ���ò��ģ������ύ���Ͷ���