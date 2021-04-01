/*
LeetCode 23. Merge k Sorted Lists
Hard
排序链表的合并（多个）
*/
/*
题目：
	已知k个【已排序】链表头节点指针，将这k个链表合并，合并后仍为有序的，返回合并后的头节点
*/
/*
方法1：
	暴力合并，每次合并前两个链表，即将k个链表按顺序合并k-1次

假设一共k个链表，每个链表节点数为n。
该方法的时间复杂度：
	(n+n)+(2n+n)+...+((k-1)n + n) 
= (1+2+...+k-1)n +(k-1)n 
= (1+2+...+k)n  - n
= (k(k+1)/2)n -n
= ((k^2+k)/2)n-n
= ((k^2 + k-2)/2)n
= O(k^2 *n)  //时间复杂度就是 上限O
(即n和n的链表合并，相当于操作n+n次)
*/
#include <iostream>
#include <vector>

// 链表-数据结构
struct ListNode {
	int val; //数据域
	ListNode *next; //指针域
	// 构造函数
	ListNode(int x): val(x), next(NULL) {}
};


// 合并两个链表
class Solution {
public:
	//合并两个链表
	ListNode *mergeTwoLists(ListNode * &l1, ListNode * &l2) {
		ListNode temp_head(0); //新头
		ListNode *pre = &temp_head; // 新链表 指针，可以动的
		// 归并合并
		while (l1 && l2) { //有一个到头了（空了），就结束
			// l1小，连l1
			if (l1->val < l2->val) {
				pre->next = l1;
				l1 = l1->next; // l1指针后移
			}
			// l2小，连l2
			else {
				pre->next = l2;
				l2 = l2->next;
			}
			pre = pre->next; // 新链表 指针pre向后移动
		}
		// l1 l2剩谁，连谁
		if (l1) {
			pre->next = l1;
		}
		if (l2) {
			pre->next = l2;
		}
		return temp_head.next; //返回新链表的.next作为 头节点指针
	}

	// 合并多个链表，暴力法，每轮合并两个，直到全部合并完
	ListNode *mergeKLists(std::vector<ListNode *> &lists) { // 里边存的是ListNode *
		// 注意，传入引用。  防止拷贝构造
		ListNode *head = lists[0];
		for (unsigned int i = 1; i < lists.size(); i++) { //因为size返回的是 unsigned int
			head = mergeTwoLists(head, lists[i]); //传入引用，防止拷贝构造
		}
		return head;
	}
};



int main() {
	ListNode a(10);
	ListNode b(40);
	ListNode c(70);
	a.next = &b;
	b.next = &c;

	ListNode e(20);
	ListNode f(80);
	e.next = &f;

	ListNode g(5);
	ListNode h(30);
	ListNode i(90);
	g.next = &h;
	h.next = &i;

	std::vector<ListNode *> node_vec;
	node_vec.push_back(&a);
	node_vec.push_back(&e);
	node_vec.push_back(&g);

	Solution solve;
	ListNode *head = solve.mergeKLists(node_vec);

	//打印
	while (head) {
		printf("%d  ", head->val);
		head = head->next; //移动head指针
	}
	printf("\n");

	system("pause");
	return 0;
}
