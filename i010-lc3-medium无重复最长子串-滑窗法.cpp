/*
��Ŀ��
����һ���ַ�����
����ַ��� ���ظ��� ��Ӵ�
���س��ȼ���
*/
/*
ע�⣺�Ӵ���������
*/
/*
˼·��
1��ʹ��char_map ����
2��˫ָ����� �������ڣ�
begin < i
�ƶ�i
��i��beginָ��(����������ͬԪ�ص�)ʱ����ǰ�ƶ�begin

*/
/*
�������ڣ�ֻ��Ҫ����һ��
���Ӷȣ�
O(n)
*/
#include <iostream>  // pause
#include <string>
#include <algorithm>

class Solution {
public:
	int longestSubstring(std::string &str) {
		int begin = 0;
		int char_map[128] = { 0 };  // ���� �ַ���ϣ
		std::string word = "";
		int max_len = 0;  // ���
		for (int i = 0; i < str.length(); i++) {
			char_map[str[i]] += 1;  // ����
			if (char_map[str[i]] == 1) {  // ����word,���£�i������
				word += str[i];
				int len = word.length();  // ��Ϊword.length()�Ĳ������� ����int������ ������һ��
				max_len = std::max(max_len, len);  // ���½��
			}
			else {  // >1,˵���ظ��ˣ�begin���ߵ����ظ���λ��
				while (char_map[str[i]] > 1) {  // begin����ߵ�i��char_map[str[i]]��==1,�ͽ�����
					char_map[str[begin]]--;
					begin++;
				}
				word = ""; // ����word
				for (int j = begin; j <= i; j++) {
					word += str[j];
				}
			}
		}
		return max_len;
	}
};

int main() {
	std::string str = "aaabcdadaaa";
	Solution solve;
	printf("%d\n", solve.longestSubstring(str));  // ��������

	system("pause");
	return 0;
}

/*
�����ܽ᣺
������ �ַ������û�������
*/