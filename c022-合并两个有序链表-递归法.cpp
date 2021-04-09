/*
leetcode 21
合并两个有序链表：
	例如：
		1 -> 2 -> 4
		1 -> 3 -> 4

		合并后：
		1 -> 1 -> 2 -> 3 -> 4 -> 4
		新链表是通过拼接给定链表 组成的
*/
#include <iostream>  // pause

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}  // 构造函数
};

class Solution {
public:
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		if (!l1) return l2;  // 递归结束条件， 谁空，返回另外一个。  （因为刚开始，已知有剩余）
		if (!l2) return l1;
		if (l1->val < l2->val) {  // 谁小， 就排好谁。 合并它的下一个, 返回给它的next 
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}
		else { // 写不写else都行，代码规范，写吧
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