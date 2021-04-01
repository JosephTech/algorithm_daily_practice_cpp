/*
LeetCode 21. Merge Two Sorted Lists
Easy
排序链表的合并
*/
/*
已知两个已排序链表头节点指针l1与l2， 将这两个链表合并， 合并后仍为有序的， 返回合并后的头节点
*/
/*
思路：
	归并排序法

	比较l1和l2指向的节点，将较小的节点插入到pre指针后，并向前移动较小节点对应的指针。
*/

#include <iostream>

//数据结构——链表
struct ListNode {
	int val;
	ListNode *next;

	//构造函数
	ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
	//归并排序法
	ListNode *  mergeTwoLists(ListNode *l1,ListNode *l2) {
		ListNode temp_head(0); //临时头
		ListNode *pre = &temp_head; // 指针，可移动的

		while (l1 && l2) 
		{
			//若 l1的数据域 值小，连上l1
			if (l1->val < l2->val) {
				pre->next = l1; //新头连上l1
				l1 = l1->next; //l1指针后移
			}
			//否则连上l2
			else {
				pre->next = l2; //连上l2
				l2 = l2->next; // l2指针后移
			}
			pre = pre->next; //pre指针后移
		}
		//剩的连上
		if (l1) { //剩的非NULL
			pre->next = l1;
		}
		if (l2) {
			pre->next = l2;
		}
		return temp_head.next; //新头的 地址（即一个ListNode*指针）
	}
};

int main() {
	//链表l1
	ListNode a(1);
	ListNode b(4);
	ListNode c(6);
	a.next = &b;
	b.next = &c;

	//链表l2
	ListNode d(0);
	ListNode e(5);
	ListNode f(7);
	d.next = &e;
	e.next = &f;

	Solution solve;
	ListNode * head= solve.mergeTwoLists(&a, &d);

	while (head) {
		printf("val = %d ", head->val);
		head = head->next;
	}

	system("pause");
	return 0;
}