/*
leetcode 876
	求链表的中间节点
*/

#include <iostream>


struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}  // 构造函数
};


class Solution {
public:
	ListNode *middleNode(ListNode *head) {  // 快慢指针 找中点
		if (!head)
			return NULL;  // 只有1个
		if (!head->next) 
			return head;  // 只有2个节点
		ListNode *slow = head, *fast = head;
		while (fast && fast->next) {  // 当前 和下一个 非NULL的时候。  （每次只用判断两个就行）
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