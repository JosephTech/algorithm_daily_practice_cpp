/*
���ݷ� �ֳ� ��̽��
	��̽����ĳһ��ʱ������ԭ��ѡ��ﲻ��Ŀ�꣬���˻�һ������ѡ��
	�����߲�ͨ���˻����ߵļ���Ϊ���ݷ�

���磺
	�����޻�ͼ
*/ 
/*
��1�� ���Ӽ�
	��֪һ�������������ظ�Ԫ�أ�����������������ɵ������Ӽ���
	����в����� �ظ����Ӽ���

���磺
	nums[] = [1,2,3]
	���Ϊ��
		[[], [1], [2], [3], [1,2], [1,3], [2,3], [1,2,3]]
*/
/*
���û��ݷ������Ӽ���������ÿ��Ԫ�أ�������̽ ����Ͳ����뼯�� ������ѡ��
*/
/*
���߼�����⣺
	ÿ�ε��õݹ麯��generate()������ѡ�����nums[i] ���߲�����nums[i]

����i=1����
	��item = [1],i=1ʱ��
	��nums[1]��ӵ�item�б��[1,2]
	[1,2]push_back��result�У�
		i=2,�Ų���nums[2]
	������item���[1]
		i=2,�Ų���nums[2]=3;   // �����[1],[1,3]������[1]�Ѿ�push_back���ˣ�����ֻ�õ���������push_back

������һ�ε��ã�
	��item = [1,2],  i=2ʱ��
		��nums[2]��ӵ�item�б��[1,2,3]
		[1,2,3]push_back��result��
			i=3,  ��ʱi >= nums.size()����return
		������item���[1,2]
			i=3, ��ʱi>=nums.size()����return

*/
#include <iostream>
#include <vector>

class Solution {
public: // ����ߵ�������subset()
	std::vector<std::vector<int>> subSet(std::vector<int> &nums) {
		std::vector<int> item; // item���Ӽ��� �������
		std::vector<std::vector<int>> result; // ����Ӽ�
		result.push_back(item); //�ռ�
		generate(0, nums, item, result); //��һ����ã�����i=0��Ҫ��Ҫnums[0]
		return result;

	}
private: //�ݹ麯���������
	void generate(int i,
		std::vector<int> &nums,
		std::vector<int> &item,
		std::vector<std::vector<int>> &result) { // ���� �����׼���
		if (i >= nums.size()) { //�ݹ����
			return;
		}
		// ��nums[i]
		item.push_back(nums[i]); // item�Ǹ����ϣ���߷ŵ��� ��������
		result.push_back(item); //result�ŵ��Ǽ���
		generate(i + 1, nums, item, result);
		// ��nums[i]
		item.pop_back();
		generate(i + 1, nums, item, result);
	}
};

int main() {
	std::vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);

	Solution solve;
	std::vector<std::vector<int>> result = solve.subSet(nums);

	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			printf("[%d]", result[i][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}