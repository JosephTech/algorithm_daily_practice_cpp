/*
数组中第K大的数
	已知一个未排序的数组，求这个数组中第K大的数字
	如： array = [3,2,1,5,6,4], k=2, return 5
*/
/*
思路一：
	排序，再返回k的位置，这个时间复杂度是nlog(n)
	比如，n=100万， k=5, 此时nlog(n) >> nlog(k)
思路二：
	利用最大堆、最小堆把 时间复杂度 降低到 nlog(k)
	
	维护一个K大小的最小堆， 堆中元素个数小于K时， 新元素直接进入堆；
	否则，当堆顶小于新元素时，弹出堆顶，将新元素加入堆

	解释：
		由于堆是最小堆，堆顶是堆中最小元素，
		新元素比堆顶小，则不要。否则堆弹出堆顶，新元素加到堆里，
		所以堆中存储了 已扫描元素中 最大的K个。
		堆顶 一直是 已扫描元素中第K大的数
*/

/*
构建堆 的时间复杂度
插入数据 的时间复杂度：
*/

#include <stdio.h>
#include <queue> // 有了这行，std::vector才不报错
#include <functional>

class Solution {
public:
	int findKthLargest(std::vector<int> &nums, int k) { // &nums是 数组的引用
		// 维护一个最小堆，堆中元素个数为k
		std::priority_queue<int, std::vector<int>, std::greater<int> >	Q;

		// for循环，当小于k时候push, 当>top时候push
		for (int i = 0; i < sizeof(nums)/sizeof(nums[0]); i++) { //遍历数组
			if (Q.size() < k) { // 不够k个，就push进堆 
				Q.push(nums[i]);
			}
			// 如果比堆顶小，弹出堆顶，新元素入堆
			else if (nums[i] > Q.top()) {
				Q.pop();
				Q.push(nums[i]);
			}
		}
		// return top
		return Q.top(); //返回堆顶
	}
};

int main() {
	Solution sol;
	std::vector<int> nums = { 5, 4, 1, 6, 2, 3 };
	int k = 1;
	printf("第%d大的元素 = %d\n", k,sol.findKthLargest(nums, k));

	system("pause");
	return 0;
}