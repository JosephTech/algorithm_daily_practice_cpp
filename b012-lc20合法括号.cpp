/*
题目：
传入一个字符串，
()[]{}只有这六个字符，
求合法否？
*/

#include <iostream>
#include <stack>  // 栈，先入后出
#include <string>
using namespace std;

class Solution {
public:
	bool validParentheses(string str) {  // 无效的括号
		if (str.length() == 0)
			return false;
		stack<char> S;
		S.push(str[0]);  // 压入 第0个
		for (int i = 1; i < str.length(); i++) {  // 遇到左括号放入栈中，遇到右括号比较下一个char和栈顶，不等就return false
			if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
				S.push(str[i]);
			}
			else {  // 遇到右括号
				if (S.empty())
					return false;  // 边界。没了，说明str有右括号剩余
				
				char c = S.top();
				if ((c == '(' && str[i] == ')') ||
					(c == '{' && str[i] == '}') ||
					(c == '[' && str[i] == ']')) { // 匹配
					S.pop();  // 弹栈
				}else {
					return false;  // 不匹配
				}
			}
		}
		return S.empty();  // 空了，返回true。  不空，说明剩余
	}
};


int main() {
	string str = "({}[])";

	Solution solve; //实例化
	printf("%d\n", solve.validParentheses(str));

	system("pause");
	return 0;
}