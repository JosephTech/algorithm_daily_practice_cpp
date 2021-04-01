/*
���һ�����У�֧�ֶ��еĻ������������е��ڲ��洢���ݵĽṹΪջ��
ջ�ķ���ֻ�ܰ���top/pop/size/empty/push�ȷ���

push(x)  ��Ԫ��xѹ�������
pop()    ��������ͷ��Ԫ��
peek()   ���ض���ͷ��Ԫ�أ���front��
empty()  �ж϶����Ƿ�Ϊ��
*/
#include <stdio.h>
#include <stack>

class MyQueue{
public:
	MyQueue() { // ���캯��
	}

	void push(int x) {
		std::stack<int> temp_stack;
		while ( !_data.empty() ) {
			temp_stack.push(_data.top()); // �ϵ�1 ������ʱջ�ײ��� ���ᵹ����
			_data.pop();
		}
		temp_stack.push(x); //�µ�5������ʱջtemp_stackջ���� ����Ҫ������
		while (!temp_stack.empty()) {
			_data.push(temp_stack.top()); 
			// �µ�5����_dataջ�ס� ������β
			// �ϵ�1����.....ջ���� ������ͷ
			temp_stack.pop();
		}
	}

	int pop() {
		int x = _data.top();
		_data.pop();
		return x;
	}

	int peek() {
		return _data.top();
	}

	bool empty() {
		return _data.empty();
	}
private:
	std::stack<int> _data; // _data��ջ��ջ�����Ƕ���ͷ��Ԫ�أ����ϵ�Ԫ�أ�
};

int main() {
	MyQueue Q;
	Q.push(1);
	Q.push(2);
	Q.push(3);
	Q.push(4);
	printf("Q.peek = %d\n", Q.peek()); // 1
	Q.pop();
	printf("Q.peek = %d\n", Q.peek()); //2
	system("pause");
	return 0;
}