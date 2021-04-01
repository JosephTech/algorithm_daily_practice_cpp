/*
��֪һ�������������ظ�Ԫ�أ�����������������ɵ������Ӽ��У�
�Ӽ��и���Ԫ�غ�Ϊ����target���Ӽ�����������ظ����Ӽ���

���磺
	nums[] = [10, 1, 2, 7, 6, 1, 5], target = 8
	���Ϊ��
	[[1,7], [1,2,5], [2,6], [1,1,6]]
*/
/*
��һ�ַ�����������С������ͨ��������leetcode�ᱨ��ʱ����Ϊ���ݷ���λ���㷨�ĸ��Ӷ���2^n��
��n�ܴ�ʱ�������㲻��

����  ��Ҫʹ�ü�֦��

���磺
	nums[] = [10, 1, 2, 7, 6, 1, 5]
	target= 8;

	ȥ��10���������������һ���ʱ�临�Ӷȣ�����ԭ����O(2^n)
	���ڱ��O(2^(n-1))

	���⣬��>8���ͼ�֦���ɽ�һ�������㷨��ʱ�临�Ӷ�
*/

#include <iostream> //pause�õ�
#include <set> //ȥ�� �ظ��Ӽ��õ�
#include <algorithm> //sort�õġ� sort���Ӽ���Ԫ���Ǵ�С�����
#include <vector> // ���Ķ��ã��漯���õ�

class Solution {
public:
	std::vector<std::vector<int>> combinationSum2(int target, std::vector<int> &candidates) { //����target������
		std::vector<int> item; // ĳ���Ӽ�
		std::vector<std::vector<int>> result; //����������׼���
		std::set<std::vector<int>> res_set; //ȥ���ظ������õ�
		std::sort(candidates.begin(), candidates.end()); //��С�������� ��������Ӽ����Ӽ�Ԫ��Ҳ�Ǵ�С����ġ� ����ͬʱ����[1, 7] �� [7,1] 
		// result.push_back(item); //���ſռ�����Ϊ�ռ��������=target
		//�ݹ����
		generate(0, candidates,item, result, res_set, 0, target); //��һ��0��i��  �ڶ���0��sum
		return result; //���ؽ��
	}

private:
	void generate(int i,
					std::vector<int> &candidates,
					std::vector<int> &item,
					std::vector<std::vector<int>> &result,
					std::set<std::vector<int>> &res_set,
					int sum,
					int target) { //i sum targetһ������ֱ�Ӵ�ֵ������
		if (i >= candidates.size() || sum > target) { //��֦ + �ݹ������ ���ڵ�������Ϊi��0��ʼ������
			return;
		}
		sum += candidates[i]; //�ݹ� ���
		item.push_back(candidates[i]); //�ŵ�item������
		if (sum == target && res_set.find(item) == res_set.end() ) { //�� ��==target������res_set(û�ҵ�)���ظ��� �ŵ�result�У��ŵ�res_set��
			res_set.insert(item); // set��insert
			result.push_back(item); //�ŵ����ս��result��
		}
		generate(i + 1, candidates, item, result, res_set, sum, target); //�ݹ����
		//����
		sum -= candidates[i];
		item.pop_back();
		generate(i + 1, candidates, item, result, res_set, sum, target); //�ݹ����
	}
};

int main() {
	std::vector<int> nums;
	nums.push_back(10);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(6);
	nums.push_back(1);
	nums.push_back(5);

	//ʵ���������ú���
	Solution solve;
	std::vector<std::vector<int>> result = solve.combinationSum2(8, nums);

	// ��ӡresult
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			printf("[%d]", result[i][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}