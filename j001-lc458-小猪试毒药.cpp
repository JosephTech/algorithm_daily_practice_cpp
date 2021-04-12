/*
lc458С���Զ�ҩ
*/

#include <iostream>  // pause

class Solution {
public:
	int poorPigs(int buckets, int minutesToTest, int minutesToDie) {  // ����Ͱˮ�� ���Զ��ٷ��ӣ��ȵ���ҩ����������
		int time = minutesToTest / minutesToDie + 1;  // һֻ�� ���� ���Լ�Ͱˮ
		int pigs_num = ceil(log(buckets) / log(time));  // c++��log����eΪ�׵�
		return pigs_num;
	}
};

int main() {
	Solution solve;  // ʵ����
	int num = solve.poorPigs(1000, 60, 15);  // 1000Ͱˮ��ֻ��һͰ�ж����� 60���Ӳ���ʱ�䣬��ȵ���ҩ15��������
	printf("%d\n", num);

	system("pause");
	return 0;
}
