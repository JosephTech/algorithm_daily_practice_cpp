/*
预备知识：
STL queue队列
*/
/*
Q.empty()  判断队列是否为空
Q.front()  返回队列头部元素
Q.back()   返回队列尾部元素
Q.pop()		弹出队头元素
Q.push()   压到队尾
Q.size()   返回队列 储存元素的个数
*/

#include <stdio.h>
#include <queue>
int main() {
	std::queue<int> Q; // 新建一个Q队列
	if (Q.empty()) {
		printf("Q is empty! \n");
	}
	Q.push(5); //?
	Q.push(6);
	Q.push(10);
	printf("Q.front = %d\n", Q.front()); //5
	Q.pop();
	Q.pop();//?
	printf("Q.front = %d\n", Q.front()); //10
	Q.push(1); //?
	printf("Q.back = %d\n", Q.back()); //1
	printf("Q.size = %d\n", Q.size()); //2


	system("pause");
	return 0;
}