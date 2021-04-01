#include <iostream>  // pause, cout
#include <vector>  // std::vector

class Solution {
public:
	void selectionSort(std::vector<int> &nums) {
		for (int i = 0; i < nums.size(); i++) {
			int min_index = i;  // ������ĩβ����Ϊi
			for (int j = i + 1; j < nums.size(); j++) {  // ����δ���򲿷�
				if (nums[j] < nums[min_index]) {  // ���С�ڣ���¼����
					min_index = j;
				}
			}
			if (min_index != i) {  // ����С�� ��δ���򲿷֣�����
				int temp = nums[i];
				nums[i] = nums[min_index];
				nums[min_index] = temp;
			}
		}
	}
};

int main() {
	std::vector<int> nums = { 9, 1, 8, 5, 7, 2, 6, 3, 4 };

	Solution solve;
	solve.selectionSort(nums);  // ��������

	// ��ӡ
	for (int i = 0; i < nums.size(); i++) {
		printf("%d ", nums[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}