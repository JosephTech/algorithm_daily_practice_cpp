/*
merge_sort�鲢����ͬʱ��˳������
*/
/*
��Ŀ��
	��Ԫ�غ���ȸ�Ԫ��С��Ԫ�صĸ���
*/

#include <iostream>
#include <vector>

class Solution {
public:
	std::vector<int> countSmaller(std::vector<int> &nums) { //�������ã�����һ��vector��ÿ��λ�ô洢��iλ��  ��С��nums[i]�ĸ���
		std::vector<std::pair<int, int>> vec; //���ڴ��pair�� pair��first��nums[i]��  pair��second��i
		std::vector<int> count; //�洢nums[i]��С��nums[i]�ĸ����� Ҳ�����շ��ؽ��
		//���
		for (int i = 0; i < nums.size(); i++) {
			vec.push_back(std::make_pair(nums[i], i)); //i��¼��ԭʼλ��
			count.push_back(0); //��ʼ����ÿ��λ�ü�¼Ϊ0��
		}
		merge_sort(vec, count); //�ݹ����
		return count;
	}

private:
	void merge_sort_two_vec(std::vector<std::pair<int, int>> &sub_vec1,
							std::vector<std::pair<int, int>> &sub_vec2,
							std::vector<std::pair<int, int>> &vec,
							std::vector<int> &count) { //��������
		int i = 0; //sub_vec1�е�i��Ԫ��
		int j = 0; // sub_vec2�е�j��Ԫ��
		while (i < sub_vec1.size() && j < sub_vec2.size()) { 
			// ˭С����˭�ŵ�vec�С���ͬ���Ͱ�sub_set1�ŵ�vec��
			// �Լ�����Ƶ��
			if (sub_vec1[i].first <= sub_vec2[j].first ){
				vec.push_back(sub_vec1[i]); // ��˳��ŵ�vec��
				count[sub_vec1[i].second] += j; // ����count���Լ�����Ƶ���ȥ
				// ע�⣺count�����ڼ�¼ԭʼ�������� ��nums[i]����м���small����
				// ֻ�з�sub_set1ʱ�򣬲Ÿ���count
				// ��sub_set2ʱ���Ǹ�j������
				i++;
			}
			else {
				vec.push_back(sub_vec2[j]);
				j++;
			}
		}
		//˭ʣ ��˭
		for (; i < sub_vec1.size(); i++) { // ע�⣺�����Ѿ�i++���ˣ���Ҫ�ٻ������㣬�±�i++��
			count[sub_vec1[i].second] += j;
			vec.push_back(sub_vec1[i]);
		}
		for (; j < sub_vec2.size(); j++) {
			vec.push_back(sub_vec2[j]);
		}
	}

	void merge_sort(std::vector<std::pair<int, int>> &vec,
					std::vector<int> &count) { //��������
		if (vec.size() < 2) { //�ݹ���������� ���𲻳ɵ�ʱ�򣬷�����һ��ݹ�
			return;
		}
		//�𿪣�����
		int mid = vec.size() / 2;
		std::vector<std::pair<int, int>> sub_vec1;
		std::vector<std::pair<int, int>> sub_vec2;
		for (int i = 0; i < mid; i++) { //ǰһ��
			sub_vec1.push_back(vec[i]);
		}
		for (int i = mid; i < vec.size(); i++) {
			sub_vec2.push_back(vec[i]);
		}
		//�ݹ����
		merge_sort(sub_vec1, count); //����ǰһ�롣 ֮��sub_set1��������
		merge_sort(sub_vec2, count); //�����һ�롣 ֮��sub_set2��������
		vec.clear(); //���vec���������ϲ���vec�ͱ��������ġ�   
		// ���οռ䣺 ��ע�⣺�˴���vec�����ǵݹ鴫��merge_sort��sub_set.��
		merge_sort_two_vec(sub_vec1, sub_vec2, vec, count); //�ϲ�
	}
};

int main() {
	int test[] = {5, -7, 9, 1, 3, 5, -2, 1};
	std::vector<int> nums;
	for (int i = 0; i < 8; i++) {
		nums.push_back(test[i]);
	}
	//ʵ���������ú���
	Solution solve;
	std::vector<int> result = solve.countSmaller(nums);
	
	//��ӡ
	for (int i = 0; i < result.size(); i++) {
		printf("[%d]", result[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}