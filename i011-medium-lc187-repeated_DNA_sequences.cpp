/*
题目：
给一串DNA，A C G T
求其 出现2次及以上的 长度为10的 子串，

例如：
"AAAAAAAAATCCCCCCCCCTAAAAAAAAAT"
其中
返回["AAAAAAAAAT",]
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
	//复杂度分析：O(n)
	// 1个元素 哈希表 插、查是O(1)
public:
	vector<string> substringDNA(string str) {  // 输入DNA序列， 返回 [" ", " "]
		vector<string> result;
		unordered_map<string, int> word_map;  // 键是 长度10的substring， 值是计数
		for (int i = 0; i <= str.length() - 10; i++) {  // str.length=11, [0,9] [1,10]
			string word = str.substr(i, 10);  // 子串。 上一行的-10可以不写，这个找不到substr就跳出循环了
			if (word_map.find(word) != word_map.end())  // 找到了
				word_map[word] += 1;
			else
				word_map[word] = 1; // 计数，但其实find()的时候，计数就已经是0了
		}
		unordered_map<string, int> ::iterator iter;
		for (iter = word_map.begin(); iter != word_map.end(); iter++) {
			if (iter->second > 1)
				result.push_back(iter->first);
		}
		return result;
	}
};


int main() {
	string str = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	Solution solve;  // 实例化
	vector<string> result = solve.substringDNA(str);

	for (int i = 0; i < result.size(); i++)
		printf("%s\n",result[i].c_str());  // 强转%s

	system("pause");
	return 0;
}