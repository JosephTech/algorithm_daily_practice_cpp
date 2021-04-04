/*
˼·��
	ָ��k ��λ��0��ʼ
	[0,k)�Ƿ�0����

	ʹ��i�������飬��iָ�����ʱ�򣬾ͺ�kָ������ֽ���
*/

#include <iostream>
#include <vector>

class Solution {
public:
	// ʱ�临�Ӷ�O(n)   ����һ��
	// �ռ临�Ӷ�O(1)   û���������ռ䣬��һ��swap    
	void move_zeros(std::vector<int> &nums) {  //�����������á�
		int k = 0;  // kָ�룬 [0,k)�Ƿ�������
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i])  // �����㣬����
				if (i != k)  // ���������鶼�Ƿ���Ԫ�أ�����Ҫ����
					std::swap(nums[i], nums[k++]);  // ����֮��k++
				else  // i==kʱ�� ˵���������鶼�Ƿ���Ԫ�أ�����Ҫ����
					k++;
		}
	}
};

int main() {
	std::vector<int> nums = { 0, 1, 0, 3, 12 };

	Solution solve;
	solve.move_zeros(nums);  //��������

	for (int i = 0; i < nums.size(); i++)
		printf("%d ", nums[i]);

	system("pause");
	return 0;
}