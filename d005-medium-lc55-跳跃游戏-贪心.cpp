/*
��Ŀ��
	һ������洢�˷Ǹ��������ݣ� �����е�i��Ԫ��nums[i]�������˿��Դ�����
	��i��λ�á���ࡿ��ǰ��Ծnums[i]���� ��֪�����Ԫ�ص�����£�
	���Ƿ���Դ������0��λ����Ծ���������һ��Ԫ��λ�ã�

	��ע������࣬���������3���� ����1��2��3�����У�
���磺
	nums = [2, 3, 1, 1, 4]�� ���Դ�nums[0] = 2��Ծ�� nums[4] = 4;
	nums = [3, 2, 1, 0, 4]�� �����Դ�nums[0] = 3��Ծ�� nums[4] = 4;
*/
/*
̰��˼·��
	1������Զ��������
		λ��i:						[0, 1, 2, 3, 4]
		��Զ��Ծnums[i]:			[2, 3, 1, 1, 4]
		��Զ�ɴﵽ��λ��index[i]:	[2, 4, 3, 4, 8]
	2)jump��¼��ǰλ�ã���ʼ��Ϊ0
	3)max_index��¼ 0~jumpλ�ã���Զλ�á���ʼ��Ϊindex[0]��

	4)����jumpɨ��index���飬ֱ��jump�ﵽindex����β����jump����max_index����ɨ������У�����max_index
	5)������jumpΪ���鳤�ȣ��򷵻�true�����򷵻�false

һ�仰��jumpֻ���ߵ�max_index
*/

#include <iostream>
#include <vector>

class Solution {
public:
	bool canJump(std::vector<int> &nums) {//���÷�ʽ��������
		std::vector<int> index; //nums��λ��i���������ĸ�λ��
		for (int i = 0; i < nums.size(); i++) {
			index.push_back(i+nums[i]); //vectorֻ��push_back��  i+nums[i]�Ǹ�λ�����������Զ
		}
		int jump = 0; // λ�ã����Զ�
		int max_jump = index[0]; // ������ߵ���
		while (jump <= max_jump && jump < index.size()) {
			if (index[jump] > max_jump) { // ��ɨ�赽��Զ�ģ��͸���max_jump
				max_jump = index[jump];
			}
			jump++; //�ƶ�ɨ��
		}
		if (jump == nums.size()) { //�ߵ���󣬿���
			return true;
		}
		return false;
	}
};

// ��һ�ֽⷨ�����
class Solution2 {
public:
	bool canJump(std::vector<int> &nums) {//���÷�ʽ��������
		std::vector<int> index; //nums��λ��i���������ĸ�λ��
		for (int i = 0; i < nums.size(); i++) {
			index.push_back(i + nums[i]); //vectorֻ��push_back��  i+nums[i]�Ǹ�λ�����������Զ
		}
		int jump = 0; // λ�ã����Զ�
		int max_jump = index[0]; // ������ߵ���
		while (jump <= max_jump && max_jump < index.size()) {
			if (index[jump] > max_jump) { // ��ɨ�赽��Զ�ģ��͸���max_jump
				max_jump = index[jump];
			}
			jump++; //�ƶ�ɨ��
		}
		if (max_jump >= nums.size()) { //�ߵ���󣬿���
			return true;
		}
		return false;
	}
};


int main() {
	std::vector<int> nums;
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(4);

	// Solutionд�ĸ�ֱ�ۣ��Ƽ�ʹ��
	//Solution solve;
	Solution2 solve;
	printf("%d\n", solve.canJump(nums));

	system("pause");
	return 0;
}


