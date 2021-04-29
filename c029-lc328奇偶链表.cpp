#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;  // ��ַ��
	ListNode(int x):val(x), next(NULL) {}  // ���캯��
};

class Solution {
public:
	ListNode* oddEvenList(ListNode *head) {  // ����ͷ�ڵ�
		if (!head)
			return NULL;
		if (!head->next)
			return head;  // ֻ��һ���ڵ㡣 �����п��Բ�д���ߵ����returnҲһ��

		ListNode *dummyOdd = new ListNode(0);
		ListNode *dummyEven = new ListNode(0);  // ��������

		ListNode *cur = head;  // �ɶ���
		ListNode *p_odd = dummyOdd, *q_even = dummyEven;  // �ֱ�����ָ�롢żָ��
		int cnt = 1;  // �����ģ�����ż������ǰcur���ĸ�λ��
		while (cur) {
			if (cnt % 2 == 1) { // ����
				p_odd->next = cur;  // ����
				p_odd = p_odd->next;  // ��һ��
			}
			else {
				q_even->next = cur;  // ����
				q_even = q_even->next;  // ��һ��
			}
			cur = cur->next;  //��һ��
			cnt += 1;  //����
		}
		q_even->next = NULL;  //ż����β ��ΪNULL
		p_odd->next = dummyEven->next;  // ����ż����ͷ

		ListNode *retNode = dummyOdd->next;
		delete dummyOdd;
		delete dummyEven;  // �����ڴ�
		
		return retNode;  //����
	}
};

int main() {
	ListNode a(1), b(2), c(3), d(4), e(5), f(6);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;


	Solution solve;  // ʵ����
	ListNode *head = solve.oddEvenList(&a);

	while (head) {
		printf("%d\n", head->val);
		head = head->next;
	}

	system("pause");
	return 0;
}