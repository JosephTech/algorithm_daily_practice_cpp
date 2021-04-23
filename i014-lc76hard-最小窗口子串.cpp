#include <iostream>  // pause
#include <string>
using namespace std;

class Solution {
public:
	string minWindowStr(string s, string t) {  // s是长串， t是短串
		const int LENTH = 128;
		int map_s[LENTH] = {0};  // 字符哈希，计数
		int map_t[LENTH] = {0};  // 字符哈希， 计数
		for (int i = 0; i < t.length(); i++)
			map_t[t[i]]++;  // 计数
		int win_begin = 0; // 指针，window_begin
		string result = "";
		for (int i = 0; i < s.length(); i++) {  // i 是窗口结束。  左闭右闭
			map_s[s[i]]++;  // 计数， 注意，一定要这时候 才能弄，（在指针前进时候，计数s）
			while (win_begin < i) {  // 因为win_begin要++,所以是<  不是小于等于
				if (map_t[s[win_begin]] == 0)  // t中没有的字符，
					win_begin++;
				else if (map_s[s[win_begin]] > map_t[s[win_begin]]) {  // s中字符多
					map_s[s[win_begin]]--;
					win_begin++;  // 这两行 不好合， 算了
				}
				else
					break;  // 说明 是个窗口，下一步更新窗口
			}
			int len_of_substr = i - win_begin + 1; // 左闭右闭
			if (is_window_ok(map_s, map_t)) {
				if (result == "" || len_of_substr < result.length()) {
					result = s.substr(win_begin, len_of_substr);
				}
			}
		}
		return result;
	}

private:
	bool is_window_ok(int map_s[], int map_t[]) {  // 两个字符串 的字符哈希，计数，返回字符串s 是否包含t中每个字符
		for (int i = 0; i < 128; i++) {
			if (map_s[i] < map_t[i])  // 若t中 某字符更多
				return false;
		}
		return true;
	}
};

int main() {
	Solution solve;  // 实例化
	string res = solve.minWindowStr("ADOBECODEBANC", "ABC");
	printf("%s\n", res.c_str());  // 强转

	res = solve.minWindowStr("MADOBCCABEC", "ABCC");
	printf("%s\n", res.c_str());

	res = solve.minWindowStr("aa", "aa");
	printf("%s\n", res.c_str());

	system("pause");
	return 0;
}