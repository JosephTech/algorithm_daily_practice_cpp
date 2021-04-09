/*
题目：
	将链表从m到n逆置
*/
#include <stdio.h>
#include <iostream>

// 链表
struct ListNode {
	//构造函数
	ListNode(int x) : val(x),next(NULL) {
	};

	int val; //数据域
	ListNode * next; // 地址域。 next域
};

// 解
// 1、pre_head
// 
class Solution {
public: //作用域
	ListNode *reverseBetween(ListNode *head, int m, int n) {
		int change_len = n - m + 1; // m到n的节点数。（改变这些节点的指向）
		ListNode *result = head; // 不出意外(前驱有节点)，result就是head。
		ListNode *pre_head = NULL; //初始化前驱

		// head指针从1移动到m。（即移动m-1次）。同时记录pre_head前驱
		while (head && --m) { //head移动m-1次
			pre_head = head; //当前节点变成前驱
			head = head->next; //下个节点变成当前节点
		}
		ListNode *modify_list_tail = head; // 新尾部节点

		// m~n逆序
		ListNode *new_head = NULL; // 前一个节点
		while (head && change_len) {
			ListNode *next = head->next; //临时存储下个节点
			head->next = new_head; //指向前一个
			new_head = head; //当前 变成 前一个
			head = next;// 下一个变成当前
			change_len--;
		}

		// 连接 尾部
		modify_list_tail->next = head;

		// if pre_head，连接头部
		if (pre_head) {
			pre_head->next = new_head; //指向新头
		}
		else {
			result = new_head; // new_head变头
		}
		return result;
	}
};


int main() {
	//建立节点
	ListNode a(1); //注意是节点。（不是指针）
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode e(5);

	// 连接。 
	a.next = &b; //注意是a.next()。因为是实例
	b.next = &c;
	c.next = &d;
	d.next = &e; //e默认指向NULL . (因构造函数)

	// 实例化Solution
	// 逆序
	Solution solve;
	ListNode *head = solve.reverseBetween(&a, 1, 4); // 2~4逆序。 返回新头

	// 遍历打印
	while (head) { //while(新头)
		printf("%d\n",head->val);
		head = head->next;
	}

	system("pause");
	return 0;
}