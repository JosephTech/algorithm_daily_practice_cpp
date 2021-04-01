/*
链表：
	新建一个结构体
	1、存储元素的数据域
	2、存储下一个元素的地址域
*/
#include <stdio.h>
#include <iostream> // 有了这一句能system("pause")。  能cout

//结构体、有数据域val。地址域*next
struct ListNode{
	int val;
	ListNode *next; //struct自身 实例的地址 放在next
};
int main() {
	ListNode a;
	ListNode b;
	ListNode c;
	ListNode d;
	ListNode e;
	a.val = 10;
	b.val = 20;
	c.val = 30;
	d.val = 40;
	e.val = 50;

	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = NULL; //c++中NULL大写，true和false小写

	ListNode *head = &a; //指针head  指向ListNode的实例a

	while (head) {
		//打印值
		printf("%d\n", head->val); //指针head 指向 a实例
		head = head->next; //指针head 指向 b实例
	}
	system("pause");
	return 0;
}
