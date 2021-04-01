/*
题目：从终端输入两个数，输出它们的和
*/
#include <iostream>  // cin,cout,pause


int main() {
	int a, b;
	std::cin >> a >> b;
	std::cout << a + b;
	printf("\n");
	system("pause");
	return 0;  // 正常结束，main返回0 给操作系统
}