/*
设计一个栈，支持如下操作，这些操作的算法复杂度应该是常数级，O(1)级

push(x)  将元素x压入栈中
pop()	 弹出（移除）栈顶元素
top()	 返回栈顶元素
getMin() 返回栈内最小元素
*/
/*
思路：
	O(1)级 算法复杂度，肯定不能用遍历，不能做临时排序，那样一般是O(n)级

	（请看PPT）
	一个变量MIN无法记录所有状态的最小值，（例如：最小值(等于MIN)在栈顶，pop()弹出了最小值，但是MIN无法更新）
	
	所以，栈的每个状态，都需要一个变量记录最小值。可以再整一个辅助栈
*/
/*
再弄一个栈，存储各个状态最小值的栈：
	1、栈为空，直接入栈（数据栈、最小值栈）。top()返回数据栈栈顶，getMin()返回最小值栈栈顶
		比如入栈：-2
	2、新入栈数据 放在 数据栈的栈顶。 （新数据和最小值比）较小的值放在 最小值栈的栈顶
		入栈0，则数据栈【0、-2】  ，最小值栈【-2，-2】
		再入栈-5， 则数据栈【-5、0、-2】， 最小值栈【-5、-2、-2】
	pop()弹出数据栈 栈顶；
	getMin()弹出最小值栈 栈顶
*/
/*
用空间换取时间的方法：
	个人理解：用内存中的空间，换取算法复杂度。（  把O(n)降低为O(1) ）
*/
#include <stdio.h>
#include <stack>

class MinStack {
public:
	//构造函数
	MinStack() {
	}
	// push函数
	void push(int x) {
		_data.push(x);
		// 若_min空的， 则_min.push(x)  
		if (_min.empty() ) {
			_min.push(x);
		}
		// 若x 大于 _min的栈顶， 则_min.top()赋值给x
		else{
			if (x > _min.top()) {
				x = _min.top();
			}
			_min.push(x); //此时，x为  x和最小值栈栈顶 中较小的。即所有元素的最小值
		}
	}
	// pop函数
	void pop() {
		_data.pop();
		_min.pop();
	}
	// top函数
	int top() {
		return _data.top();
	}
	// getMin函数
	int getMin() {
		return _min.top();
	}

private:
	std::stack<int> _data; // 数据栈     （普通的栈）
	std::stack<int> _min;  // 最小值栈。（存储当前状态最小值，即该位置放着数据栈所有元素的最小值）
};

int main() {
	MinStack ms;
	ms.push(-2);
	ms.push(0);
	printf("数据栈top = %d\n", ms.top()); // 0
	printf("最小值栈top = %d\n", ms.getMin()); // -2

	printf("==========================\n");

	ms.push(-5);
	printf("数据栈top = %d\n", ms.top()); // -5
	printf("最小值栈top = %d\n", ms.getMin()); // -5

	printf("===========================\n");

	ms.pop();
	printf("数据栈top = %d\n", ms.top()); // 0
	printf("最小值栈top = %d\n", ms.getMin()); // -2

	system("pause");
	return 0;
}