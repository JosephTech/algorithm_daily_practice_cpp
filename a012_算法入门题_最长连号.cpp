/*
��Ŀ��
	����n������������1 <= n <= 10000���������������ŵĳ��ȡ� ������ָ��С����������Ȼ����
*/
/*
�����ʽ��
	��һ�У� һ����n;
	�ڶ��У� n����������֮���ÿո������

�����ʽ��
	һ����������Ÿ�����
*/

#include <iostream>  // pause, cin, cout
#include <vector>  // std::vector

int main() {
	int n, cnt = 1, max = 1; // max��������ţ�cnt�Ǽ�������cnt>max������max��
	int arr[10000 + 5];
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];  // ע��vector����cin�� �������cin
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] + 1 == arr[i + 1]) { // ������������
			cnt += 1;
			if (cnt > max) {
				max = cnt;  // ������������max
			}
		}
		else cnt = 1; // �������ţ��������cnt��ʼ��
	}
	std::cout << max;
	printf("\n");

	system("pause");
	return 0;
}