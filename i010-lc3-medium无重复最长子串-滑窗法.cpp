/*
题目：
传入一个字符串，
求该字符串 无重复的 最长子串
返回长度即可
*/
/*
注意：子串是连续的
*/
/*
思路：
1、使用char_map 计数
2、双指针组成 滑动窗口，
begin < i
移动i
当i和begin指向(区间中有相同元素的)时候，向前移动begin

*/
/*
滑动窗口，只需要遍历一次
复杂度：
O(n)
*/
#include <iostream>  // pause
#include <string>
#include <algorithm>

class Solution {
public:
	int longestSubstring(std::string &str) {
		int begin = 0;
		int char_map[128] = { 0 };  // 数组 字符哈希
		std::string word = "";
		int max_len = 0;  // 结果
		for (int i = 0; i < str.length(); i++) {
			char_map[str[i]] += 1;  // 计数
			if (char_map[str[i]] == 1) {  // 更新word,更新，i继续走
				word += str[i];
				int len = word.length();  // 因为word.length()的参数类型 不是int，所以 添上这一笔
				max_len = std::max(max_len, len);  // 更新结果
			}
			else {  // >1,说明重复了，begin就走到不重复的位置
				while (char_map[str[i]] > 1) {  // begin最多走到i，char_map[str[i]]就==1,就结束了
					char_map[str[begin]]--;
					begin++;
				}
				word = ""; // 更新word
				for (int j = begin; j <= i; j++) {
					word += str[j];
				}
			}
		}
		return max_len;
	}
};

int main() {
	std::string str = "aaabcdadaaa";
	Solution solve;
	printf("%d\n", solve.longestSubstring(str));  // 传入引用

	system("pause");
	return 0;
}

/*
个人总结：
连续的 字符串，用滑动窗口
*/