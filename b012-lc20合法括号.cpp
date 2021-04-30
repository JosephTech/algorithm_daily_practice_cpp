/*
��Ŀ��
����һ���ַ�����
()[]{}ֻ���������ַ���
��Ϸ���
*/

#include <iostream>
#include <stack>  // ջ��������
#include <string>
using namespace std;

class Solution {
public:
	bool validParentheses(string str) {  // ��Ч������
		if (str.length() == 0)
			return false;
		stack<char> S;
		S.push(str[0]);  // ѹ�� ��0��
		for (int i = 1; i < str.length(); i++) {  // ���������ŷ���ջ�У����������űȽ���һ��char��ջ�������Ⱦ�return false
			if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
				S.push(str[i]);
			}
			else {  // ����������
				if (S.empty())
					return false;  // �߽硣û�ˣ�˵��str��������ʣ��
				
				char c = S.top();
				if ((c == '(' && str[i] == ')') ||
					(c == '{' && str[i] == '}') ||
					(c == '[' && str[i] == ']')) { // ƥ��
					S.pop();  // ��ջ
				}else {
					return false;  // ��ƥ��
				}
			}
		}
		return S.empty();  // ���ˣ�����true��  ���գ�˵��ʣ��
	}
};


int main() {
	string str = "({}[])";

	Solution solve; //ʵ����
	printf("%d\n", solve.validParentheses(str));

	system("pause");
	return 0;
}