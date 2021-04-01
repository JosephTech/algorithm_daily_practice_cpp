/*
输入、输出数据 不算空间
算法本身 代码文本不算空间

额外需要的辅助空间，是空间复杂度
*/

void swap(int x, int y) {
	int temp;
	temp = x;
	x = y;
	y = temp;
}

/*
额外为变量temp申请了空间，所以空间复杂度是O(1)

此外，常数级 都叫O(1)
*/