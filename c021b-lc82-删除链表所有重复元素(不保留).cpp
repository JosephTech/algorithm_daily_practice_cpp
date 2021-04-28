/*
��Ŀ��ɾ�������� �����ظ�Ԫ�أ�������

��������ͷ�ڵ�ָ��
*/
#include <iostream>  // pause
using namespace std;

struct ListNode {
	int val;  // ������
	ListNode* next;  // ָ����
	ListNode(int x): val(x), next(NULL) {}  //���캯��
};


class Solution {
public:
	ListNode *removeDuplicates(ListNode* head) {  // ����ͷ�ڵ�ָ�룬�Ƴ������ظ�Ԫ��
		ListNode *dummyHead = new ListNode(0);  // 0Ҳ�У�-1Ҳ�У�������������������
		dummyHead->next = head;  // ����
		ListNode *cur = dummyHead;  // �ɶ�
		ListNode *pre = dummyHead;  // ǰ��
		while (cur) {  // cur���յ�ʱ��
			if (cur->next && cur->val == cur->next->val) {  // next����NULL����ֵ���
				while (cur->next && cur->val == cur->next->val)  // next����null ����� ,�ƶ�cur���ظ�Ԫ�ؽ�β
					cur = cur->next;
				cur = cur->next;  // ����
				pre->next = cur;  // ����
			}
			else {  // next��NULL������ �����
				pre = cur;  // ��ǰ���ǰ��
				cur = cur->next;  // �ƶ���ǰ���ƶ���next������next��NULL�������ȥ��һ��while��
			}
		}
		ListNode *retNode = dummyHead->next;  // ��¼
		delete dummyHead;  // �����ڴ�
		return retNode;
	}
};

int main() {
	ListNode a(1), b(1), c(2), d(3), e(3), f(3), g(4), h(5), x(6), y(6);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	f.next = &g;
	g.next = &h;
	h.next = &x;
	x.next = &y;

	Solution solve; // ʵ����
	ListNode *head = solve.removeDuplicates(&a);

	while (head) {
		printf("%d\n", head->val);
		head = head->next;
	}

	system("pause");
	return 0;
}