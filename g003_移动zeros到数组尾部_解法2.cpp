/*
˼·2��
	����һ��ָ��k
	ʹ��iָ�����nums��ÿ��Ԫ��
	��i��������0Ԫ�ص�ʱ�򣬾ͷŵ�kλ�ã�k+=1
*/

#include <iostream>  // puase
#include <vector>  // std::vector

class Solution {
public:
	// ʱ�临�Ӷ�O(n)
	// �ռ临�Ӷ�O(1) û��ʹ���κθ����ռ�
	void move_zeros(std::vector<int> &nums) {
		int k = 0;  // nums��, [0,k)��Ԫ�ؾ�Ϊ��0Ԫ��
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i]) {  // ��iָ���0Ԫ�أ��� ��ֵ��nums[k] �� k++
				nums[k] = nums[i];
				k++;  //����д�ϱ�
			}
		}
		for (int i = k; i < nums.size(); i++) {  // ��k��ʣ�࣬��ȫ��ֵΪ0
			nums[i] = 0;
		}
	}
};


int main() {
	int arr[] = { 0, 1, 0, 3, 12 };
	std::vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));  // ������βָ�롣����arr����vec

	//std::vector<int> nums = {0, 1, 0, 3, 12};
	Solution solve;
	solve.move_zeros(nums);  // ��������

	for (int i = 0; i < nums.size(); i++) {
		printf("%d ",nums[i]);
	}
	printf("\n");
	
	system("pause");
	return 0;
}