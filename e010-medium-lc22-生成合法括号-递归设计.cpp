/*
��������
��Ŀ��
	��֪n�����ţ�����һ������������n���������еĺϷ�����Ͽ��ܡ�
	���磺n = 3
	���Ϊ�� ["((()))", "(()())", "(())()", "()(())", "()()()"]
	
*/
/*
˼����
n�����ţ��ж����ֿ��ܣ�

	n�����ţ��ַ�������2*n

	ÿ���ַ�����������(  ����������)
	���Թ���2^(2n)�ֿ���

���磺
	1�����ţ�2^2
		"(("   "))"  "()"  ")("
		����  ���ң� ���ң� ����

	2�����ţ�2^4
	"((((" ,  "((()",  "(())",  "(()("
	"()((" ,  "()()",  "()))",  "())("
	")(((",   ")(()",  ")())",  ")()("
	"))((",   "))()",  "))))",  ")))("
*/
/*
�㷨˼·��
	����ɵ����п����У���Щ�ǺϷ��ģ�
	1�������ź������ŵ��������ɳ���n
	2��ÿ��һ�������ţ��ſɷ�һ�������ţ��������Ų������������ŷ���

�ʵݹ���Ҫ����������
	1���������������ŵ�������������n����
	2���������ŵ����� <= �����ŵ����������ɽ��з��������ŵĵݹ顣
*/

#include <iostream> //pause�õ�
#include <string> // �ַ��� 
#include <vector> // ����

class Solution {
public:
	std::vector<std::string> generateParenthesis(int n) {
		std::vector<std::string> result; // ��ŷ��صĽ��
		generate("", n, n, result);
		return result;
	}
private:
	void generate(std::string item, //��� �����ַ���
					int left,  // ���ܷż���left����
					int right, // ���ܷż���right����
					std::vector<std::string> &result) {// ��Ž��
		if (left == 0 && right == 0) { // ���������� �����ܷŵ�ʱ��
			result.push_back(item);
			return;
		}
		if (left > 0) { //���ܷ�left���ŵ�ʱ��
			generate(item + '(', left - 1, right, result); //�ݹ����
		}
		if (left < right) { // �����ܷ������ŵ�ʱ��ע���ȷ������ţ����� �ɷ�������left < �ɷ�������right
			generate(item + ')', left, right - 1, result);
		}
	}
};

int main() {
	//ʵ���������ú���
	Solution solve;
	std::vector<std::string> result = solve.generateParenthesis(3);

	//��ӡ
	for (int i = 0; i < result.size(); i++) {
		printf("%s\n", result[i].c_str());
	}

	system("pause");
	return 0;
}