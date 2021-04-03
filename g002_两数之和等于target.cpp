/*
��Ŀ��
	����һ�����У�	
	������������������


���磺nums = [2, 7, 11, 15], target = 9
���أ� [0,1]
������ֻ����һ��𰸣�����ͳһԪ�ز���ʹ�����ߣ�
����target=4�����ܷ�������2������[0,0]��
*/
/*
�ⷨ1��
	����Ƕ��ѭ����ö��x,y�������ǲ���9
	O(n^2)
�ⷨ2��
	ֻ��ö��x����9-x�Ƿ�Ҳ������������
	O(n) ֻ���ԡ�ö����һ��
*/

#include <iostream>  // pause
#include <unordered_map>  // std::map
#include <vector>  // std::vector


std::vector<int> two_sum(std::vector<int> &nums, int target) {  // Ŀ��
	std::vector<int> ans; // �������Ž�����������������
	std::unordered_map<int, int> hashmap;  // hash�� ����num��ֵ������i
	for (int i = 0; i < nums.size(); i++) {
		int tag = target - nums[i];  // �����ҵ�ֵ tag
		if (hashmap.find(tag) != hashmap.end()) {  // �����hash����Ͱ�������ӵ�ans������
			ans.push_back(hashmap[tag]);
			ans.push_back(i);  //��������������
			break;  // ����ѭ��
		}
		// Ϊʲô֮������ӣ���Ϊ���ܷ�����������������ԾͲ��Լ���ǰ��
		// ̫����
		hashmap[nums[i]] = i; // ����nums[i]  ֵ��i
	}
	return ans;
}

/*
ö��O(n)
����O(1)
һ����O(n)
*/

int main() {
	std::vector<int> nums = { 2, 7, 11, 15 };

	std::vector<int> ans = two_sum(nums, 9);
	for (int i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}