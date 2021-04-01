/*
leetCode 86. Partition List
链表划分
已知链表头指针head与数值x，将所有小于x的节点放在大于或等于x的节点前，且保持这些节点原来的相对位置
*/
#include <iostream>

// 结构体。链表节点ListNode
struct ListNode {
	int val;
	ListNode *next;

	//构造函数
	ListNode(int x):val(x), next(NULL) {}
};

// 类Solution，里边定义函数partition
class Solution {
public:
	ListNode *partition(ListNode *head, int x) 
	{
		ListNode less_head(0);
		ListNode more_head(0); //新建两个头  即实例化
		ListNode *less_ptr = &less_head; //指向 新头
		ListNode *more_ptr = &more_head;

		while (head) 
		{
			// 小于，则连上less_head。使用ptr连，因为ptr能动啊
			if (head->val < x) 
			{
				less_ptr->next = head; //连上
				less_ptr = head; //移动less_ptr
			}

			// 大于，则连上more_head
			else 
			{
				more_ptr->next = head; //连上
				more_ptr = head; //移动more_ptr
			}
			head = head->next; // 指针head 右移
		}
		less_ptr->next = more_head.next; //连上
		more_ptr->next = NULL; // 尾巴置空
		return less_head.next; // 返回第二个节点开始的链表
	}
};

//main
int main() {
	// 实例化 链表节点
	ListNode a(30);
	ListNode b(70);
	ListNode c(40);
	ListNode d(60);
	ListNode e(10);
	ListNode f(50);
	ListNode g(20);

	//连接
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	f.next = &g;
	g.next = NULL;

	// 实例化Solution、调用函数
	Solution solve;
	ListNode *head = solve.partition(&a, 39);

	while (head) 
	{
		printf("%d\n",head->val);
		head = head->next;
	}

	system("pause");
	return 0;
}

