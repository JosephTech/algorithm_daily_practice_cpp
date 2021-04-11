/*
lc198 ��ҽ���
*/
/*
��Ŀ��
	һ��ֱ������n�����ݣ�
	ÿ�������в�ͬ�����ĲƱ���
	����������������ݵ�ȡ�Ʊ����ͻᴥ��������
	���������Ե�ȡ���ٲƱ������ܴ���������
*/
/*
��n=6��ÿ�����ݲƱ����£�
[5, 2, 6, 3, 1, 7]

�����Ե�ȡ 5+6+7 = 18���Ʊ�
*/
/*
˼·1��
	���������������Ӽ���ÿ�����䶼��ѡ����ѡ ���ֿ��ܣ�ʱ�临�Ӷ���O(2^n)
	ѡ���ܺ������Ӽ�

	����ö�٣���1�����俪ʼ���г�����
*/
/*
˼·2��
̰���㷨
	������������ͬʱ��ÿ��ѡ��Ʊ����ķ���
���˷��������У��������ӾͲ����ˣ�
*/
/*
˼·3��
��̬�滮����dp��
ԭ�����������⡢״̬���߽�״̬��״̬ת�Ʒ���
*/
/*
dp״̬ת�Ʒ��̣�
dp[i] = max(dp[i-1], dp[i-2]+nums[i])
*/

#include <iostream>  // pause
#include <vector>  // std::vector
#include <algorithm>

class Solution {
public:
	int houseRobber(std::vector<int> &nums) {
		if (nums.size() == 0)
			return 0;
		if (nums.size() == 1)
			return nums[0];
		std::vector<int> dp(nums.size(), 0);  // ��ô���0
		dp[0] = nums[0];
		dp[1] = std::max(nums[0], nums[1]);  // ǰ������
		for (int i = 2; i < nums.size(); i++) {
			dp[i] = std::max(dp[i-2]+nums[i], dp[i - 1]);
		}
		return dp[nums.size() - 1];
	}
};


int main() {
	std::vector<int> nums = { 5, 2, 6, 3, 1, 7 };

	Solution solve;
	int res = solve.houseRobber(nums);
	printf("%d\n", res);

	system("pause");
	return 0;
}
