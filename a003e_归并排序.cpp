/*
�鲢����

�ο����ϣ�
	�鲢����C++ʵ��
	https://zhuanlan.zhihu.com/p/74820690
*/

#include <iostream>  // pause, cout
#include <vector>

void merge_sort(std::vector<int> &nums, int l, int r, std::vector<int> &temp) {  
	// temp����������ڴ�ռ䣬��Ž����  lָ��������������ʼλ�ã� rָ����һ��������������ʼλ�á�
	if (l + 1 >= r) {  // ��ָ��ָ����
		return;
	}
	// ����
	int mid = l + (r - l) / 2;  // ��Ϊl����������㣬l��Ϊ0�� midΪ�������յ�
	merge_sort(nums, l, mid, temp);  // ���һ��
	merge_sort(nums, mid, r, temp);
	// ����
	int p = l, q = mid, i = l;  // pָ���l��mid-1 �ƶ���  q��mid��r���ƶ��� i��temp��ָ�룬��l��ʼ�ƶ�
	while (p < mid && q < r) {  // �������У���һ���������ˣ��ͽ���
		if (nums[p] < nums[q]) {  // nums[p]С���Ͱ�nums[p]�ŵ�temp�С� <���ı�������ֵ����λ��
			temp[i] = nums[p]; // ˭С��˭�ŵ�temp
			i++;
			p++;
		}
		else {
			temp[i] = nums[q];  // nums[q]���ڵ��ڣ� ��ȡnums[q] 
			i++;
			q++;
		}

	}
	// ���p=mid,�󲿷ֱ�������
	// ���q=r���ұ߲��ֱ�������
	//ʣ˭��˭�����ŵ�temp��
	if (p < mid) {
		while (p < mid) {
			temp[i] = nums[p];
			i++;
			p++;
		}
	}
	if (q < r) {
		while (q < r) {
			temp[i] = nums[q];
			i++;
			q++;
		}
	}
	for (i = l; i < r; i++) {
		nums[i] = temp[i];  // temp���� �����ŵ� nums��
	}
}

int main() {
	std::vector<int> nums = {9, 1, 8, 5, 7, 2, 6, 3, 4,};
	int l = 0;
	int r = nums.size();
	std::vector<int> temp(10,0);  // 10��0
	merge_sort(nums, l, r, temp);

	for (int i = 0; i < nums.size(); i++) {
		printf("%d ", nums[i]);
	}

	system("pause");
	return 0;
}