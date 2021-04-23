/*
位运算法，
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int g_hash_map[1048576] = { 0 };  // 2^21-1全局数组。 哈希太大了，放在全局，是虚拟内存中，否则编译器处理不了

string changeToDNA(int dna_int) {
	static const char ch_map[] = {'A', 'C', 'G', 'T'};  // 0 1 2 3
	string str;
	for (int i = 0; i < 10; i++) {  // 不为0的时候
		str += ch_map[dna_int & 3];  // 位运算，按位与， 去掉高位
		dna_int = dna_int >> 2;  // 一定要重新赋值 =
	}
	return str;
}

class Solution {
public:
	vector<string> substringDNA(string str) {  //
		vector<string> result;
		if (str.length() < 10)
			return result;  // 异常
		for (int i = 0; i < sizeof(g_hash_map) / sizeof(g_hash_map[0]); i++) {  // 清空 全局变量初始化
			g_hash_map[i] = 0;
		}
		int char_map[128] = {0};  // 字符哈希，键 字符，值 编码0123
		char_map['A'] = 0;
		char_map['C'] = 1;
		char_map['G'] = 2;
		char_map['T'] = 3;
		int key = 0;
		for (int i = 9; i >= 0; i--)
			key = (key << 2) + char_map[str[i]];  // 乘4。 叠加。 小端模式
		g_hash_map[key] = 1;  // 第一个该字符串 计数
		for (int i = 10; i < str.length(); i++) {  // 遍历字符串，计数
			key = key >> 2; // 除以4 （右移两位，空出来头）。  一定要重新赋值 =
			key = key | (char_map[str[i]] << 18);  // 乘2^18, 按位或  （就是放到头部，相当于加上）
			g_hash_map[key]++;
		}
		for (int i = 0; i < sizeof(g_hash_map) / sizeof(g_hash_map[0]); i++) {
			if (g_hash_map[i] > 1) {  // 若重复
				result.push_back(changeToDNA(i));  // i是DNA的编码
			}
		}
		return result;
	}

};

int main() {
	string str = "AAAAACCCCCAAAAAACCCCCCAAAAAGGGTTT";
	Solution solve; // 实例化
	vector<string> result = solve.substringDNA(str);
	for (int i = 0; i < result.size(); i++)
		printf("%s\n", result[i].c_str());  // 强转字符串


	system("pause");
	return 0;
}