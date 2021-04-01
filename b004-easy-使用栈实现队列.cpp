/*
设计一个队列，支持队列的基本操作，队列的内部存储数据的结构为栈，
栈的方法只能包括top/pop/size/empty/push等方法

push(x)  将元素x压入队列中
pop()    弹出队列头部元素
peek()   返回队列头部元素（即front）
empty()  判断队列是否为空
*/
#include <stdio.h>
#include <stack>

class MyQueue{
public:
	MyQueue() { // 构造函数
	}

	void push(int x) {
		std::stack<int> temp_stack;
		while ( !_data.empty() ) {
			temp_stack.push(_data.top()); // 老的1 放在临时栈底部， 待会倒过来
			_data.pop();
		}
		temp_stack.push(x); //新的5放在临时栈temp_stack栈顶， 待会要倒过来
		while (!temp_stack.empty()) {
			_data.push(temp_stack.top()); 
			// 新的5放在_data栈底。 即队列尾
			// 老的1。。.....栈顶。 即队列头
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
	std::stack<int> _data; // _data是栈，栈顶部是队列头的元素（最老的元素）
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