/*
Ԥ��֪ʶ��
	c++��sort������lamda���ʽ�Զ�������
	https://blog.csdn.net/dong_beijing/article/details/81057918
	sort�Զ��������lambda���ʹ��
	https://blog.csdn.net/weixin_42714773/article/details/109722485?utm_medium=distribute.pc_relevant.none-task-blog-baidujs_title-1&spm=1001.2101.3001.4242
	C++sort���ʹ��lambda���ʽ��һάvector�Ͷ�άvector��������
	https://lishizheng.blog.csdn.net/article/details/112250038
*/

/*
��Ŀ��
	����ɾ���������䣬�����䲻�ص���

���ӣ�
	����std::vector<std::vector<int>>  [[1,2], [2,4], [1,3]]   ÿ��Ԫ�ر�ʾ��ʾ�������β
	����� int 1  ��ʾɾ��1������
	������ɾ��[1,3]��
*/

/*
˼����
	���ȱ��� �����βС �� ���ص�������
	������
	���ص�����ֻ������С�ģ�
*/

/*
�㷨˼·��
	1��������β���� ��[[1,2], [1,3], [2,4]]
	2����ʼ������[1,2]
	3���ص�������[1,2] ����ɾ��[1,3]��
	4������[2,4]
*/


#include <iostream>  // pause, cout
#include <vector>   // std::vector
#include <algorithm>  // std::sort


class Solution {
public:
	int eraseOverlapIntervals(std::vector<std::vector<int>> &intervals) {  // �������ã���ֹ�������졣����,����[[1,3],[1,3],[2,4]]
		if (intervals.empty()) {
			return 0;  //����գ�����0
		}
		std::sort(intervals.begin(), intervals.end(), [](std::vector<int> a, std::vector<int> b) {
			return a[1] < b[1];
		});  // lambda�����������������β  ��С��������
		int total = 0, pre_end = intervals[0][1];  // total��¼ɾ��������pre_end��¼ǰһ����β
		for (int i = 1; i < intervals.size(); i++) {
			if (intervals[i][0] < pre_end) {
				total += 1;  // �����ͷ С�� ǰһ�������β����ɾ�������
			}else {
				pre_end = intervals[i][1];  // �����ͷ ���ڵ��� ǰһ�������β���ͱ��������䡣
			}
		}
		return total;
	}
};

int main() {
	std::vector<std::vector<int>> intervals;
	std::vector<int> in1;
	std::vector<int> in2;
	std::vector<int> in3;

	in1.push_back(1);  // [1,3]
	in1.push_back(3);

	in2.push_back(1);  // [1,2]
	in2.push_back(2);

	in3.push_back(2);  // [2,4]
	in3.push_back(4);



	intervals.push_back(in1);
	intervals.push_back(in2);
	intervals.push_back(in3);

	Solution solve;
	int res = solve.eraseOverlapIntervals(intervals);
	printf("res = %d\n", res);

	system("pause");
	return 0;
}
