/*
���򵥵�д��
*/
#include <iostream>  // pause
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	int longestSubstring(string &str) {  // ����ظ��Ӵ���l rָ�룬�ַ���ϣ��������һ������==0�Ҳ�Խ�磬r�����ߣ�����
		int  l = 0, r = -1, max_len = 0;  // ����ұ�
		int char_map[256] = { 0 };  // �ַ���ϣ�����ַ���ֵ������ ����ÿ���ַ�������Ϊ1����
		while (l < str.length()) {  // ����ұգ�l=length()������������
			if (r + 1 < str.length() && char_map[str[r + 1]] == 0)  // ��Խ�磬r+1=length()����ôr+1��Խ����
				char_map[str[++r]]++;  // r��ǰ���� �ڼ���
			else
				--char_map[str[l++]];  // �ȼ�������lǰ��
			max_len = max(max_len, r-l+1);  // ����ұ�
		}
		return max_len;
	}
};

int main() {
	string str = "aaabcdadaaa";
	Solution solve;
	printf("max_len = %d\n", solve.longestSubstring(str));

	system("pause");
	return 0;
}