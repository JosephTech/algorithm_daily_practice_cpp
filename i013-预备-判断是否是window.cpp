/*
传入长字符串s、短字符串t;
判断s是不是t的窗口（是不是t中字符，s中都有）

思路：
利用map_s[128]记录s中字符个数，
利用map_t[128]记录t中字符个数，
map_s中字符数 >= map_t，则是窗口
*/

#include <iostream>  // pause
#include <string>
using namespace std;

bool is_window_ok(int map_s[], int map_t[]) {  // 一定要写128，否则sizeof算的 形参，算不出来128
	for (int i = 0; i < 128; i++) {
		if (map_s[i] < map_t[i])
			return false;
	}
	return true;
}

int main() {
	string s = "ADOBECODEBANC";
	string t = "ABCDAB";
	const int MAX_ARRAY_LEN = 128;  // 0~127,记录字符数
	int map_s[128] = { 0 };
	int map_t[128] = { 0 };
	for (int i = 0; i < s.length(); i++)
		map_s[s[i]]++;
	for (int i = 0; i < t.length(); i++)
		map_t[t[i]]++;

	for (int i = 0; i < sizeof(map_s) / sizeof(map_s[0]); i++) {
		if (map_s[i] > 0)
			printf("[%c]: %d次\n", i, map_s[i]);  // 频次
	}
	printf("-----\n");
	for (int i = 0; i < sizeof(map_t) / sizeof(map_t[0]); i++) {
		if (map_t[i] > 0)  // 频次1、 2 ...
			printf("[%c]: %d次\n", i, map_t[i]);
	}

	printf("is_window_ok = %d\n", is_window_ok(map_s, map_t));

	system("pause");
	return 0;
}