/*
��aʱb�� �� cʱd�֣�һ���Ƕ೤ʱ�䡣 �����죬24Сʱ�ƣ�

���룺 a, b, c, d�ĸ�����

����� e��f����ʾ��Сʱ����
*/
/*
˼·��
	ͳһ�ɷ��ӣ�
	��
	/60�õ�Сʱ
	%60�õ�����
*/

#include <iostream>

int main() {
	int a, b, c, d;
	std::cin >> a >> b >> c >> d;
	int total_m = (60 * c + d) - (60 * a + b);
	int e = total_m / 60;
	int f = total_m % 60;
	std::cout << e << " "<< f;

	system("pause");
	return 0;
}


