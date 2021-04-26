#include <iostream>  // pause
#include <vector>  // std::vector
#include <unordered_set>  // ��ϣ��  ʵ�ֵ�set
using namespace std;

class Solution {
public:
	bool containDuplicate(vector<int>& nums, int k) {  // k����󴰿�
		unordered_set<int> record_set;
		for (int i = 0; i < nums.size(); i++) {
			if (record_set.find(nums[i]) != record_set.end())  // �ҵ��ˣ�return true, ������ӵ�set��
				return true;
			else
				record_set.insert(nums[i]);
			if (record_set.size() == k + 1)   // ����ұգ�����k+1ʱ��ȥ����������ߵģ�Ԥ��һ����������һ��Ԫ��
				record_set.erase(nums[i-k]);  // ��i=9�� k=9�������nums[0]			
		}
		return false;  // ����������k�����Ҷ�Ҳ���������������
	}
};


int main() {
	vector<int> nums = {3, 4, 5, 6, 7, 8, 9, 5 };
	Solution solve;  // ʵ����
	printf("%d\n", solve.containDuplicate(nums, 6));

	system("pause");
	return 0;
}