/*
����һ�����飬
���ҵ�������λ������
��û�ҵ������ز���λ�ã�
*/
#include <iostream>  // pause
#include <vector>  // std::vector

class Solution {
public:
	int binSearch(std::vector<int> &nums, int target) {  // ����һ������nums�����������Ԫ��target
		int begin = 0;
		int end = nums.size() - 1;  // �Ҷ˵�
		int index = -1;  // λ������
		while (index == -1) {
			int mid = begin + (end - begin) / 2;
			if (target == nums[mid]) {
				index = mid;   // indexֵ�ı䣬whileѭ�����������Բ���break
			}
			else if (target < nums[mid]) {
				if (mid == 0 || nums[mid-1] < target) {
					index = mid;  // ���ҷ�
				}
				end = mid - 1;
			}
			else if (target > nums[mid]) {
				if (mid == nums.size() - 1 || target < nums[mid + 1]) {
					index = mid + 1;  // ���ҷ�
				}
				begin = mid + 1;
			}
		}
		return index;
	}
};

int main() {
	std::vector<int> nums = {-1, 2, 5, 20, 90, 100, 207, 800};
	std::vector<int> targets = { -1, 2, 5, 20, 90, 100, 207, 800, -2, 3, 14, 80, 95,150,300, 900};
	Solution solve;  // ʵ����
	for (int i = 0; i < targets.size(); i++) {
		int res = solve.binSearch(nums, targets[i]);
		printf("%d\n", res);
	}

	system("pause");
	return 0;
}