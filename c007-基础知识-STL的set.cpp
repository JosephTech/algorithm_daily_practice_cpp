/*
STL set容器 的使用 
*/

#include <iostream> // system("pause")要用
#include <set>

int main() {
	//创建test_set
	std::set<int> test_set;

	//数组长度
	const int A_LEN = 7; // 常量大写
	const int B_LEN = 8;

	//数组
	int a[A_LEN] = {5, 1, 4, 8, 10, 1, 3 };
	int b[B_LEN] = {2, 7, 6, 3, 1, 6, 0, 1};

	//把a插入到 test_set
	for (int i = 0; i < A_LEN; i++) 
	{
		test_set.insert(a[i]);
	}

	// 打印重复元素
	for (int i = 0; i < B_LEN; i++)
	{
		if (test_set.find(b[i]) != test_set.end()) //find找到, 会返回一个值。未找到 返回test.end() 
		{
			printf("b[%d] = %d is in array a \n", i, b[i]);
		}
	}

	system("pause");
	return 0;
}