/*
��Ŀ��
��һ��DNA��A C G T
���� ����2�μ����ϵ� ����Ϊ10�� �Ӵ���

���磺
"AAAAAAAAATCCCCCCCCCTAAAAAAAAAT"
����
����["AAAAAAAAAT",]
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
	//���Ӷȷ�����O(n)
	// 1��Ԫ�� ��ϣ�� �塢����O(1)
public:
	vector<string> substringDNA(string str) {  // ����DNA���У� ���� [" ", " "]
		vector<string> result;
		unordered_map<string, int> word_map;  // ���� ����10��substring�� ֵ�Ǽ���
		for (int i = 0; i <= str.length() - 10; i++) {  // str.length=11, [0,9] [1,10]
			string word = str.substr(i, 10);  // �Ӵ��� ��һ�е�-10���Բ�д������Ҳ���substr������ѭ����
			if (word_map.find(word) != word_map.end())  // �ҵ���
				word_map[word] += 1;
			else
				word_map[word] = 1; // ����������ʵfind()��ʱ�򣬼������Ѿ���0��
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
	Solution solve;  // ʵ����
	vector<string> result = solve.substringDNA(str);

	for (int i = 0; i < result.size(); i++)
		printf("%s\n",result[i].c_str());  // ǿת%s

	system("pause");
	return 0;
}