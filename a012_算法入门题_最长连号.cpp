/*
题目：
	输入n个正整数，（1 <= n <= 10000），求输出最长的连号的长度。 （连号指从小到大连续自然数）
*/
/*
输入格式：
	第一行， 一个数n;
	第二行， n个正整数，之间用空格隔开。

输出格式：
	一个数，最长连号个数。
*/

#include <iostream>  // pause, cin, cout
#include <vector>  // std::vector

int main() {
	int n, cnt = 1, max = 1; // max是最大连号，cnt是计数（若cnt>max，更新max）
	int arr[10000 + 5];
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];  // 注意vector不能cin。 数组可以cin
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] + 1 == arr[i + 1]) { // 若连续，计数
			cnt += 1;
			if (cnt > max) {
				max = cnt;  // 若大，立即更新max
			}
		}
		else cnt = 1; // 若不连号，则计数器cnt初始化
	}
	std::cout << max;
	printf("\n");

	system("pause");
	return 0;
}