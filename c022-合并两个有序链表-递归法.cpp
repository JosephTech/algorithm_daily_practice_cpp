/*
leetcode 21
�ϲ�������������
	���磺
		1 -> 2 -> 4
		1 -> 3 -> 4

		�ϲ���
		1 -> 1 -> 2 -> 3 -> 4 -> 4
		��������ͨ��ƴ�Ӹ������� ��ɵ�
*/
#include <iostream>  // pause

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}  // ���캯��
};

class Solution {
public:
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		if (!l1) return l2;  // �ݹ���������� ˭�գ���������һ����  ����Ϊ�տ�ʼ����֪��ʣ�ࣩ
		if (!l2) return l1;
		if (l1->val < l2->val) {  // ˭С�� ���ź�˭�� �ϲ�������һ��, ���ظ�����next 
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}
		else { // д��дelse���У�����淶��д��
			l2->next = mergeTwoLists(l1, l2->next);
			return l2;
		}
	}
};


int main() {
	ListNode a1(1), a2(2), a3(4), b1(1), b2(3), b3(4);
	a1.next = &a2;
	a2.next = &a3;

	b1.next = &b2;
	b2.next = &b3;

	Solution solve;
	ListNode *head = solve.mergeTwoLists(&a1, &b1);
	while (head) {
		printf("%d ", head->val);
		head = head->next;
	}
	printf("\n");
	system("pause");
	return 0;
}