/*
�����е�K�����
	��֪һ��δ��������飬����������е�K�������
	�磺 array = [3,2,1,5,6,4], k=2, return 5
*/
/*
˼·һ��
	�����ٷ���k��λ�ã����ʱ�临�Ӷ���nlog(n)
	���磬n=100�� k=5, ��ʱnlog(n) >> nlog(k)
˼·����
	�������ѡ���С�Ѱ� ʱ�临�Ӷ� ���͵� nlog(k)
	
	ά��һ��K��С����С�ѣ� ����Ԫ�ظ���С��Kʱ�� ��Ԫ��ֱ�ӽ���ѣ�
	���򣬵��Ѷ�С����Ԫ��ʱ�������Ѷ�������Ԫ�ؼ����

	���ͣ�
		���ڶ�����С�ѣ��Ѷ��Ƕ�����СԪ�أ�
		��Ԫ�رȶѶ�С����Ҫ������ѵ����Ѷ�����Ԫ�ؼӵ����
		���Զ��д洢�� ��ɨ��Ԫ���� ����K����
		�Ѷ� һֱ�� ��ɨ��Ԫ���е�K�����
*/

/*
������ ��ʱ�临�Ӷ�
�������� ��ʱ�临�Ӷȣ�
*/

#include <stdio.h>
#include <queue> // �������У�std::vector�Ų�����
#include <functional>

class Solution {
public:
	int findKthLargest(std::vector<int> &nums, int k) { // &nums�� ���������
		// ά��һ����С�ѣ�����Ԫ�ظ���Ϊk
		std::priority_queue<int, std::vector<int>, std::greater<int> >	Q;

		// forѭ������С��kʱ��push, ��>topʱ��push
		for (int i = 0; i < sizeof(nums)/sizeof(nums[0]); i++) { //��������
			if (Q.size() < k) { // ����k������push���� 
				Q.push(nums[i]);
			}
			// ����ȶѶ�С�������Ѷ�����Ԫ�����
			else if (nums[i] > Q.top()) {
				Q.pop();
				Q.push(nums[i]);
			}
		}
		// return top
		return Q.top(); //���ضѶ�
	}
};

int main() {
	Solution sol;
	std::vector<int> nums = { 5, 4, 1, 6, 2, 3 };
	int k = 1;
	printf("��%d���Ԫ�� = %d\n", k,sol.findKthLargest(nums, k));

	system("pause");
	return 0;
}