/* ȫ����
0 = 000
1 = 001
2 = 010
3 = 011
4 = 100
5 = 101
6 = 110
7 = 111
*/
/*
λ������û�У�
	��001������A������nums[0]
	��010������B, ����nums[1]
	��100������C������nums[2]

0 �� A B C��and ��[]
1 �� A B C��and ��[A]
2 �� A B C��and ��[B]
3 �� A B C��and ��[B] [A]
4 �� A B C��and ��[C]
5 �� A B C��and ��[C][A]
6 �� A B C��and ��[C][B]
7 �� A B C��and ��[C][C][A]

ע�⣺��λ����  һ��&
...
*/
#include <iostream>
#include <vector>

class Solutionl {
public:
	std::vector<std::vector<int>> subSet(std::vector<int> &nums) {
		std::vector<std::vector<int>> result; //�洢���ս������߷ŵ�������
		int all_set = 1 << nums.size(); // 1����3λ  ���1000 = 8
		for (int i = 0; i < all_set; i++) { //��Ȧѭ��0 1 2 3 4 5 6 7
			std::vector<int> item; //��ʼ��item������������߷�
			for (int j = 0; j < nums.size(); j++){ // ��Ȧѭ����A B C
				if (i & (1 << j)) { //i�ֱ���A�� B ��C��and��  1����0λ�� 1����1λ��  1����2λ
					item.push_back(nums[j]); //ע�⣺ ��λ���㣬һ��&
				}
			}
			result.push_back(item);
		}
		return result;
	}
};

int main() {
	std::vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);

	Solution solve;
	std::vector<std::vector<int>> result = solve.subSet(nums);

	//��ӡ���
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			printf("[%d]",result[i][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}





















