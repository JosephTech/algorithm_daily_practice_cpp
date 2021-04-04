/*
二分查找法：
	给定 有序数组int array[]   （注意是排好序的数组）
	数组长度 int n
	待查找元素 target
	找到则返回 索引，未找到返回-1

每次分两半查找，中间是则找到，否则继续分两半
*/
#include <iostream>  // pause,

int binary_search(int array[], int n, int target) {
	int l = 0, r = n - 1;  // 维护区间，target在[0, n-1]闭区间。 注意边界
	while (l <= r) {  // 注意 当l=r时候，闭区间仍然合法。  所以是l<=r
		int mid = (r + l) / 2;  // mid是中间索引。 注意是r+l
		if (array[mid] == target) 
			return mid;
		if (target > array[mid]) //  维护闭区间
			l = mid + 1;
		else   // 维护闭区间
			r = mid - 1;
	}
	return -1;
}

int main() {
	int arr[100];
	for (int i = 0; i < 100; i++) {
		arr[i] = 10 * i;
	}
	int res = binary_search(arr, 100, 990); // 数组不允许引用
	printf("索引 res = %d\n", res);

	system("pause");
	return 0;
}