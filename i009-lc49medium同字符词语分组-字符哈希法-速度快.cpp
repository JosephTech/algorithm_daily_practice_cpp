/*
˼·��
1�����ַ��� ӳ���char_map  ����vec����ʽ��
2����char_map��Ϊ����[str��Ϊֵ]
3�������� �������浽result��
*/
#include <iostream>  // pause
#include <string>
#include <vector>
#include <map>

void change_to_vec(std::string &str, std::vector<int> &vec) {  // �������ã�����char_map��Ϊ ��
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
		std::vector<std::string> &strs) {  // �������ã�����[["eat", "ate", "tea"],["xyz"],["fuc"]] 
		std::vector<std::vector<std::string>> result;  // ����
		std::map<std::vector<int>, std::vector<std::string>> nan_map;  // ���룬ӳ���[str1, str2]
		for (int i = 0; i < strs.size(); i++) {
			std::vector<int> vec;
			change_to_vec(strs[i], vec);
			nan_map[vec].push_back(strs[i]);
		}
		std::map<std::vector<int>, std::vector<std::string>>::iterator it;
		for (it = nan_map.begin(); it != nan_map.end(); it++) {  // �浽�����
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
			printf("[%s]", result[i][j].c_str());  // �ַ��� ǿ��ת�� %s�������
		}
		printf("\n");
	}

	system("pause");
	return 0;
}