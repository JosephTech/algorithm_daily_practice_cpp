/*
���볤�ַ���s�����ַ���t;
�ж�s�ǲ���t�Ĵ��ڣ��ǲ���t���ַ���s�ж��У�

˼·��
����map_s[128]��¼s���ַ�������
����map_t[128]��¼t���ַ�������
map_s���ַ��� >= map_t�����Ǵ���
*/

#include <iostream>  // pause
#include <string>
using namespace std;

bool is_window_ok(int map_s[], int map_t[]) {  // һ��Ҫд128������sizeof��� �βΣ��㲻����128
	for (int i = 0; i < 128; i++) {
		if (map_s[i] < map_t[i])
			return false;
	}
	return true;
}

int main() {
	string s = "ADOBECODEBANC";
	string t = "ABCDAB";
	const int MAX_ARRAY_LEN = 128;  // 0~127,��¼�ַ���
	int map_s[128] = { 0 };
	int map_t[128] = { 0 };
	for (int i = 0; i < s.length(); i++)
		map_s[s[i]]++;
	for (int i = 0; i < t.length(); i++)
		map_t[t[i]]++;

	for (int i = 0; i < sizeof(map_s) / sizeof(map_s[0]); i++) {
		if (map_s[i] > 0)
			printf("[%c]: %d��\n", i, map_s[i]);  // Ƶ��
	}
	printf("-----\n");
	for (int i = 0; i < sizeof(map_t) / sizeof(map_t[0]); i++) {
		if (map_t[i] > 0)  // Ƶ��1�� 2 ...
			printf("[%c]: %d��\n", i, map_t[i]);
	}

	printf("is_window_ok = %d\n", is_window_ok(map_s, map_t));

	system("pause");
	return 0;
}