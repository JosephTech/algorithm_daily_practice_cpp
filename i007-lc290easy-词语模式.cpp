/*
��Ŀ��
	ȷ��str��pattern�Ƿ�ƥ��

	pattern��char�ַ���
	str���ַ��������Կո�����
*/
/*
˼·��
ʹ��stl mapӳ�� str��char
���һ����һ��

���Ȳ���Ҳreturn false
*/
#include <iostream>
#include <map>
#include <string>

class Solution {
public:
	bool wordPattern(std::string str, std::string pattern) {
		std::map< std::string, char>  word_map;  // word��char��ӳ��
		int used[128] = { 0 };  //  ���飬��¼char�Ƿ�ʹ�ù� ��ʹ��char����Ҳһ��
		str.push_back(' ');  // ��ո�ʹ�ÿո�ָ�
		int pos = 0;  // ָ�룬ָ��pattern��ÿ���ַ�
		std::string word;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == ' ') {  // �з��µ���
				if (pos >= pattern.length()) {  // �ֳ���word������û��pattern�ˣ�pattern����
					return false;
				}
				if (word_map.find(word) == word_map.end()) {  // ��һ�飬û�ҵ���˵�����´�
					if (used[pattern[pos]]) {  // ��word�������ù���
						return false;
					}
					word_map[word] = pattern[pos];
					used[pattern[pos]] += 1;
				}
				else {  // �ҵ���
					if (word_map[word] != pattern[pos]) {  // �ҵ��ˣ����ǲ���
						return false;
					}
				}
				word = "";  // ���
				pos++;
			}
			else if (str[i] != ' '){  // word�ַ��� �ӳ�
				word += str[i];
			}
		}
		if (pos < pattern.length()) {  // �� pattern����word�̡�  posָ�룬�������,Ӧ������ȵģ�����pattern��str��
			return false;
		}
		return true;
	}
};

int main() {
	std::string str = "dog cat cat cat";
	std::string pattern = "abbb";
	Solution solve;
	printf("res = %d\n", solve.wordPattern(str, pattern));

	system("pause");
	return 0;
}