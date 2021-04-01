/*
��Ծ��Ϸ2��
	һ������洢�˷Ǹ��������ݣ������еĵ�i��Ԫ��nums[i]�������˿��Դ������i��λ�����
	��ǰ��Ծnums[i]������֪�����Ԫ�ص�����£�ȷ�Ͽ��Դӵ�0λ����Ծ���������һ��λ�ã�
	������������Ծ���Σ���
	��ע�⣺0��ȷ�����������ġ� �м��λ��iҲ���������
*/
/*
̰��˼·��
	��ԽԶԽ��.
*/
/*
˼����
	���ϣ��������Ծ�ﵽ�յ㣬������ȷ��ʱ������Ծ������ʵġ�

	���������Ծ�������������Ծ������

̰�Ĺ��ɣ�
	����ĳ��ǰ��һֱ����Ծ�����ִӸõ㲻��������Զ�ĵط��ˣ�����֮ǰ�϶��дα�Ҫ����Ծ

���ۣ�
	����������
	ֱ���޷������Զ�ĵط�ʱ������֮ǰ���Ҹ�λ�ã�����һ����Զ�ط�
	���ܱ�֤���Ĵ���������
*/

#include <iostream>
#include <vector>

// 
class Solution {
public:	// ������
	int lessJumpTimes(std::vector<int> &nums) { //����nums�����á�  nums�����飬��vector��
		if (nums.size() < 2) { //Ԫ�ظ���0��1,�Ͳ�����������0��
			return 0;
		}
		int jump_times = 1; //������Ծ��������ʼ��
		int current_max_jump = nums[0]; //��ǰ��Զ��Ծ���ĸ�λ��j�� ��ʼ��
		int pre_max_max_jump = nums[0]; //�����ӵ�ǰλ��i����Զλ��j����¼�´�������Զλ�á���ʼ��
		for (int i = 0; i < nums.size(); i++) {
			if (i > current_max_jump) { // ����������ֱ��i>j������j=current_max_jump�� ������һ�Σ�ֱ������i~j����Զ��¼pre
				current_max_jump = pre_max_max_jump;
				jump_times++;
			}
			if (pre_max_max_jump < nums[i] + i ) { //��nums[i] + i��˵���´�������Զ������pre
				pre_max_max_jump = nums[i] + i;
			}
		}
		return jump_times;
	}
};

int main() {
	// ������ ���2 3 1 1 4
	std::vector<int> nums;
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(4);

	// ʵ��������ӡ
	Solution solve;
	printf("less jump times = %d\n", solve.lessJumpTimes(nums));

	system("pause");
	return 0;
}
// warning �з����޷��Ų�ƥ�䣬���ùܣ�ֻ��warning