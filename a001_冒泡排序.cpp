#include <iostream>  // pause, cout
#include <vector>  // std::vector

class Solution {
public:
	void bubble(std::vector<int> &nums) {  //�������ã� ��ֹ��������
		int length = nums.size();
		for (int i = 0; i < length - 1; i++) {  // ѭ��n-1�֣�ÿ��ðһ������
			for (int j = 1; j < length - i; j++) {  // ��һ�ֱȽ�(����)n-1�Σ� �ڶ��ֱȽ�n-2��
				if (nums[j - 1] > nums[j]) {  // ǰ�Ⱥ�󣬽���
					int temp = nums[j - 1];
					nums[j - 1] = nums[j];
					nums[j] = temp;
				}
			}
		}
	}
};

int main() {
	std::vector<int> nums = { 7, 8, 1, 9, 5, 4, 6, 2, 3, };
	Solution solve;
	solve.bubble(nums);
	for (int i = 0; i < nums.size(); i++) {
		printf("%d ", nums[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}