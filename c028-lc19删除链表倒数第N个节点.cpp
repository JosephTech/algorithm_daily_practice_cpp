/*
删除链表 倒数第N个节点，
*/
/*
思路：
双指针法
*/
#include<iostream>
#include<assert.h>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNode(ListNode *head, int N) {  // 删除倒数 第N个节点。 因为头节点可能被删除，所以要有返回值
		ListNode *dummyHead = new ListNode(0);
		dummyHead->next = head;  //连上

		ListNode *l = dummyHead, *r = dummyHead;

		// 前提： 题目给了N<=链表长度
		assert(N >= 0);
		for (int i = 0; i < N + 1; i++) {  // 先走N+1步
			assert(r);
			r = r->next;
		}
		while (r) {  // r不NULL时候, 各走一步
			l = l->next;
			r = r->next;
		}
		l->next = l->next->next; // 跳跃连接,  (也可以先记录，在delete，但是vs2015报错)

		ListNode* retNode = dummyHead->next;
		delete dummyHead;  // 管理内存
		return retNode;  // 返回， 若retNode=NULL，就返回的是NULL
	}
};

int main() {
	ListNode a(10), b(20), c(30), d(40), e(50), f(60);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;

	Solution solve;  //实例化
	solve.removeNode(&a, 6);

	ListNode* head = &a;
	while (head) {
		printf("%d\n", head->val);
		head = head->next;
	}

	system("pause");
	return 0;
}