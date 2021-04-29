#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;  // 指针域
	ListNode(int x):val(x), next(NULL) {}  // 构造函数
};

class Solution {
public:
	ListNode *rotateList(ListNode *head, int k) {  // k可能比链表长很多
		if (!head)
			return NULL;
		ListNode *cur = head;
		int len = 0;
		while (cur) {
			len += 1;  // 当前节点 计数
			cur = cur->next;  // 下一个节点
		}
		k = k % len;  // 更新k，让小于链表长度
		if (k == 0)
			return head;  // 说明没有变，如长度5，旋转5

		ListNode *p = head, *q = head;
		for (int i = 0; i < k; i++) {  // 先走k步
			q = q->next;
		}
		
		while(q->next){  // 判断next，着这样q走到最后一个节点就停了
			p = p->next;
			q = q->next;
		}  // q停在最后一个节点，p停在倒数k+1个节点
		
		ListNode *new_head = p->next;  // 记录新头
		p->next = NULL;  // 断开
		q->next = head;  //尾巴连上头
		
		return new_head;
	}
};

int main() {
	ListNode a(10), b(20), c(30), d(40), e(50);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;

	Solution solve;  //实例化
	ListNode *head = solve.rotateList(&a, 7);

	while (head) {
		printf("%d\n", head->val);
		head = head->next;
	}
	system("pause");
	return 0;
}