/*
��������
	�����е������㷨���ٶ����������㷨

�㷨˼·��
	ѡһ�����ᣨ�������ұߵģ��� 
		����߿�ʼ��ѡһ����������ģ�
		���ұ߿�ʼ��ѡһ��С������ģ�������
		ͨ��lָ���rָ�룬����l++, r++����ν����� while l<rʱ��

		�����ỻ���м�

	�ݹ�ʵ��
*/
#include <iostream>  // pause
#include <vector>  // std::vector

class Solution {
public:
	void quick_sort(std::vector<int> &nums, int l, int r) {  // ��ָ�롢��ָ�롢����
		if (l >= r)
			return; // �ݹ����������ά��������[l, r]�� ��Ȼl==r�ǺϷ��ģ�����û��Ҫ������Ҳ�������� �����������
		int i = l, j = r;  // i��j�ֱ�����ҿ�ʼ ���� ά��[l, r] ����ұա� r������
		int pivot = nums[r]; // ѡ����Ϊ���ᡣ  ��Ϊ������ұգ�����ѡnums[r] 
		// ��<����ģ�������������
		// >����ģ�����������ұ�
		while (i < j){
			while (nums[i] < pivot && i < j)  // ��С�����ᣬ�������ƶ�i��Ϊ��iָ����������
				i++;
			while (nums[j] >= pivot && i < j)  // �����ڵ������ᣬ������j��  Ϊ��jָ��С�������
				j--;
			if (i < j)
				std::swap(nums[i], nums[j]);  // �� ָ��i<j�� �򽻻�
		}  // ��i < jʱ�򣬾Ͳ��Ͻ���
		std::swap(nums[r], nums[j]);  // �������ᵽ �м�  ����������ֵ������ָ�룩�� ��[j, r]��>=pivot��

		quick_sort(nums, l, j - 1);  // С������� �ݹ顣 ά��[l, r]����ұ�
		quick_sort(nums, j + 1, r);  // ���ڵ�������� �ݹ顣 ά��[l, r]����ұ�
		// ע��j���Ѿ�����õģ����Բ����ٶ���
	}
};


int main() {
	std::vector<int> nums = { 8, 1, 9, 2, 6, 0, 7, 3, 5, 4 };
	Solution solve;

	int r = nums.size()-1;  // ά������ұ�[l, r]
	solve.quick_sort(nums, 0, r);
	
	for (int i = 0; i < nums.size(); i++) {
		printf("%d ", nums[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}