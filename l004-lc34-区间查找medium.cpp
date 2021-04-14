/*
��Ŀ��
���������飨���ظ�Ԫ�أ���
���ҵ�target������ ���Ҷ˵��±� [��˵㣬�Ҷ˵�]
��δ�ҵ�target, ���� [-1, -1]
*/
#include <iostream>  // pause
#include <vector>

class Solution {
public:
	std::vector<int> searchRange(std::vector<int> &nums, int target) {
		std::vector<int> result;
		int left = binSearchLeft(nums, target);
		int right = binSearchRight(nums, target);
		result.push_back(left);
		result.push_back(right);
		return result;
	}
private:
	int binSearchLeft(std::vector<int> &nums, int target) {
		int index = -1;  // ������˵�
		int begin = 0;
		int end = nums.size()-1;  // ����ұ�
		while (begin <= end) {
			int mid = begin + (end - begin) / 2;
			if (nums[mid] == target ) {
				if (mid == 0 || nums[mid - 1] < nums[mid]) {  // �ҵ���˵�
					index = mid;
					break;
				}
				else {
					end = mid-1;  // �������� ���һ��
				}
			}
			else if (target < nums[mid]) {
				end = mid - 1;  // �������� ���һ��
			}
			else if (target > nums[mid]) {
				begin = mid + 1; // �������� �ұ�һ��
			}
		}
		return index;
	}

	int binSearchRight(std::vector<int> &nums, int target) {
		int index = -1;
		int begin = 0;
		int end = nums.size() - 1;  // ����ұ�
		while (begin <= end) {
			int mid = begin + (end - begin) / 2;
			if (nums[mid] == target) {
				if (mid == nums.size()-1 || nums[mid+1] > nums[mid]) {  // �Ҷ˵㣬�����ұߴ�
					index = mid;
					break;
				}
				else {  // �������� �ұ�һ��  (��Ϊ�Ҷ˵� �����ұ�)
					begin = mid + 1;
				}
			}
			else if (target < nums[mid]) {
				end = mid - 1;  // �����������һ��
			}
			else if(target > nums[mid]){
				begin = mid + 1;
			}
		}
		return index;
	}
};

int main() {
	std::vector<int> nums = { 5, 7, 7, 8, 8, 8, 8, 10 };
	std::vector<int> targets = { 5, 7, 7, 8, 8, 8, 8, 10, 0, -1, 6, 9 };
	Solution solve;
	for (int i = 0; i < targets.size(); i++) {
		std::vector<int> res = solve.searchRange(nums, targets[i]);
		for (int j = 0; j < res.size(); j++) {
			printf("%d ", res[j]);
		}
		printf("\n");
	}
	
	system("pause");
	return 0;
}