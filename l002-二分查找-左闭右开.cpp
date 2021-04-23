#include <iostream>  // pause
#include <vector>  // std::vector
using namespace std;

class Solution {
public:
	int binSearch(vector<int> &nums, int target) {  // ��������
		int l = 0, r = nums.size();  // ǰ�պ�
		while (l < r) {  // ǰ�պ󿪣� ��[42,42)�Ƿ�����Ԫ��
			int mid = l + (r - l) / 2;
			if (target == nums[mid])
				return mid;
			else if (target < nums[mid])
				r = mid;  // ����ҿ�
			else
				l = mid + 1;  // ����ҿ�
		}
		return -1;  // nums.size() == 0������-1�� �Ҳ��� ������-1
	}
};

int main() {
	std::vector<int> nums = {3, 4, 55, 88};
	Solution solve;
	printf("res = %d\n", solve.binSearch(nums, 55));

	system("pause");
	return 0;
}