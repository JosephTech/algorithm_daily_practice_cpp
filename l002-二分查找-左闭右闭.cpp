#include <iostream>  // pause
#include <vector>  // std::vector
using namespace std;

class Solution {
public:
	int binSearch(vector<int> &nums, int target) {
		int l = 0, r = nums.size() - 1;  // ����ұ�
		while (l <= r) {  // ����Ϸ�
			int mid = l + (r - l) / 2;
			if (target == nums[mid])
				return mid;
			else if (target < nums[mid])
				r = mid - 1;
			else
				l = mid + 1;
		}
		return -1;  // size==0����return -1��
	}
};


int main() {
	vector<int> nums = { 2,3,4,5,6 };
	Solution solve;  // ʵ����
	int index = solve.binSearch(nums, 6);
	printf("%d\n",index);

	system("pause");
	return 0;
}