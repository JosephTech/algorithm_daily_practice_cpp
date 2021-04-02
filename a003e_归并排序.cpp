/*
归并排序：

参考资料：
	归并排序C++实现
	https://zhuanlan.zhihu.com/p/74820690
*/

#include <iostream>  // pause, cout
#include <vector>

void merge_sort(std::vector<int> &nums, int l, int r, std::vector<int> &temp) {  
	// temp是新申请的内存空间，存放结果。  l指向已排序序列起始位置， r指向另一个已排序序列起始位置。
	if (l + 1 >= r) {  // 左指针指完了
		return;
	}
	// 分治
	int mid = l + (r - l) / 2;  // 因为l是左序列起点，l可为0。 mid为左序列终点
	merge_sort(nums, l, mid, temp);  // 左边一半
	merge_sort(nums, mid, r, temp);
	// 排序
	int p = l, q = mid, i = l;  // p指针从l到mid-1 移动。  q从mid到r，移动。 i是temp的指针，从l开始移动
	while (p < mid && q < r) {  // 两个序列，有一个遍历完了，就结束
		if (nums[p] < nums[q]) {  // nums[p]小，就把nums[p]放到temp中。 <不改变相等数字的相对位置
			temp[i] = nums[p]; // 谁小把谁放到temp
			i++;
			p++;
		}
		else {
			temp[i] = nums[q];  // nums[q]大于等于， 则取nums[q] 
			i++;
			q++;
		}

	}
	// 最后p=mid,左部分遍历完了
	// 最后q=r，右边部分遍历完了
	//剩谁，谁挨个放到temp里
	if (p < mid) {
		while (p < mid) {
			temp[i] = nums[p];
			i++;
			p++;
		}
	}
	if (q < r) {
		while (q < r) {
			temp[i] = nums[q];
			i++;
			q++;
		}
	}
	for (i = l; i < r; i++) {
		nums[i] = temp[i];  // temp序列 挨个放到 nums里
	}
}

int main() {
	std::vector<int> nums = {9, 1, 8, 5, 7, 2, 6, 3, 4,};
	int l = 0;
	int r = nums.size();
	std::vector<int> temp(10,0);  // 10个0
	merge_sort(nums, l, r, temp);

	for (int i = 0; i < nums.size(); i++) {
		printf("%d ", nums[i]);
	}

	system("pause");
	return 0;
}