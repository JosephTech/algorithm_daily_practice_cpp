/*
�������������������ǵĽ���

���ӣ�
	a1 -> a2 -> a3->

	b1 -> b2 ->       c1 -> c2 -> c3
*/
/*
˼·��
	���� ���ƶ���ָ��l1��l2
	�ƶ���β��  ����һ�����ͷ������

	ֱ�� ��ָ�����
*/

#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}  // ���캯��
};

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *l1 = headA;  // ���Զ���
		ListNode *l2 = headB;  // ���Զ���
		while (l1 != l2) {
			l1 = l1 ? l1->next : headB;  // ��ͷ���ʹ���һ����ʼ
			l2 = l2 ? l2->next : headA;  // ��ͷ���ʹ���һ����ʼ
		}
		return l1;  // ��ȣ��򷵻ؽڵ�ָ��
	}
};

/*
ע�⣬��Ŀ��������Է���Ϊ��
if (l1){
	l1 = l1->next;
}else{
	l1 = headB;
}
*/

int main() {
	ListNode a1(10), a2(20), a3(30);
	ListNode b1(1), b2(2);
	ListNode c1(40), c2(50), c3(60);

	a1.next = &a2;
	a2.next = &a3;
	a3.next = &c1;
	c1.next = &c2;
	c2.next = &c3;

	b1.next = &b2;
	b2.next = &c1;

	Solution solve;  // ʵ����
	ListNode *intersection = solve.getIntersectionNode(&a1, &b1);

	printf("%d\n", intersection->val);

	system("pause");
	return 0;
}

