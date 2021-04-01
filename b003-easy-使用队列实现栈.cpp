/*
设计一个栈，支持基本的栈操作，这个栈内部存储数据的结构为队列，队列的方法只能
包括push、peek(front)、pop、size、empty等标准的队列方法

1、push() 将元素x压入栈中
2、pop()  弹出（移除）栈顶元素
3、top()  返回栈顶元素
4、empty() 判断栈是否为空
*/
#include <stdio.h>
#include <queue>

class MyStack {
public:
	MyStack() { //构造函数
	}
	void push(int x) { 
		std::queue<int> temp_queue; // 临时队列。 利用该队列进行 次序调换。（就是把x放在队列头）
		temp_queue.push(x); // 放在 临时队列头
		while ( !_data.empty()) {  // 不空
			temp_queue.push(_data.front()); // 就把_data头 推到 临时队列
			_data.pop(); // 弹出_data头
		}
		//把临时队列，挨个放到 _data中
		while (!temp_queue.empty()) { // 不空
			_data.push(temp_queue.front());  // 就把 临时队列头 推到 _data
			temp_queue.pop(); //弹出 临时队列头
		}
	}

	int pop() {
		int x = _data.front(); // 取出栈顶元素，即取出队列头部元素
		_data.pop(); // 弹出队列头部元素
		return x; // 返回队列头部元素x，  作为栈顶元素
	}
	int top() {
		return _data.front(); // 返回队列头部。  作为返回栈顶元素
	}
	bool empty() {
		return _data.empty();
	}
private:
	std::queue<int> _data; // _data里边存的是 栈存储元素的顺序
	// 把新元素添加到_data_queue的头部即可
};


int main() {
	MyStack S;
	S.push(1);
	S.push(2);
	S.push(3);
	S.push(4);
	printf("S.top = %d\n", S.top()); // 4
	S.pop();
	printf("S.top = %d\n", S.top()); // 3
	S.push(5);
	printf("S.top = %d\n", S.top()); // 5
	system("pause");
	return 0;
}
