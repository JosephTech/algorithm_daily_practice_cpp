#include <iostream>  // pause
#include <string>
using namespace std;

class Solution {
public:
	string minWindowStr(string s, string t) {  // s�ǳ����� t�Ƕ̴�
		const int LENTH = 128;
		int map_s[LENTH] = {0};  // �ַ���ϣ������
		int map_t[LENTH] = {0};  // �ַ���ϣ�� ����
		for (int i = 0; i < t.length(); i++)
			map_t[t[i]]++;  // ����
		int win_begin = 0; // ָ�룬window_begin
		string result = "";
		for (int i = 0; i < s.length(); i++) {  // i �Ǵ��ڽ�����  ����ұ�
			map_s[s[i]]++;  // ������ ע�⣬һ��Ҫ��ʱ�� ����Ū������ָ��ǰ��ʱ�򣬼���s��
			while (win_begin < i) {  // ��Ϊwin_beginҪ++,������<  ����С�ڵ���
				if (map_t[s[win_begin]] == 0)  // t��û�е��ַ���
					win_begin++;
				else if (map_s[s[win_begin]] > map_t[s[win_begin]]) {  // s���ַ���
					map_s[s[win_begin]]--;
					win_begin++;  // ������ ���úϣ� ����
				}
				else
					break;  // ˵�� �Ǹ����ڣ���һ�����´���
			}
			int len_of_substr = i - win_begin + 1; // ����ұ�
			if (is_window_ok(map_s, map_t)) {
				if (result == "" || len_of_substr < result.length()) {
					result = s.substr(win_begin, len_of_substr);
				}
			}
		}
		return result;
	}

private:
	bool is_window_ok(int map_s[], int map_t[]) {  // �����ַ��� ���ַ���ϣ�������������ַ���s �Ƿ����t��ÿ���ַ�
		for (int i = 0; i < 128; i++) {
			if (map_s[i] < map_t[i])  // ��t�� ĳ�ַ�����
				return false;
		}
		return true;
	}
};

int main() {
	Solution solve;  // ʵ����
	string res = solve.minWindowStr("ADOBECODEBANC", "ABC");
	printf("%s\n", res.c_str());  // ǿת

	res = solve.minWindowStr("MADOBCCABEC", "ABCC");
	printf("%s\n", res.c_str());

	res = solve.minWindowStr("aa", "aa");
	printf("%s\n", res.c_str());

	system("pause");
	return 0;
}