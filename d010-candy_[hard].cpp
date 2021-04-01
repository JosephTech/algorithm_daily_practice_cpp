/*
��Ŀ��
	ÿ���������ٷ�һ���ǡ�
	ÿ�������и�rating�� ��ÿ������rating�� ���ҵĺ��Ӹߣ�������������Ҫ�ࡣ
	�����ٹ���Ҫ������

���磺
	���룺vector<int> ratings   [1,0,2]
	�����ٷ��� [2, 1, 2]�� ��5��

˼����
	̰�ģ� Խ��Խ��

�㷨˼·��
	��-���ң������� ����rating>��rating�� �� �� = ��+1
	��
	��-���� ������ ����rating>��rating�� �� �� = ��+1
	������
*/
#include <iostream>  // puase, cout
#include <vector>  // std::vector
#include <numeric>  // std::accumulate


class Solution {
public:
	int candy(std::vector<int> &ratings) {  //��������
		int size = ratings.size();
		if (size < 2) {
			return size;  // ��0��1���ӣ� ÿ��һ���Ǽ���
		}
		std::vector<int> cookies(size, 1);  // size��1
		for (int i = 1; i < size; i++) {
			if (ratings[i - 1] < ratings[i]) {
				cookies[i] = cookies[i - 1] + 1;  // ��rating������cookie=��+1
			}
		}
		for (int i = size - 1; i > 0; i--) {  //i��С=1����ΪiҪ-1�� i���=size-1,��Ϊ����0��ʼ
			if (ratings[i - 1] > ratings[i]) {
				cookies[i - 1] = cookies[i] + 1;  //��rating������cookie=��+1
			}
		}
		return std::accumulate(cookies.begin(), cookies.end(), 0);  // �ۼӵĳ�ʼֵ��0
	}
};


int main02() {
	std::vector<int> ratings;
	ratings.push_back(1);
	ratings.push_back(0);
	ratings.push_back(2);
	//ratings.push_back(1);

	Solution solve;
	int res = solve.candy(ratings);
	printf("������Ҫ%d���ǹ�\n", res);


	system("pause");
	return 0;
}