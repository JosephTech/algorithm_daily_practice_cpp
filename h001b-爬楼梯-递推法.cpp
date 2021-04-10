/*
˼����
	��i��¥�� �� ǰ��� ����ЩЩ��¥������������ ��ֱ����صģ�
	��ô���Ƴ���i���м���������

�𰸣�
	��i���������� = ����i-1������������ + ����i-2������������
	��3���������� = ����1������������+ ����2������������
	��4���������� = ����3������������ + ����2������������
*/
#include <iostream>
#include <vector>  // ������vector�� Ĭ������������

class Solution {
public:
	int climbStairs(int n) {  // һ��n��¥��
		std::vector<int> vec(n+3, 0);  // n+3��0  ����
		vec[0] = 1;
		vec[1] = 2;
		for (int i = 2; i < n; i++) {
			vec[i] = vec[i - 2] + vec[i - 1];
			//printf("%d\n",vec[i]);
		}
		return vec[n - 1];  // ���һ��Ԫ��
	}
};

int main() {
	Solution solve;  // ʵ����
	int res = solve.climbStairs(10);

	printf("%d\n", res);

	system("pause");
	return 0;
}