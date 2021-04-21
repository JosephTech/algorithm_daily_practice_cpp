/*
题目：
已知一组 字符串，
将所有anagram（由颠倒字母构成的词）放在一起输出
*/
/*
例如：
输入：["eat", "tea", "tan", "ate", "nat", "bat"]
返回：[["ate", "eat", "tea"],["nat", "tan"],["bat"]]
*/

#include <iostream>  // pause
#include <vector>  // std::vector
#include <map>
#include <algorithm>

class Solution {
public:
	std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs) {
		std::vector<std::vector<std::string>> results;
		std::map<std::string, std::vector<std::string>> anagram_map;
		for (int i = 0; i < strs.size(); i++) {  // 遍历strs，放到anagram_map中
			std::string str = strs[i];  // 避免修改原数据
			std::sort(str.begin(), str.end());  // 字符串排序
			if (anagram_map.find(str) == anagram_map.end()) {  // 没找到
				std::vector<std::string> item;
				anagram_map[str] = item;   // 初始化？这个键
			}
			anagram_map[str].push_back(strs[i]);
		}
		std::map<std::string, std::vector<std::string>>::iterator it;
		for (it = anagram_map.begin(); it != anagram_map.end(); it++) {  // 迭代器
			//results.push_back(it->second);
			results.push_back((*it).second);  // 解引用，也行
		}
		return results;
	}
};

int main() {
	std::vector<std::string> strs = { "eat", "ate", "tea", "bat", "nat" };
	Solution solve;  // 实例化
	std::vector<std::vector<std::string>> res = solve.groupAnagrams(strs);

	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			printf("[%s] ", res[i][j].c_str());  // 强转字符串
		}
		printf("\n");
	}

	system("pause");
	return 0;
}