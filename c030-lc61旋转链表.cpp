#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;  // ָ����
	ListNode(int x):val(x), next(NULL) {}  // ���캯��
};

class Solution {
public:
	ListNode *rotateList(ListNode *head, int k) {  // k���ܱ������ܶ�
		if (!head)
			return NULL;
		ListNode *cur = head;
		int len = 0;
		while (cur) {
			len += 1;  // ��ǰ�ڵ� ����
			cur = cur->next;  // ��һ���ڵ�
		}
		k = k % len;  // ����k����С��������
		if (k == 0)
			return head;  // ˵��û�б䣬�糤��5����ת5

		ListNode *p = head, *q = head;
		for (int i = 0; i < k; i++) {  // ����k��
			q = q->next;
		}
		
		while(q->next){  // �ж�next��������q�ߵ����һ���ڵ��ͣ��
			p = p->next;
			q = q->next;
		}  // qͣ�����һ���ڵ㣬pͣ�ڵ���k+1���ڵ�
		
		ListNode *new_head = p->next;  // ��¼��ͷ
		p->next = NULL;  // �Ͽ�
		q->next = head;  //β������ͷ
		
		return new_head;
	}
};

int main() {
	ListNode a(10), b(20), c(30), d(40), e(50);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;

	Solution solve;  //ʵ����
	ListNode *head = solve.rotateList(&a, 7);

	while (head) {
		printf("%d\n", head->val);
		head = head->next;
	}
	system("pause");
	return 0;
}