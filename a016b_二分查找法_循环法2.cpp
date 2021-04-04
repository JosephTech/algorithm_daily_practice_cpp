#include <iostream>  // puase

int binary_search(int arr[], int n, int target) {  // ���ֲ��ҡ���������arr[]�� ����Ԫ�ظ���n�� ������Ŀ��target
	int l = 0, r = n;  // ά������[l, r), ����ҿ�
	while (l < r) {  // ��l==rʱ����[33,33)���Ϸ�
		int mid = (l + r) / 2;
		if (arr[mid] == target)  // �ҵ������ء�  ע��������==
			return mid;
		if (target > arr[mid])  // ���ұߵ�����
			l = mid + 1;  // �������
		else  // �����
			r = mid;  // �� ������
	}
	return -1;
}

int main() {
	int array[100];  // 100��Ԫ�ص�����
	for (int i = 0; i < 100; i++) {
		array[i] = i*10;
	}

	int res = binary_search(array, 100, 90);  // ���鲻������

	printf("res = %d\n", res);

	system("pause");
	return 0;
}