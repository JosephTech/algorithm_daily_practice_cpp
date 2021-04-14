/*
��Ŀ��	
��ת���飬
����ĳ��Ԫ��,
�����֣��򷵻��±�
��δ���֣� �򷵻�-1
*/
#include<iostream>  // pause
#include<vector>  // std::vector

class Solution {
public:
	int search(std::vector<int> &nums, int target) {  // nums����ת���飬target�Ǵ�����Ԫ��
		int begin = 0;
		int end = nums.size() - 1;  // ����ұ�
		int index = -1;
		while (begin <= end) {
			int mid = begin + (end - begin) / 2;
			if (target == nums[mid]) {
				index = mid;
				break; // �ҵ���
			}
			else if (target < nums[mid]) {
				if (nums[mid] < nums[begin]) {
					end = mid - 1;
				}
				else if (nums[begin] <= target) {
					end = mid - 1;
				}
				else if (target < nums[begin] && nums[begin] < nums[mid]) {
					begin = mid + 1;
				}
				else if (nums[begin] == nums[mid]) {
					begin = mid + 1;
				}
			}
			else if (target > nums[mid]) {
				if (nums[mid] > nums[begin]) {
					begin = mid + 1;
				}
				else if (nums[begin] >= target) {
					begin = mid + 1;
				}
				else if (nums[mid] < nums[begin] && nums[begin] < target) {
					end = mid - 1;
				}
				else if (nums[begin] == nums[mid]) {
					begin = mid + 1;
				}
			}
		}
		return index;
	}
};

int main() {
	std::vector<int> nums = {9, 12, 15, 20, 1, 3, 6, 7};
	Solution solve;  // ʵ����
	for (int i = 0; i < 22; i++) {
		printf("%d : %d \n", i, solve.search(nums, i));
	}

	system("pause");
	return 0;
}