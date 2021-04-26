/*
��Ŀ��
����nums����

���Ƿ����i�� j�� ʹ��i��j����С�ڵ���k��nums[i]��nums[j]�ľ���С�ڵ���t
*/
/*
˼·��
i,j���룬�϶��û�������

��[i, j]���ŵ� set��

ʵ�֣���set.size()<=k+1,���ܱ�֤��������

�ڻ����У�set.lower_bound(nums[i] - t)���� ��<=nums[i]+t�����ܱ�֤nums[i]��nums[j]�ľ�������
*/
#include <iostream>  // pause
#include <vector>  // std::vector
#include <set>  // ����Ҫ��lower_bound()
using namespace std;

class Solution {
public:
	bool containDuplicates(vector<int> &nums, int t, int k) {  // num[i]��nums[j]����С�ڵ���t.  i��j����С�ڵ���k�� �򷵻�ture
		set<int> record_set;  // ��¼ָ��i��i���Զ���nums[i]������Ҫ����insert��record_set�С� ����record_set.size()<k+1
		for (int i = 0; i < nums.size(); i++) {
			if (record_set.lower_bound(nums[i] - t) != record_set.end() && *record_set.lower_bound(nums[i] - t) <= nums[i] + t)
				return true;
			record_set.insert(nums[i]);
			if (record_set.size() == k + 1)
				record_set.erase(nums[i - k]);  // ɾ����i����Ϊk��Ԫ�أ���i=9��k=9����ɾ��nums[0]�� ��һ��λ�ã�������һ�ֲ���
		}
		return false;
	}
};


int main() {
	vector<int> nums = { 10,20,30,40,55,60,90,56 };
	Solution solve; // ʵ����
	printf("res = %d\n", solve.containDuplicates(nums, 1, 3) );  // nums[i]��nums[j]����С�ڵ���1�� i��j����С�ڵ���3


	system("pause");
	return 0;
}