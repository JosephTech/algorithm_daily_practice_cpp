#include <iostream>  // pause, cout
#include <vector>  // std::vector

class Solution {
public:
	void bubbleSort(std::vector<int> &nums) {  //�������ã���ֹ��������
		int flag = 1;  //��־λ�����ź���ѭ��һ�Σ�ʱ�临�Ӷ�O(n)
		int length = nums.size();
		for (int i = 0; i < length -1 ; i++) {  // ѭ��n-1�֣�ÿ��ðһ��
			for (int j = 1; j < length - i; j++) { //��һ�ֱ�n-1�Σ��ڶ��ֱ�n-2��...
				if (nums[j - 1] > nums[j]) {  //ǰ>�󣬽���
					int temp = nums[j - 1];
					nums[j - 1] = nums[j];
					nums[j] = temp;
					flag = 0;
				}
			}
			if (flag) break;  // ����Ѿ��ź���ֱ��������Ȧѭ��
		}
	}
};


int main() {
	std::vector<int> nums = { 8, 1, 6, 9, 7, 5, 2, 3, 4 };
	Solution solve;
	solve.bubbleSort(nums);  //��������

	for (int i = 0; i < nums.size(); i++) {
		printf("%d ", nums[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}