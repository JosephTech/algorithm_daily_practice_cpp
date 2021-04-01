/*
��֪һ�������������ظ�Ԫ�أ�����������������ɵ������Ӽ���
��������ظ����Ӽ���

	���磺nums[] = [2,1,2,2]
	���Ϊ��[[], [2], [1,2], [1,2,2], [1,2,2,2], [2],[2,2],[2,2,2]]

	ע�⣺��������ظ��ļ���

������Ҫȥ���ظ��Ľ�ϣ�����[1,2,2]��[2,1,2]
*/
/*
˼·��
	�ȶ�nums[] = [2,1,2,2]����
	�õ�[1,2,2,2]

	��ʹ�û��ݷ��������Ӽ�
*/

#include <vector>
#include <algorithm>
#include <set>

class Solution {
public:
	std::vector<std::vector<int>> subSet(std::vector<int> &nums) { //�����ã����⿽������
		std::vector<int> item; // ���ϣ���ߴ洢int
		std::vector<std::vector<int>> result; //result��߷ŵ���һ�������ϣ����ظ��ļ��ϣ�
		std::sort(nums.begin(), nums.end()); //����֮��Ͳ������1 2 2 ��2 1 2�ظ���
		std::set<std::vector<int>> res_set; // ȥ��ʹ�õļ���

		result.push_back(item); //�ռ���ӵ�result��
		//�ݹ����
		generate(0, nums, item, result, res_set);
		return result;
	}
private:
	void generate(int i, 
					std::vector<int> &nums, 
					std::vector<int> &item,
					std::vector<std::vector<int>> &result,
					std::set<std::vector<int>> &res_set) {   //�ݹ����
		//�ݹ��������
		if (i >= nums.size()) {
			return;
		}

		item.push_back(nums[i]);
		if (res_set.find(item) == res_set.end()) { // ��set�ж��Ƿ��ظ���������ظ�����ӵ�result��
			result.push_back(item);
			res_set.insert(item); //������insert����
		}
		generate(i + 1, nums, item, result, res_set); //Ҫ
		//���ݷ�
		item.pop_back();
		generate(i + 1, nums, item, result, res_set); //��Ҫ
	}
};


int main() {
	std::vector<int> nums;
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(2);

	//ʵ����������
	Solution solve;
	std::vector<std::vector<int>> result = solve.subSet(nums);

	// ��ӡ
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			printf("[%d]",result[i][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}