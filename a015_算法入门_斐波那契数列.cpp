/*
쳲��������У�
	f(n) = f(n-1) + f(n-2)
	����һ���� = ��֮ǰ�������ĺ�

���ӣ�
	1,1,2,3,5,8,13...
*/
/*
�ݹ�ʱ�临�Ӷȣ�
	O(2^n)
*/

#include <iostream>  // puase


int fib(int n) {  // n����쳲�������n������ֵ
	if (n == 0 || n == 1) {  // �ݹ��������
		return 1;
	}
	return fib(n - 1) + fib(n - 2);  // ֮ǰ�������ĺ�
}

int main() {
	int res = fib(6);
	printf("res = %d\n", res);

	system("pause");
	return 0;
}