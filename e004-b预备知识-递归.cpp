/*
��Ŀ��
	��������nums = [1, 2, 3]  (ʹ��vector�洢)
	ʹ�õݹ飬���Ӽ�[1]  [1,2]   [1,2,3] ��ӵ�����result�� ��ʹ��vector�洢��
*/

#include <iostream> //pause��
#include <vector>

void generate(int i, std::vector<int> &nums,
	std::vector<int> &item, std::vector<std::vector<int>> &result) { // ���÷�ʽ���룬ֱ�Ӳ���ԭʼ���ݡ� ���Է���ֵ����void
	
	if (i >= nums.size()) { //�ݹ��������
		return;
	}
	item.push_back(nums[i]);
	result.push_back(item);
	generate(i+1, nums, item, result);

}

int main() {
	std::vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);

	std::vector<int> item; //�յ�
	std::vector<std::vector<int>> result; //�յ�
	int i = 0;
	generate(i, nums, item, result); //�ݹ����

	//��ӡ
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			printf("[%d]", result[i][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}