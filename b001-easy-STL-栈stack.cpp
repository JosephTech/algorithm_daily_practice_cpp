/*
预备知识
栈(栈顶、栈底)：  先进后出  的线性表
堆（队头）：  先进先出  的线性表

push操作
pop操作
*/
/*
s.push()   压入栈中
s.pop()    弹出栈顶
s.empty()  判断栈是否为空
s.size()   栈存储的元素个数
s.top()    取出栈顶
*/
#include <stdio.h>
#include <stack>
int main() {
	std::stack<int> s;
	if (s.empty()) {
		printf("s is empty \n"); //? 输出这句话
	}
	s.push(5);
	s.push(6);
	s.push(10);//?
	printf("s.top = %d\n", s.top()); // 10

	s.pop();
	s.pop();//?
	printf("s.top = %d\n", s.top()); // 5
	printf("s.size = %d\n", s.size()); // 1

	system("pause");
	return 0;
}