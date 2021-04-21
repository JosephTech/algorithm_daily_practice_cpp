/*
最长回文串

题目：
	输入一个字符串，
	使用 其中的字符，构成回文串，
	返回最长长度
*/
/*
思路：
	hash_map计数
	偶数
	或偶数+ 随便一个
*/
#include <string>  // std::string
#include <iostream>  // std::pause

class Solution {
public:
	int longestPalindrome(std::string str) {  // 传入str，返回整型
		int char_map[128] = {0};  // 这么多个0。字符哈希 还是直接而用数组 的好
		for (int i = 0; i < str.length(); i++) {
			char_map[str[i]] += 1;  // 字符哈希 计数
		}
		int max_len = 0;
		int flag = 0;
		for (int i = 0; i < 128; i++) {  // 遍历 字符哈希，遇到偶数 max_len加上，遇到奇数，加上-1，,
			if (char_map[i] % 2 == 0) {  // 偶数，加上。 0则，加上
				max_len += char_map[i];
			}
			else if (char_map[i] % 2 == 1) {  // 奇数。 1，则+0，更新flag。 3则+2，更新flag
				max_len += char_map[i] - 1;
				flag = 1;
			}
		}
		return max_len + flag;
	}
};

int main() {
	std::string str = "adddddcefxyz";
	Solution solve;  // 实例化
	printf("res = %d\n", solve.longestPalindrome(str));

	system("pause");
	return 0;
}