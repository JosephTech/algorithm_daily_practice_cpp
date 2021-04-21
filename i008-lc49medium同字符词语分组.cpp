/*
��Ŀ��
��֪һ�� �ַ�����
������anagram���ɵߵ���ĸ���ɵĴʣ�����һ�����
*/
/*
���磺
���룺["eat", "tea", "tan", "ate", "nat", "bat"]
���أ�[["ate", "eat", "tea"],["nat", "tan"],["bat"]]
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
		for (int i = 0; i < strs.size(); i++) {  // ����strs���ŵ�anagram_map��
			std::string str = strs[i];  // �����޸�ԭ����
			std::sort(str.begin(), str.end());  // �ַ�������
			if (anagram_map.find(str) == anagram_map.end()) {  // û�ҵ�
				std::vector<std::string> item;
				anagram_map[str] = item;   // ��ʼ���������
			}
			anagram_map[str].push_back(strs[i]);
		}
		std::map<std::string, std::vector<std::string>>::iterator it;
		for (it = anagram_map.begin(); it != anagram_map.end(); it++) {  // ������
			//results.push_back(it->second);
			results.push_back((*it).second);  // �����ã�Ҳ��
		}
		return results;
	}
};

int main() {
	std::vector<std::string> strs = { "eat", "ate", "tea", "bat", "nat" };
	Solution solve;  // ʵ����
	std::vector<std::vector<std::string>> res = solve.groupAnagrams(strs);

	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			printf("[%s] ", res[i][j].c_str());  // ǿת�ַ���
		}
		printf("\n");
	}

	system("pause");
	return 0;
}