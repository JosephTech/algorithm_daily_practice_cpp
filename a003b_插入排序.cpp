/*
��������
	ȡһ��δ���������
	�Ӻ���ǰ���������򲿷֣�����Ƚϣ�

	��С�� ����
*/
#include <iostream>  // pause
#include <vector>  // std::vector

void inseration_sort(std::vector<int> &nums) {
	int n = nums.size();
	for (int i = 0; i < n; i++) {  // ��0~n�� ��n�֡� ÿ�ֲ���һ������
		for (int j = i; j > 0 && nums[j - 1] > nums[j]; j--) {  // ��nums[i], ǰ>�󣬾Ͳ��Ͻ����� ��˼���ǰ�nums[i]���뵽ǰ���������������
			int temp = nums[j - 1];
			nums[j - 1] = nums[j];
			nums[j] = temp;
		}
	}
}


int main() {
	std::vector<int> nums = { 1, 3, 5, 7, 2, 6, 4, 8, 9, 2, 8 };
	inseration_sort(nums);  //��������

	for (int i = 0; i < nums.size(); i++) {
		printf("%d ", nums[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}