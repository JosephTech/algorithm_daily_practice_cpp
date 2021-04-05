/*
找出数组中第k大的元素

(注意：是第k大的元素，不是第k大的不同元素)
（第k大元素只用维护一个最小堆）

例如：
	输入: [3,2,1,5,6,4] 和 k = 2
	输出: 5

	输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
	输出: 4
*/
/*
思路：
	维护一个最小堆，返回堆顶即可
*/

#include <queue>  // std::priority_queque
#include <iostream>  // pause
#include <functional>  // std::greater 

class Solution {
public:
	int find_kth_largest(std::vector<int> &nums, int k) {  // 传入nums数组引用，传入k， 返回堆顶
		std::priority_queue <int, std::vector<int>, std::greater<int>> Q;  // 最小堆，从小到大向量
		for (int i = 0; i < nums.size(); i++) {
			if (Q.size() < k)  // 注意是<，如k=3，当size=2时候，push一个就成了
				Q.push(nums[i]);
			else if (nums[i] > Q.top()) { // Q.size() >= k的时候, 且nums[i]大。 就弹堆、放进去
					Q.pop();
					Q.push(nums[i]);
			}
		}
		return Q.top();
	}
};

int main() {
	std::vector<int> nums = { 3, 2, 1, 5, 6, 4 };

	Solution solve;  // 实例化
	int res = solve.find_kth_largest(nums, 2);  // 第二大
	printf("res = %d\n", res);

	system("pause");
	return 0;
}