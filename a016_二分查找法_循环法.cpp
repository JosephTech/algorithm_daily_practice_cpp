/*
���ֲ��ҷ���
	���� ��������int array[]   ��ע�����ź�������飩
	���鳤�� int n
	������Ԫ�� target
	�ҵ��򷵻� ������δ�ҵ�����-1

ÿ�η�������ң��м������ҵ����������������
*/
#include <iostream>  // pause,

int binary_search(int array[], int n, int target) {
	int l = 0, r = n - 1;  // ά�����䣬target��[0, n-1]�����䡣 ע��߽�
	while (l <= r) {  // ע�� ��l=rʱ�򣬱�������Ȼ�Ϸ���  ������l<=r
		int mid = (r + l) / 2;  // mid���м������� ע����r+l
		if (array[mid] == target) 
			return mid;
		if (target > array[mid]) //  ά��������
			l = mid + 1;
		else   // ά��������
			r = mid - 1;
	}
	return -1;
}

int main() {
	int arr[100];
	for (int i = 0; i < 100; i++) {
		arr[i] = 10 * i;
	}
	int res = binary_search(arr, 100, 990); // ���鲻��������
	printf("���� res = %d\n", res);

	system("pause");
	return 0;
}