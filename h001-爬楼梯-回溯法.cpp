/*
leetcode 70 climbing stairs
��¥��
*/
/*
��Ŀ��
	����¥��ʱ��ÿ�ο�����1��̨�ף�����2��̨�ף� ����n��¥���ж�������¥��ʽ
*/
/*
˼·1��
	������������ ����
*/

#include <iostream>

class Solution {
public:
	int climbStairs(int n){  //  ����n��¥��
		if (n == 1 || n == 2)
			return n;   // 1��¥����1���߷��� 2��¥����2���߷�
		return climbStairs(n - 1) + climbStairs(n - 2);  // �ݹ���ʣ�µ�n-1�ף��ݹ���ʣ�µ�n-2��
	}
};

/*
ע�⣺
	���ַ�����ʱ
*/


int main(){
	Solution solve;
	int n = solve.climbStairs(10);
	printf("%d\n", n);

	system("pause");
	return 0;
}