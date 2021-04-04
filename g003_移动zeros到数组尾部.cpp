/*
leetcode 283 move zeros

��Ŀ��
	����һ������nums��дһ��������������������0Ų�������ĩβ����ά����������
	��0Ԫ�ص����λ��

������
	nums = [0, 1, 0, 3, 12]
	�������к󣬽��Ϊ[1, 3, 12, 0, 0]
*/
/*
˼·1��
	ɨ�� �õ����з�0Ԫ�أ�
	�Ż�ȥ����ʣ��λ�ò�0
*/


#include <iostream>
#include <vector>

class Solution {
public:
	void moveZeros(std::vector<int> &nums) {
		std::vector<int> nonZeroElements;  // ��ŷ���Ԫ��
		for (int i = 0; i < nums.size(); i++) {  // ����Ԫ�أ��Ž�nonZeroElements
			if (nums[i]) {  // ����0
				nonZeroElements.push_back(nums[i]);
			}
		}
		for (int i = 0; i < nonZeroElements.size(); i++){  // �Ż�ȥ
			nums[i] = nonZeroElements[i];
		}
		for (int i = nonZeroElements.size(); i < nums.size(); i++) {
			nums[i] = 0;
		}
	}
};

int main() {
	int arr[] = { 0, 1, 0, 3, 12 };
	std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));  // ������λָ��

	Solution solve;
	solve.moveZeros(vec);  // ��������

	for (int i = 0; i < vec.size(); i++) {
		printf("%d ", vec[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}