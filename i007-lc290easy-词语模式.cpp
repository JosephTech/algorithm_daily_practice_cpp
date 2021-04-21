/*
题目：
	确定str与pattern是否匹配

	pattern是char字符型
	str是字符串，（以空格间隔）
*/
/*
思路：
使用stl map映射 str到char
添加一个比一次

长度不对也return false
*/
#include <iostream>
#include <map>
#include <string>

class Solution {
public:
	bool wordPattern(std::string str, std::string pattern) {
		std::map< std::string, char>  word_map;  // word到char的映射
		int used[128] = { 0 };  //  数组，记录char是否使用过 。使用char数组也一样
		str.push_back(' ');  // 添空格，使用空格分隔
		int pos = 0;  // 指针，指向pattern的每个字符
		std::string word;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == ' ') {  // 切分新单词
				if (pos >= pattern.length()) {  // 分出来word，但是没有pattern了，pattern短了
					return false;
				}
				if (word_map.find(word) == word_map.end()) {  // 找一遍，没找到，说明是新词
					if (used[pattern[pos]]) {  // 新word，但是用过了
						return false;
					}
					word_map[word] = pattern[pos];
					used[pattern[pos]] += 1;
				}
				else {  // 找到了
					if (word_map[word] != pattern[pos]) {  // 找到了，但是不等
						return false;
					}
				}
				word = "";  // 清空
				pos++;
			}
			else if (str[i] != ' '){  // word字符串 加长
				word += str[i];
			}
		}
		if (pos < pattern.length()) {  // 若 pattern长，word短。  pos指针，到最后了,应该是相等的，但是pattern比str长
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