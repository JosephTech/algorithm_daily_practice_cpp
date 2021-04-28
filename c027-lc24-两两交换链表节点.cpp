/*
lc24
��Ŀ��
����һ�飬��������ڵ�
*/
#include <iostream>  // pause
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x):val(x), next(NULL) {}  // ���캯��
};

class Solution {
public:
	ListNode *swapNodeInPairs(ListNode *head) {  // ����ͷ�ڵ�
		ListNode *dummyHead = new ListNode(0);
		dummyHead->next = head;
		ListNode *p = dummyHead;

		while (p->next && p->next->next) {  // ��󣬼���ʣ1���ڵ㣬�Ͳ�����
			ListNode *node1 = p->next;
			ListNode *node2 = node1->next;
			ListNode *next = node2->next;  // ��¼�����ڵ�

			p->next = node2;
			node2->next = node1;
			node1->next = next;  // ����

			p = node1;  // �ƶ�p��������һ��ѭ��
		}
		ListNode *retNode = dummyHead->next;
		delete dummyHead;  // ��������ڴ�
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

	Solution solve;  // ʵ����
	ListNode *head = solve.swapNodeInPairs(&a);

	while (head) {
		printf("%d\n", head->val);
		head = head->next;
	}

	system("pause");
	return 0;
}