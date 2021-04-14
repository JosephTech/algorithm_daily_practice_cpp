/*
��Ŀ��
�ҵ�����true,
���򷵻�false
whileѭ����
*/

#include <iostream>  // pause
#include <vector>

class Solution {
public:
	bool binSearch(std::vector<int> &nums, int target) {  // ��������nums�����������Ԫ��target
		int begin = 0;
		int end = nums.size()-1;  // ����ұ�
		while (begin <= end) {  // ����ұգ��Ϸ�
			int mid = begin + (end - begin) / 2;
			if (target == nums[mid]) {
				return true;
			}
			else if (target <= nums[mid]) {
				end = mid - 1;
			}
			else if (target >= nums[mid]) {
				begin = mid + 1;
			}
		}
		return false;
	}
};

int main() {
	std::vector<int> nums = { -1, 2, 5, 20, 90, 100, 207, 800 };
	std::vector<int> targets = { -1, 2, 5, 20, 90, 100, 207, 800, -2, 3, 15, 80, 95, 150, 300 };
	Solution solve;  // ʵ����
	for (int i = 0; i < targets.size(); i++) {
		int res = solve.binSearch(nums, targets[i]);
		printf("%d\n", res);
	}

	system("pause");
	return 0;
}