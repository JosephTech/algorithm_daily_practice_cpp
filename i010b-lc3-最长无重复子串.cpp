/*
更简单的写法
*/
#include <iostream>  // pause
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	int longestSubstring(string &str) {  // 最长无重复子串，l r指针，字符哈希计数。下一个数量==0且不越界，r继续走，计数
		int  l = 0, r = -1, max_len = 0;  // 左闭右闭
		int char_map[256] = { 0 };  // 字符哈希，键字符，值计数。 保持每个字符的数量为1即可
		while (l < str.length()) {  // 左闭右闭，l=length()就索引不到了
			if (r + 1 < str.length() && char_map[str[r + 1]] == 0)  // 不越界，r+1=length()，那么r+1就越界了
				char_map[str[++r]]++;  // r先前进， 在计数
			else
				--char_map[str[l++]];  // 先减数，再l前进
			max_len = max(max_len, r-l+1);  // 左闭右闭
		}
		return max_len;
	}
};

int main() {
	string str = "aaabcdadaaa";
	Solution solve;
	printf("max_len = %d\n", solve.longestSubstring(str));

	system("pause");
	return 0;
}