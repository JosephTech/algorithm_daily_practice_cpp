/*
ɾ������ ������N���ڵ㣬
*/
/*
˼·��
˫ָ�뷨
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
	ListNode* removeNode(ListNode *head, int N) {  // ɾ������ ��N���ڵ㡣 ��Ϊͷ�ڵ���ܱ�ɾ��������Ҫ�з���ֵ
		ListNode *dummyHead = new ListNode(0);
		dummyHead->next = head;  //����

		ListNode *l = dummyHead, *r = dummyHead;

		// ǰ�᣺ ��Ŀ����N<=������
		assert(N >= 0);
		for (int i = 0; i < N + 1; i++) {  // ����N+1��
			assert(r);
			r = r->next;
		}
		while (r) {  // r��NULLʱ��, ����һ��
			l = l->next;
			r = r->next;
		}
		l->next = l->next->next; // ��Ծ����,  (Ҳ�����ȼ�¼����delete������vs2015����)

		ListNode* retNode = dummyHead->next;
		delete dummyHead;  // �����ڴ�
		return retNode;  // ���أ� ��retNode=NULL���ͷ��ص���NULL
	}
};

int main() {
	ListNode a(10), b(20), c(30), d(40), e(50), f(60);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;

	Solution solve;  //ʵ����
	solve.removeNode(&a, 6);

	ListNode* head = &a;
	while (head) {
		printf("%d\n", head->val);
		head = head->next;
	}

	system("pause");
	return 0;
}