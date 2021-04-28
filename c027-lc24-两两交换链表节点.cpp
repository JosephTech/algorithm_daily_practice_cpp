/*
lc24
题目：
两个一组，交换链表节点
*/
#include <iostream>  // pause
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x):val(x), next(NULL) {}  // 构造函数
};

class Solution {
public:
	ListNode *swapNodeInPairs(ListNode *head) {  // 传入头节点
		ListNode *dummyHead = new ListNode(0);
		dummyHead->next = head;
		ListNode *p = dummyHead;

		while (p->next && p->next->next) {  // 最后，假如剩1个节点，就不换了
			ListNode *node1 = p->next;
			ListNode *node2 = node1->next;
			ListNode *next = node2->next;  // 记录三个节点

			p->next = node2;
			node2->next = node1;
			node1->next = next;  // 连接

			p = node1;  // 移动p，继续下一轮循环
		}
		ListNode *retNode = dummyHead->next;
		delete dummyHead;  // 管理堆区内存
		return retNode;
	}
};

int main() {
	ListNode a(10), b(20), c(30), d(40), e(50), f(60), g(70);

	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	f.next = &g;

	Solution solve;  // 实例化
	ListNode *head = solve.swapNodeInPairs(&a);

	while (head) {
		printf("%d\n", head->val);
		head = head->next;
	}

	system("pause");
	return 0;
}