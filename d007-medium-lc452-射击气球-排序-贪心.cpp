/*
�������
	��֪��һ��ƽ������һ������������ƽ����Կ���һ������ϵ��
	��ƽ���x��Ĳ�ͬλ�ð��Ź�������y�᷽�����������������y��������Զ��
	��������Ŀ��xstart << x << xend
	��������Ҫ���ٹ����֣���ȫ������򱬣�

���磺
	�ĸ����� [[10,16], [2,8], [1,6], [7,12]]
	������Ҫ2��������
*/
/*
̰��˼�룺
	һֻ����������Ҫ1ֻ����
	�ڽ���ֻ���������ͬʱ�������ܻ���������������򣡣�̰�ģ�
*/
/*
�㷨˼·��
	1��������������򣬰����������˵��С��������
	2��ά��һ��������䣬��������Խ���ǰ�����䴩������£������ܻ������������
		ÿ����һ�������򣬸���һ��������䣨����֤���������Ի�����Щ���򣩡�
	3������µ�����û�������ˣ�����Ҫ����һ�������֣���ά��һ���µ�������䡣����
	
	ѭ������ָ����������������
*/

#include <iostream>
#include <vector>
#include <algorithm>

//�ȽϺ���
bool cmp(std::pair<int, int> &a, std::pair<int, int> &b) { //�������� pair< T,T> &a  ��&b
	return a.first < b.first; //��˵��С��������  �˴���������˵��ظ���һ�ῼ����˵�� �����Ҷ˵��ظ�����
}

class Solution {
public:
	int findMinArrayShots(std::vector<std::pair<int, int>> &balloons) { //����vector. ���pair�������������Ҷ˵�
		if (balloons.empty()) { //�յĻ��������������
			return 0;
		}
		std::sort(balloons.begin(), balloons.end(), cmp); //����
		int shoot_begin = balloons[0].first; //ά��һ������
		int shoot_end = balloons[0].second;
		int num_shots = 1; //��¼����� ����
		for (int i = 1; i < balloons.size(); i++) { //��λ������1��ʼ������
			//����һ����.first <= shoot_endʱ�򣬸���shoot_begin��
			if (balloons[i].first <= shoot_end) { //������
				shoot_begin = balloons[i].first; //��Ϊ֮ǰ�����ˡ����� ���������˵�һ������shoot_begin
				if (balloons[i].second < shoot_end) { //��˵�С�ڵ��ڵ�ͬʱ���Ҷ˵�ҲС��������
					shoot_end = balloons[i].second;
				}
			}
			else { //ά��������
				num_shots++; //��¼ ����������
				shoot_begin = balloons[i].first;
				shoot_end = balloons[i].second;
			}
		}
		return num_shots;
	}
};

int main() {
	std::vector<std::pair<int, int>> balloons;
	balloons.push_back(std::make_pair(10, 16));
	balloons.push_back(std::pair<int, int>(2, 8));
	balloons.push_back(std::pair<int, int>(1, 6));
	balloons.push_back(std::pair<int, int>(7, 12));

	Solution solve;
	printf("nums of shots =  %d\n", solve.findMinArrayShots(balloons));

	system("pause");
	return 0;
}