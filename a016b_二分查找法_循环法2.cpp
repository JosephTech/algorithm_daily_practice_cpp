#include <iostream>  // puase

int binary_search(int arr[], int n, int target) {  // 二分查找。传入数组arr[]， 数组元素个数n， 待查找目标target
	int l = 0, r = n;  // 维护区间[l, r), 左闭右开
	while (l < r) {  // 当l==r时候，如[33,33)不合法
		int mid = (l + r) / 2;
		if (arr[mid] == target)  // 找到，返回。  注意是两个==
			return mid;
		if (target > arr[mid])  // 在右边的区间
			l = mid + 1;  // 左闭区间
		else  // 在左边
			r = mid;  // 右 开区间
	}
	return -1;
}

int main() {
	int array[100];  // 100个元素的数组
	for (int i = 0; i < 100; i++) {
		array[i] = i*10;
	}

	int res = binary_search(array, 100, 90);  // 数组不能引用

	printf("res = %d\n", res);

	system("pause");
	return 0;
}