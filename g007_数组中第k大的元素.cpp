/*
�ҳ������е�k���Ԫ��

(ע�⣺�ǵ�k���Ԫ�أ����ǵ�k��Ĳ�ͬԪ��)
����k��Ԫ��ֻ��ά��һ����С�ѣ�

���磺
	����: [3,2,1,5,6,4] �� k = 2
	���: 5

	����: [3,2,3,1,2,4,5,5,6] �� k = 4
	���: 4
*/
/*
˼·��
	ά��һ����С�ѣ����ضѶ�����
*/

#include <queue>  // std::priority_queque
#include <iostream>  // pause
#include <functional>  // std::greater 

class Solution {
public:
	int find_kth_largest(std::vector<int> &nums, int k) {  // ����nums�������ã�����k�� ���ضѶ�
		std::priority_queue <int, std::vector<int>, std::greater<int>> Q;  // ��С�ѣ���С��������
		for (int i = 0; i < nums.size(); i++) {
			if (Q.size() < k)  // ע����<����k=3����size=2ʱ��pushһ���ͳ���
				Q.push(nums[i]);
			else if (nums[i] > Q.top()) { // Q.size() >= k��ʱ��, ��nums[i]�� �͵��ѡ��Ž�ȥ
					Q.pop();
					Q.push(nums[i]);
			}
		}
		return Q.top();
	}
};

int main() {
	std::vector<int> nums = { 3, 2, 1, 5, 6, 4 };

	Solution solve;  // ʵ����
	int res = solve.find_kth_largest(nums, 2);  // �ڶ���
	printf("res = %d\n", res);

	system("pause");
	return 0;
}