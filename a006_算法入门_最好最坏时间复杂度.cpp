/*
在arr[n]的数组中，按顺序查找x，返回其下标i，如果没找到，则返回-1
*/
#include <iostream>
#include <vector>

int findx(int x, std::vector<int> arr) {
	int length = arr.size();
	for (int i = 0; i < length; i++) {
		if (arr[i] == x) {
			return i;
		}
	}
	return -1;
}

/*
n = length
最差情况，执行n次
最好情况，执行1次

如果概率分布均等，平均执行次数 (1+n)/2

就是求均值：  每个数乘概率，累加
*/