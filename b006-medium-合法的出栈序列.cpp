/*
题目：
	已知从1至n的数字序列， 按顺序入栈， 
	每个数字入栈后即可出栈，
	也可在栈中停留，等待后面数字入栈出栈后，该数字再出栈
	求该数字的出栈序列是否合法
*/

#include <iostream>
using namespace std;
#include <stack>
#include <queue>
#pragma warning(disable:4996) //防止scanf报错

// 判断传入的 队列中元素的顺序  是否合法（符合栈）
bool check_is_valid_order(std::queue<int> queue_order) { //传入一个队列，里边是一个顺序
	//创建栈 S。  用于存1~n
	std::stack<int> S; // S为模拟栈
	int n = queue_order.size();

	// 把1~n push到栈里。每push一次后，用while判断 S栈顶 和 queue_order的队列头  是否相同，相同则弹出
	for (int i = 1; i <= n; i++) { //从1开始，取到n
		S.push(i);
		while (!S.empty() && S.top()==queue_order.front()) {
			S.pop();
			queue_order.pop();
		}
	}
	if (!S.empty()) { // 消消乐。 只有queue_order和S中的相同元素，才会一同pop。S剩的有（栈不为空），则queue_order也必剩的有
		return false;
	}
	return true;
} //算法整体复杂度O(n) ，因为所有元素只入栈出栈一次。 （虽然一个队列一个栈，但是成对消消乐的，不是n*n循环的）

// poj测试与提交
int main() {
	int n; // n=5,代表有5个元素
	int train;

	printf("请输入元素个数（0返回）：\n");
	scanf("%d", &n); //读取从键盘输入的数据
	printf("请输入元素队列（请用空格分隔）（0返回）：\n");
	while (n) {
		scanf("%d", &train); //读一个元素，就push到order中
		while (train) {
			std::queue<int> order;
			order.push(train);
			for (int i = 1; i < n; i++) { //再push n-1个元素 push到order中。一共push了n个元素
				scanf("%d", &train);
				order.push(train);
			}
			// check_is_valid_order，如果是yes，则打印yes，如果是no，则打印no
			if (check_is_valid_order(order)) {
				printf("Yes\n");
			}
			else {
				printf("No\n");
			}
			printf("请输入元素队列（请用空格分隔）（0返回）~：\n");
			scanf("%d", &train); //遇到0,则break while循环
		}
		printf("\n请输入元素个数（0返回）：\n");
		scanf("%d", &n); //遇到0,则break while循环
		printf("\n请输入元素队列（请用空格分隔）（0返回）~~：\n");
	}

	system("pause");
	return 0;
}
// 注意：poj用的是std::in和std::out文件输入输出。  文件一行行输入，输出存在文件里，再写到文件里
// 不用操心，这样提交，就对了