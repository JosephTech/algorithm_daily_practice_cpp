/*
һֻ�ʵļ۸���1Ԫ9�ǣ� �������θ�С�� ��Ǯ��aԪb�ǣ� �������ֻ�ʣ�

a<=10000, b <= 9

���������������
*/
/*
˼·��
	ͳһ�����⣬ת��Ϊ��
*/
#include <iostream>  // pause

int buyPenNum(int a, int b) {
	int total_money = 10 * a + b;
	int num = total_money / 19;  // ȡ�������֣� python������//��ȡ���� c++��1��/��ȡ��
	return num;
}

int main() {
	int res = buyPenNum(17, 2);
	printf("res = %d\n", res);

	system("pause");
	return 0;
}