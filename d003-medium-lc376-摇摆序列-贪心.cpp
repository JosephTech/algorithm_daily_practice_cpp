/*
ҡ������ medium leetcode376

	һ���������У������������Ԫ�صĲ�ǡ��������������������֣�������б���Ϊҡ�����С�
	һ��С������Ԫ�ص�����ֱ�ӱ���Ϊҡ������

���������εģ�

���磺
	����[1��7��4��9��2��5]��ҡ�����У��6, -3, 5, -7, 3��
	����[1��4��7��2��5]����ҡ�����У��3, 3, -5, 3��
	����[1, 7, 4, 5, 5]����ҡ������,�6, -3, 1, 0��

	ע�⣺��Ԫ����Ȳ���ҡ������
*/
/*
��Ŀ��
	��һ��������У�������ҡ�����е�������еĳ��ȡ�
	��[1, 7, 4, 9, 2, 5]���ҡ�������� ����Ϊ6�� ������ɾ��Ԫ�أ�����ҡ������

	��[1, 2, 3, 3, 4, 5, 6, 7, 8, 9]�ҡ�������г�����2
*/

/*
�����ӣ�
	[1, 17, 5, 10, 13, 15, 10, 5, 16, 8]
��������һ���������������½�ʱ
	�����ݼ��׶Σ�ѡ��С���ڸý׶����һ����
	���������׶Σ�ѡ����ڸý׶����һ����
*/
/*
˼·:
	�Զ�״̬��
*/

#include <iostream>
#include <vector>

class Solution {
public:
	int wiggleMaxLength(std::vector<int> &nums) { //���÷�ʽ����
		if (nums.size() < 2) { //������С��2ֱ����Ϊ��ҡ������
			return nums.size(); 
		}
		static const int BEGIN = 0;
		static const int UP = 1;
		static const int DOWN = 2;
		int max_len = 1; //ҡ�����������ǵ�һ��Ԫ�ء� �ݲ�����������Ԫ��
		int STATE = BEGIN; //��ʼ��״̬STATE�� ��д��Ϊ�˴���淶
		for (unsigned int i = 1; i < nums.size(); i++) 
		{ //��i=1��ʼ��������Ĭ��i=0��ҡ�����е�һ��
			switch (STATE) 
			{
			case BEGIN: //�����ǰԪ��nums[i]=��һ���������ڱ�STATE
				if (nums[i-1] < nums[i]) {
					STATE = UP; //ת��״̬
					max_len++; //��¼״̬ת����ÿת��һ�Σ��Ͷ�һ��Ԫ��
				}
				else if (nums[i - 1] > nums[i]) {
					STATE = DOWN;
					max_len++;
				}
				break; //switchҪ��break�˳�����forѭ��
			case UP://�����ǰԪ��nums[i] = nums[i-1]�������ڱ�STATE. ����Ҳ���ڱ�STATE
				if (nums[i-1] > nums[i]) {
					STATE = DOWN;
					max_len++;
				}
				break;
			case DOWN: //���ȣ����ڱ�STATE;  ���½������ڱ�STATE
				if (nums[i-1] < nums[i]) {
					STATE = UP;
					max_len++;
				}
				break;
			}
		}
		return max_len;
	}
};

int main() {
	// ���졢���
	std::vector<int> nums;
	nums.push_back(1);
	nums.push_back(17);
	nums.push_back(5);
	nums.push_back(10);
	nums.push_back(13);
	nums.push_back(15);
	nums.push_back(10);
	nums.push_back(5);
	nums.push_back(16);
	nums.push_back(8);

	Solution solve;
	printf("max lenth of wiggle ���� = %d\n", solve.wiggleMaxLength(nums));

	system("pause");
	return 0;
}

//�ܽ᣺
// ��������������еĳ���
// ��ÿ��״̬ת��ʱ�򣬰�Ԫ��push_back��ȥ�����������������