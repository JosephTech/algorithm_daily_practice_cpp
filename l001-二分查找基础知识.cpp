/*
��Ŀ��
	�鵽 ����true
	û�鵽 ����false
*/
/*
���磺arr = [-1, 2, 5, 20, 90, 100, 207, 800]
����������target == 2, 200
*/
/*
˼·��
	����target��ô�죿 ����true
	С��target��ô��?  ��ѯǰ��һ��[0,mid-1]
	����target��ô�죿 ��ѯ���һ��[mid+1, arr.size()-1]
*/
#include <iostream>  // pause
#include <vector>  // std::vector

// �ݹ�д��
class Solution {
public:
	bool binSearch(std::vector<int> &nums, int target, int begin, int end) {  // ���������Ԫ��target���������顣����bool��
		if (begin > end)  // ����ұգ�����begin == end�ǺϷ���
			return false;
		int mid = begin + (end - begin) / 2;
		if (target == nums[mid]) {
			return true;
		}
		else if (target < nums[mid]) {
			return binSearch(nums, target, begin, mid-1);
		}
		else if (target > nums[mid]) {
			return binSearch(nums, target, mid+1, end);
		}


	}
};

int main() {
	std::vector<int> nums = {-1, 2, 5, 20, 90, 100, 207, 800};
	Solution solve;  // ʵ����

	std::vector<int> targets = { 0,-1, 2, 3, 5, 7, 20,30, 90, 100, 200, 207,300, 800 };
	
	for (int i = 0; i < targets.size(); i++) {
		int res = solve.binSearch(nums, targets[i], 0, nums.size() - 1);
		printf("%d\n", res);
	}

	system("pause");
	return 0;
}
