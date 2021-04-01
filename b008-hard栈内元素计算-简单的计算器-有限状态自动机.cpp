/*
���һ��������������һ���ַ����洢����ѧ���ʽ�����Լ������ "("  ")"  "+"  "-"
���ַ��ŵ���ѧ���ʽ���������ѧ���ʽ�ַ�����֤�ǺϷ��ġ�
�������ѧ���ʽ�п��ܴ��ڿո��ַ�

����㣺
	"(1+1)" = 2
	"1+121-(14+(-6))" = 109
*/
#include <stdio.h>
#include <string>
#include <stack>

//������ʱ�� �����ã���Ϊstack���ܷǳ��ǳ���ֱ�Ӵ����� �Ḵ��һ�ݡ�
//��java��ȫ����������


// 1��	compute��������������stack�����ã�operation_stack��Ӽ��ţ�number_stack�����֡�
//		number_stackֻʣһ����ʱ��ֱ�ӷ���
//		��number_stackջ��������������'+' '-;���㡣  �����pop����ջ��ջ��

// number_stackջ������������ �� �����push��number_stack
void compute(std::stack<int> &number_stack, 
			 std::stack<char> &operation_stack) { //���� ����ջ�����á���Ϊstack���ܷǳ��ǳ���
	// number_stackֻʣһ����ʱ�򣬷���
	// ��ʱoperation_stack���ʣ���������� ')' ��  ������ʽ������Ȧ���˼���û�õ�((......))
	if (number_stack.size() < 2) {
		return;
	}
	int num2 = number_stack.top(); // num2�ź�� ������ �� ������������ʱ��  
	number_stack.pop();
	int num1 = number_stack.top();
	number_stack.pop();
	if (operation_stack.top() == '+') {
		number_stack.push(num1 + num2);
	}
	else if (operation_stack.top() == '-') {
		number_stack.push(num1 - num2);
	}
	operation_stack.pop(); //���� operator_stack�� �����
}

// ��ҵ�ϵĴ����ַ����������� ������״̬�Զ����� ��˼�룬 ���в�ͬ״̬ת����Ȼ����ÿ��״̬����if else�ж�
// ֱ��ǿ��ȫдif  else������ܶ��ģ�

// Solution�ࡢ����״̬������ջ�� һ��number��һ�����ڵ�״̬��һ��compute_flag 
class Solution {
public:
	int calculate(std::string s) {
		static const int STATE_BEGIN = 0; // ��̬������
		static const int NUMBER_STATE = 1;
		static const int OPERATION_STATE = 2;
		std::stack<int> number_stack;
		std::stack<char> operation_stack; //�ַ��� ջ
		int number = 0;
		int STATE = STATE_BEGIN;
		int compute_flag = 0;

		// ��Ȧѭ��ָ��i��ָ���ַ���λ�á� ���磺 " 1 + (2 + 3)"
		// ��ע�⣺��ָ��Ǳ�ָ�롣 ����ָָ���ַ�����λ�ã�
		for (int i = 0; i < s.length(); i++) { // ��0��s-1����s��λ��
			if (s[i] == ' ') {
				continue; // �����ո񣬽����´�forѭ���� ���¸�iλ��
			}
			// ����״̬�Զ���
			switch (STATE) {
			case STATE_BEGIN:
				// if0~9�� ��NUMBER_STAGE��i�˸�
				if (s[i] >= '0' && s[i] <= '9') {
					STATE = NUMBER_STATE;
				}
				// ������ ��OPERATION_STAGE��i�˸�
				else {
					STATE = OPERATION_STATE;
				}
				// i�˸�д��ߡ�break���switch
				i--;
				break;

			case NUMBER_STATE:
				// if 0~9, һֱ��10�ۼ�
				if (s[i] >= '0' && s[i] <= '9') {
					number = 10 * number + s[i] - '0';
				}
				// �������ո񡢼ӡ�����, number push��ջ�� ����flag�Ƿ����㡢i�˸�number���㡢��state
				else {
					number_stack.push(number);
					if (compute_flag == 1) {
						compute(number_stack, operation_stack); // ��
					}
					i--; //i�˸�
					number = 0; //number��0
					STATE = OPERATION_STATE;
				}
				// break���switch
				break;

			case OPERATION_STATE:
				// if����0~9�� ��state�� i�˸� 
				if (s[i] >= '0' && s[i] <= '9') {
					STATE = NUMBER_STATE;
					i--; // ÿ�λ�״̬����Ҫi�˸�  ����(��״̬
				}

				// if����+-��  push��ջ��flag��1��   �Ӽ�����Ҫ״̬ת�����´�iѭ��������number
				else if (s[i] == '+' || s[i] == '-') {
					operation_stack.push(s[i]);
					compute_flag = 1;
				}

				// if����( ��  flag��0����״̬��  ���˸�
				else if (s[i] == '(') {
					compute_flag = 0;
					STATE = NUMBER_STATE;
				}

				// if����) ��  ��
				else if (s[i] == ')') {
					compute(number_stack, operation_stack); 
					//  1+(2+3)�� ���У�2+3��number_state�Ѿ�����һ����
					// �˴������ 1 + 5 
				}
				// break�˴�switch
				break;
			}
		}
		// ��β�֪����ɶ�ģ��Ҹо� �Զ�״̬���Ѿ������ˡ�
		if (number != 0) {
			number_stack.push(number);
			compute(number_stack, operation_stack);
		}
		// û��������ʽ�� ���� ' +   -'
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

// �ܽ᣺����Ӧ�ò�����д��ֻ����д���˼·