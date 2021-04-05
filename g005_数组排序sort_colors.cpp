/*
��Ŀ��
	����һ����n��Ԫ�ص����飬������Ԫ�ص�ȡֵֻ��0��1��2���ֿ��ܡ�
	Ϊ�����������
*/

/*
����˼·��
	ʹ��O(nlogn)�����򷽷�Ҳ�ܽ�����⣬��accepted������û������ȫ������������
*/
/*
���õĽ���˼·��
	��������counting sort
	ͳ��0��1��2�ĸ�����
	����Ӧ������0/1/2����
*/
/*
�ο����ϣ�
	Leetcode 75 ��ɫ���� C++
	https://blog.csdn.net/qq_43387999/article/details/86982438?utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7Edefault-6.control&dist_request_id=&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7Edefault-6.control
	liubobo �㷨����Σ� ������
*/

#include <iostream>  // pause
#include <vector>  // std::vector
#include <cassert>  // ����

class Solution {
public:
	void sort_colors(std::vector<int> &nums) {  // ��������
		int count[3] = { 0 };  // �������飬count[0] ��¼nums[i] = 0����������
		for (int i = 0; i < nums.size(); i++) {
			assert (nums[i] >= 0 && nums[i] <= 2);  // ����nums��Ԫ����0/1/2���쳣����
			count[nums[i]]++;  // ����
		}
		int index = 0;
		for (int i = 0; i < count[0]; i++)  // [)  ����ҿ�
			nums[index++] = 0;  // ֮�����
		for (int i = 0; i < count[1]; i++)  // ����ҿ��� count[1]��1
			nums[index++] = 1;
		for (int i = 0; i < count[2]; i++)  // ����ҿ���count[2]��2
			nums[index++] = 2;
	}

	void sort_colors2(std::vector<int> &nums) {  // ��һ��д����100�������ܲ�����д100��forѭ���ɣ�
		int count[3] = { 0 };  // ȫ0����
		for (int i = 0; i < nums.size(); i++) {
			assert(nums[i] >= 0 && nums[i] <=2);  // ���ԣ���[0,2]
			count[nums[i]]++;  // ����
		}
		int index = 0;
		for (int i = 0; i <= 2; i++)
			for (int j = 0; j < count[i]; j++)
				nums[index++] = i;  // ̫���ˡ�  ��Ȧѭ��count[i]��i��  ��Ȧ��count[i]��Ԫ�ظ�ֵi  
	}
};

int main() {
	std::vector<int> nums = { 1, 2, 0, 1, 0, 2, 0, 2, 0, 1, 1, 0, 0 };

	Solution solve;
	solve.sort_colors2(nums);  // ��������

	for (int i = 0; i < nums.size(); i++)
		printf("%d ", nums[i]);
	printf("\n");
	system("pause");
	return 0;
}


