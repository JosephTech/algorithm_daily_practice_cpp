/*
设计一个计算器，输入一个字符串存储的数学表达式，可以计算包括 "("  ")"  "+"  "-"
四种符号的数学表达式，输入的数学表达式字符串保证是合法的。
输入的数学表达式中可能存在空格字符

如计算：
	"(1+1)" = 2
	"1+121-(14+(-6))" = 109
*/
#include <stdio.h>
#include <string>
#include <stack>

//传参数时候 传引用，因为stack可能非常非常大，直接传参数 会复制一份。
//而java里全部都是引用


// 1、	compute函数，传入两个stack的引用，operation_stack存加减号；number_stack存数字。
//		number_stack只剩一个数时候，直接返回
//		对number_stack栈顶的两个数字做'+' '-;运算。  运算后pop两个栈的栈顶

// number_stack栈顶的两个数字 做 运算后，push进number_stack
void compute(std::stack<int> &number_stack, 
			 std::stack<char> &operation_stack) { //传入 两个栈的引用。因为stack可能非常非常大
	// number_stack只剩一个数时候，返回
	// 此时operation_stack最多剩几个后括号 ')' 。  即在算式的最外圈套了几个没用的((......))
	if (number_stack.size() < 2) {
		return;
	}
	int num2 = number_stack.top(); // num2放后边 被加数 和 被减数。减法时候。  
	number_stack.pop();
	int num1 = number_stack.top();
	number_stack.pop();
	if (operation_stack.top() == '+') {
		number_stack.push(num1 + num2);
	}
	else if (operation_stack.top() == '-') {
		number_stack.push(num1 - num2);
	}
	operation_stack.pop(); //弹出 operator_stack的 运算符
}

// 工业上的处理字符串，都是用 【有限状态自动机】 的思想， 进行不同状态转换，然后在每个状态进行if else判断
// 直接强行全写if  else，代码很恶心，

// Solution类、三个状态、两个栈、 一个number、一个现在的状态、一个compute_flag 
class Solution {
public:
	int calculate(std::string s) {
		static const int STATE_BEGIN = 0; // 静态常整型
		static const int NUMBER_STATE = 1;
		static const int OPERATION_STATE = 2;
		std::stack<int> number_stack;
		std::stack<char> operation_stack; //字符型 栈
		int number = 0;
		int STATE = STATE_BEGIN;
		int compute_flag = 0;

		// 外圈循环指针i，指向字符串位置。 例如： " 1 + (2 + 3)"
		// （注意：此指针非彼指针。 这是指指向字符串的位置）
		for (int i = 0; i < s.length(); i++) { // 从0到s-1，共s个位置
			if (s[i] == ' ') {
				continue; // 遇到空格，进行下次for循环。 读下个i位置
			}
			// 有限状态自动机
			switch (STATE) {
			case STATE_BEGIN:
				// if0~9， 进NUMBER_STAGE、i退格
				if (s[i] >= '0' && s[i] <= '9') {
					STATE = NUMBER_STATE;
				}
				// 其它， 进OPERATION_STAGE、i退格
				else {
					STATE = OPERATION_STATE;
				}
				// i退格写外边。break这次switch
				i--;
				break;

			case NUMBER_STATE:
				// if 0~9, 一直×10累加
				if (s[i] >= '0' && s[i] <= '9') {
					number = 10 * number + s[i] - '0';
				}
				// 其它（空格、加、减）, number push到栈、 根据flag是否运算、i退格、number置零、跳state
				else {
					number_stack.push(number);
					if (compute_flag == 1) {
						compute(number_stack, operation_stack); // 算
					}
					i--; //i退格
					number = 0; //number置0
					STATE = OPERATION_STATE;
				}
				// break这次switch
				break;

			case OPERATION_STATE:
				// if遇到0~9。 换state、 i退格、 
				if (s[i] >= '0' && s[i] <= '9') {
					STATE = NUMBER_STATE;
					i--; // 每次换状态，都要i退格。  除了(换状态
				}

				// if遇到+-。  push到栈、flag置1。   加减不需要状态转换，下次i循环会遇到number
				else if (s[i] == '+' || s[i] == '-') {
					operation_stack.push(s[i]);
					compute_flag = 1;
				}

				// if遇到( 。  flag置0、换状态。  不退格
				else if (s[i] == '(') {
					compute_flag = 0;
					STATE = NUMBER_STATE;
				}

				// if遇到) 。  算
				else if (s[i] == ')') {
					compute(number_stack, operation_stack); 
					//  1+(2+3)。 其中，2+3在number_state已经算了一次了
					// 此次算的是 1 + 5 
				}
				// break此次switch
				break;
			}
		}
		// 这段不知道干啥的，我感觉 自动状态机已经算完了。
		if (number != 0) {
			number_stack.push(number);
			compute(number_stack, operation_stack);
		}
		// 没有输入算式。 例如 ' +   -'
		if (number == 0 && number_stack.empty()) {
			return 0;
		}
		return number_stack.top();
	}
};
 

int main() {
	std::string s = "1+121 - (14+(5-6) )";
	Solution solve;
	int result = solve.calculate(s);
	printf("result = %d\n", result);

	system("pause");
	return 0;
}

// 总结：这题应该不会让写，只会让写大概思路