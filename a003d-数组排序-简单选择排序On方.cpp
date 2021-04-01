/*
ѡ�������㷨����ѡ������
ʱ�临�Ӷ�O(n^2),   �ռ临�Ӷ�O(1)
*/
/*
�㷨˼·��
��������ѡ��һ����󣨻���С����һ��Ԫ�أ���������е���ʼλ�á�

��һ�Σ����±�Ϊ0��Ԫ�� �ͺ�ߵ�����Ԫ�رȽϣ��ҳ���С������󣬷����±�Ϊ0��λ��

�ڶ��Σ����±�Ϊ1�Ŀ�ʼ�Ƚϣ���ѯʣ�µ���������Сֵ�������±�Ϊ1��λ�á�

...
ֱ��ȫ������

�ο���https://zhuanlan.zhihu.com/p/76799311
*/
#include <iostream>
#include <vector> //װ����

void select_sort(std::vector<int> &nums) { //�������������
	for (int i = 0; i < nums.size(); i++) {
		int min_index = i; //ȡ��i��Ϊ��С
		for (int j = i+1; j < nums.size(); j++) { //����Ƚϵ�i+1�����С�˾ͻ�
			if (nums[j] < nums[min_index]) {
				min_index = j;
			}
		}
		if (min_index != i){ //��С���ͽ������ߵ�ֵ
			int tmp = nums[i];
			nums[i] = nums[min_index];
			nums[min_index] = tmp;
		}
	}
} //���÷��أ���Ϊ�����ã�ֱ�Ӹĵ�ԭʼ����

int main() {
	std::vector<int> nums;
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(88);
	nums.push_back(6);
	nums.push_back(3);
	nums.push_back(99);

	select_sort(nums); //���ú���

	//��ӡ
	for (int i = 0; i < nums.size(); i++) {
		printf("%d\n",nums[i]);
	}

	system("pause");
	return 0;
}