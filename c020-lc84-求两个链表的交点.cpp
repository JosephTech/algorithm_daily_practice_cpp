/*
给定两个链表，返回他们的交点

例子：
	a1 -> a2 -> a3->

	b1 -> b2 ->       c1 -> c2 -> c3
*/
/*
思路：
	两个 可移动的指针l1和l2
	移动到尾部  从另一链表的头部继续

	直到 两指针相等
*/

#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}  // 构造函数
};

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *l1 = headA;  // 可以动的
		ListNode *l2 = headB;  // 可以动的
		while (l1 != l2) {
			l1 = l1 ? l1->next : headB;  // 到头，就从另一个开始
			l2 = l2 ? l2->next : headA;  // 到头，就从另一个开始
		}
		return l1;  // 相等，则返回节点指针
	}
};

/*
注意，三目运算符可以翻译为：
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

	Solution solve;  // 实例化
	ListNode *intersection = solve.getIntersectionNode(&a1, &b1);

	printf("%d\n", intersection->val);

	system("pause");
	return 0;
}

