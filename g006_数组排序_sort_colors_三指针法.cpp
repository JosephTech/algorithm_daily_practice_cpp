/*
����һ�������� �������� ɨ�������ߣ�
��һ�� ɨ��ÿ��Ԫ��
�ڶ��� �Ż�ȥ��

˼·2��
	ֻɨ��һ�飬��·����
	����ֳ����ݣ� С��v�� ����v�� ����v

	֮��� <v �� >v �ĵط� ���ż���
*/
#include <iostream>  // pause
#include <vector>  // std::vector
#include <cassert>

class Solution {
public:
	void sort_colors(std::vector<int> &nums) {
		int zero = -1, two = nums.size();  // [0, zero]��0����ұա�  [two, n-1]��2,����ұ�
		// ע�⣺��Ϊ����[5, 5]�ǺϷ���
		for (int i = 0; i < two;) {  //  [zero+1, two��1]�� ע�⣬������i < two�� ע�⣺���ﲻ��i++����Ϊiָ����ʱ���ǲ�����
			if (nums[i] == 1)
				i++;  // [zero+1, two-n]��1
			else if (nums[i] == 2)
				std::swap(nums[i], nums[--two]);  // twoָ�����ƣ� �ٽ�����i���õ���
			else {
				assert( nums[i] == 0);  // ���ԣ����Ͻ���
				zero++;
				std::swap(nums[zero], nums[i]); //����
				i++;  // zeroָ�����ƣ������� iָ����һ���� �����п���д��һ��
				// ��Ϊ[zero+1, i-1]��������1���� ����Ҫi++
			}
		}
	}
};


int main() {
	std::vector<int> nums = { 2, 1, 2, 2, 0, 2, 1, 2, 1, 0, 2, 0, 1, 0 };
	Solution solve;
	solve.sort_colors(nums);  // ��������

	for (int i = 0; i < nums.size(); i++)
		printf("%d ", nums[i]);
	printf("\n");

	system("pause");
	return 0;
}


