/*
思路：
1、把字符串 映射成char_map  （以vec的形式）
2、以char_map作为键，[str作为值]
3、迭代器 遍历，存到result中
*/
#include <iostream>  // pause
#include <string>
#include <vector>
#include <map>

void change_to_vec(std::string &str, std::vector<int> &vec) {  // 传入引用，返回char_map作为 键
	for (int i = 0; i < 26; i++) {
		vec.push_back(i);
	}
	for (int i = 0; i < str.length(); i++) {
		vec[str[i] - 'a']++;
	}
}


class Solution {
public:
	std::vector<std::vector<std::string>> groupAnagram(
		std::vector<std::string> &strs) {  // 传入引用，返回[["eat", "ate", "tea"],["xyz"],["fuc"]] 
		std::vector<std::vector<std::string>> result;  // 存结果
		std::map<std::vector<int>, std::vector<std::string>> nan_map;  // 编码，映射成[str1, str2]
		for (int i = 0; i < strs.size(); i++) {
			std::vector<int> vec;
			change_to_vec(strs[i], vec);
			nan_map[vec].push_back(strs[i]);
		}
		std::map<std::vector<int>, std::vector<std::string>>::iterator it;
		for (it = nan_map.begin(); it != nan_map.end(); it++) {  // 存到结果里
			result.push_back((*it).second);
		}
		return result;
	}
};


int main() {
	std::vector<std::string> strs = { "eat", "tea", "ate", "fuc", "xyz" };
	Solution solve;
	std::vector<std::vector<std::string>> result = solve.groupAnagram(strs);

	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			printf("[%s]", result[i][j].c_str());  // 字符串 强制转成 %s才能输出
		}
		printf("\n");
	}

	system("pause");
	return 0;
}