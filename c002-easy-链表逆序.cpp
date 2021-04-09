/*
已知链表头节点指针head，将链表逆序。（不可申请额外空间，变量不算额外空间，指的是不能再整个vecto）
*/
#include <stdio.h>
#include <iostream>

// 结构体，链表的节点
struct ListNode {
	int val; //数据域
	ListNode *next; //地址域。  （指针，存下一个ListNode的地址）

	//构造函数
	ListNode(int x) : val(x), next(NULL) { // next指针有了默认值NULL。 就不会空了
	}
};

class Solution {
public:
	ListNode * reverseList(ListNode *head) { // 返回值是ListNode*
		// head存当前节点 的地址
		// new_head存 上个节点的地址
		// next临时存 下个节点地址（即当前节点的指向）
		
		ListNode *new_head = NULL;
		while (head) {
			//next 临时存下个节点地址（即当前节点指向）
			ListNode *next = head->next;

			// 调转马头head->next  指向上一个
			head->next = new_head;
			
			// 当前变成上一个。 更新上一个节点地址new_head。 
			new_head = head;
			
			// 下一个变成当前。更新当前节点地址。 
			head = next;
		}
		return new_head; // 最后，new_head指向最后一个 当前节点
		// 最后，next和head都是NULL
	}
};

int main() {
	ListNode a(1); //构造
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode e(5);

	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	//e.next = NULL;//这句不用，因为ListNode的构造函数写了

	printf("reverse逆序前：\n");
	ListNode * head = &a;
	while (head) {
		printf("%d\n", head->val); // %d格式化为整型
		head = head->next; //下一个变成当前
	}

	printf("reverse逆序后：\n");
	Solution sol;
	ListNode *new_head = sol.reverseList(&a);
	while (new_head) {
		printf("%d\n", new_head->val);
		new_head = new_head->next;
	}
	system("pause");
	return 0;
}