/*
��Ŀ��
	��֪һ�������������ظ�Ԫ�أ�����������������ɵ������Ӽ��У�
	�Ӽ��и���Ԫ�غ�Ϊ����target���Ӽ�����������ظ����Ӽ���

	���磺
		nums[] = [10, 1, 2, 7, 6, 1, 5]
	(��Ϊ8)���Ϊ��
		[[1,7],  [1,2,5],  [2,6],  [1,1,6]]
*/

/*
��������
	1��(ʹ�û��ݷ� ���� λ���㷨)����������Ӽ�,��Щ�Ӽ����ظ�����std::set��
	2�������ҵ�Ԫ�غ�Ϊ8���Ӽ�

�������⣺
	�㷨���ӶȾ޸�
	�����¼�����
*/
#include <iostream> // pause�õ�
#include <vector>
#include <set>
#include <algorithm> //sort�õ�

class Solution {
public:
	std::vector<std::vector<int>> combinationSum2(int target, std::vector<int> &nums) { //�������ã���ֹ��������
		std::vector<int> item; // �Ӽ�����ߴ洢��int
		std::vector<std::vector<int>> result; // ������ս������ߴ洢�����Ӽ�
		std::set<std::vector<int>> res_set; //���ϣ���߷ŵ��ǲ��ظ����Ӽ��� ������item����res_set�У�����result��
		// Ϊɶ����set��Ϊ���ս������Ϊ�õ�vector��vector�����
		result.push_back(item); //�ռ� ��ӽ�ȥ
		std::sort(nums.begin(),nums.end()); //��С�������򣬷�ֹһ�����[1,7]��[7,1]������ͬ����
		generate(0, nums, item, result, res_set); //�ݹ����

		// ������result�� �͵���8���Ӽ�
		std::vector<std::vector<int>> target_result;
		for (int i = 0; i < result.size(); i++) {
			int sum = 0;
			for (int j = 0; j < result[i].size(); j++) {
				sum += result[i][j]; //��������Ӽ��ĺ�
			}
			if (sum == target) { //����==target,�Ͱ�����Ӽ��ŵ�target_result��
				target_result.push_back(result[i]);
			}
		}
		return target_result;
	}

private:
	void generate(int i, 
					std::vector<int> &nums,
					std::vector<int> &item, 
					std::vector<std::vector<int>> &result, 
					std::set<std::vector<int>> &res_set) {
		if (i >= nums.size()) { //�ݹ��������
			return;
		}
		item.push_back(nums[i]);
		if (res_set.find(item) == res_set.end()) { //���û�ҵ����ͷŵ�set����ҷŵ����ս����
			res_set.insert(item); 
			result.push_back(item);
		}
		generate(i+1, nums, item, result, res_set);
		item.pop_back(); //���ݷ�
		generate(i+1, nums, item, result, res_set);
	}
};

int main() {
	//���� ����nums
	std::vector<int> nums;
	nums.push_back(10);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(6);
	nums.push_back(1);
	nums.push_back(5);

	// ʵ����������
	Solution solve;
	std::vector<std::vector<int>> target_result = solve.combinationSum2(8, nums);

	//��ӡ
	for (int i = 0; i < target_result.size(); i++) {
		for (int j = 0; j < target_result[i].size(); j++) {
			printf("[%d]", target_result[i][j]);
		}
		printf("\n");
	}



	system("pause");
	return 0;
}

