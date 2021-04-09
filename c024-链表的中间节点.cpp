/*
leetcode 876
	��������м�ڵ�
*/

#include <iostream>


struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}  // ���캯��
};


class Solution {
public:
	ListNode *middleNode(ListNode *head) {  // ����ָ�� ���е�
		if (!head)
			return NULL;  // ֻ��1��
		if (!head->next) 
			return head;  // ֻ��2���ڵ�
		ListNode *slow = head, *fast = head;
		while (fast && fast->next) {  // ��ǰ ����һ�� ��NULL��ʱ��  ��ÿ��ֻ���ж��������У�
			fast = fast->next->next;
			slow = slow->next;
		}
		return slow;
	}
};


int main() {
	ListNode a(1), b(2), c(3), d(4), e(5);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;

	Solution solve;
	ListNode *mid = solve.middleNode(&a);
	
	printf("%d\n", mid->val);


	system("pause");
	return 0;
}