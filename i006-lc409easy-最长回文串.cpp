/*
����Ĵ�

��Ŀ��
	����һ���ַ�����
	ʹ�� ���е��ַ������ɻ��Ĵ���
	���������
*/
/*
˼·��
	hash_map����
	ż��
	��ż��+ ���һ��
*/
#include <string>  // std::string
#include <iostream>  // std::pause

class Solution {
public:
	int longestPalindrome(std::string str) {  // ����str����������
		int char_map[128] = {0};  // ��ô���0���ַ���ϣ ����ֱ�Ӷ������� �ĺ�
		for (int i = 0; i < str.length(); i++) {
			char_map[str[i]] += 1;  // �ַ���ϣ ����
		}
		int max_len = 0;
		int flag = 0;
		for (int i = 0; i < 128; i++) {  // ���� �ַ���ϣ������ż�� max_len���ϣ���������������-1��,
			if (char_map[i] % 2 == 0) {  // ż�������ϡ� 0�򣬼���
				max_len += char_map[i];
			}
			else if (char_map[i] % 2 == 1) {  // ������ 1����+0������flag�� 3��+2������flag
				max_len += char_map[i] - 1;
				flag = 1;
			}
		}
		return max_len + flag;
	}
};

int main() {
	std::string str = "adddddcefxyz";
	Solution solve;  // ʵ����
	printf("res = %d\n", solve.longestPalindrome(str));

	system("pause");
	return 0;
}