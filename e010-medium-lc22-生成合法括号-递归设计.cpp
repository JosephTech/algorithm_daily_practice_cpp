/*
生成括号
题目：
	已知n组括号，开发一个程序，生成这n组括号所有的合法的组合可能。
	例如：n = 3
	结果为： ["((()))", "(()())", "(())()", "()(())", "()()()"]
	
*/
/*
思考：
n组括号，有多少种可能？

	n组括号，字符串长度2*n

	每个字符串是左括号(  或者右括号)
	所以共有2^(2n)种可能

例如：
	1组括号：2^2
		"(("   "))"  "()"  ")("
		左左，  右右， 左右， 右左

	2组括号，2^4
	"((((" ,  "((()",  "(())",  "(()("
	"()((" ,  "()()",  "()))",  "())("
	")(((",   ")(()",  ")())",  ")()("
	"))((",   "))()",  "))))",  ")))("
*/
/*
算法思路：
	在组成的所有可能中，哪些是合法的？
	1、左括号和右括号的数量不可超过n
	2、每放一个左括号，才可放一个右括号，即右括号不可先于左括号放置

故递归需要限制条件：
	1、左括号与右括号的数量，最多放置n个。
	2、若左括号的数量 <= 右括号的数量，不可进行放置右括号的递归。
*/

#include <iostream> //pause用的
#include <string> // 字符串 
#include <vector> // 向量

class Solution {
public:
	std::vector<std::string> generateParenthesis(int n) {
		std::vector<std::string> result; // 存放返回的结果
		generate("", n, n, result);
		return result;
	}
private:
	void generate(std::string item, //存放 括号字符串
					int left,  // 还能放几个left括号
					int right, // 还能放几个right括号
					std::vector<std::string> &result) {// 存放结果
		if (left == 0 && right == 0) { // 结束条件。 都不能放的时候
			result.push_back(item);
			return;
		}
		if (left > 0) { //还能放left括号的时候
			generate(item + '(', left - 1, right, result); //递归调用
		}
		if (left < right) { // 当还能放右括号的时候。注意先放左括号，所以 可放左括号left < 可放右括号right
			generate(item + ')', left, right - 1, result);
		}
	}
};

int main() {
	//实例化、调用函数
	Solution solve;
	std::vector<std::string> result = solve.generateParenthesis(3);

	//打印
	for (int i = 0; i < result.size(); i++) {
		printf("%s\n", result[i].c_str());
	}

	system("pause");
	return 0;
}