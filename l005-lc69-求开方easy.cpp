/*
��Ŀ������
	����һ�� �Ǹ������������Ŀ���������ȡ��

���磺
	����8
	��8 = 2.82
	ȡ������2
*/
/*
����һ�����ַ�
��������ţ�ٵ�����������
*/
#include <iostream>

class Solution {
public:
	int mySqrt(int a) {  // ��a��ƽ����
		int left = 1;
		int right = a;  // ����ұ�
		while (left <= right) {  // ����ұ�
			int mid = left + (right - left) / 2;
			if (mid == a/mid) {
				return mid;  //  ����3^2 = 9
			}
			else if (mid < a/mid) {
				left = mid + 1;  // �ڴ����һ��  �� ����a
			}
			else if (mid > a/mid) {
				right = mid - 1;  // ��С����һ���� ����a
			}
		}
		return right;  // ��Ϊleft�Ѿ�����right�ˣ�����right����
	}
};

int main() {
	Solution solve;  // ʵ����
	int res = solve.mySqrt(100000);
	printf("%d\n", res);

	system("pause");
	return 0;
}

