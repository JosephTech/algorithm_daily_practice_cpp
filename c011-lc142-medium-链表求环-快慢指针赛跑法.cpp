/*
leetCode 142.
链表求环
*/
/*
思路2：
	快慢指针赛跑法

快指针每次走两步，慢指针每次走一步

相遇时（套圈）：
a+b+c+b = 2*(a+b)
可得 a = c

所以：
从起始位置 和 相遇位置 以相同速度同时出发，相遇点即为环开始节点
*/

#include <iostream>

struct ListNode {
	int val;
	ListNode *next; // 指针

	// 构造函数
	ListNode(int x):val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *detectCycle(ListNode *head) 
	{
		ListNode *fast = head;
		ListNode *slow = head;
		ListNode *meet = NULL;

		// fast走两步，slow走一步，记录相遇
		while(fast) // 踩到NULL，不循环
		{
			fast = fast->next;
			slow = slow->next; //各走一步

			if (!fast) // 踩到NULL,跳出
			{
				return NULL; //或者break，在外边return
			}
			fast = fast->next;//再走一步
			if (fast == slow) //套圈了 
			{
				meet = fast;
				break; // 跳出while
			}
		}

		// 未相遇，返回NULL
		if (meet == NULL) // 注意：是==
		{
			return NULL;
		}

		// 相遇。从head和meet各走一步，相遇点即为 环起始位置
		while (head && meet) //为了代码规范才写的。可以写做while(1){}
		{
			if (head == meet) 
			{
				return head; //找到了环的起始位置
			}
			head = head->next; //各走一步
			meet = meet->next;
		}
		return NULL; //根本走不到这一步，为了代码规范才写的。
	}
};

int main() {
	// 节点 实例化
	ListNode a(1);
	ListNode b(2);
	ListNode c(666888);
	ListNode d(4);
	ListNode e(5);
	ListNode f(6);
	ListNode g(7);

	// 连接 链表的节点
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	f.next = &g;
	g.next = &c;

	// 实例化Solution、调函数。 显示返回值
	Solution solve;
	ListNode * node = solve.detectCycle(&a);

	if (node) //地址非空
	{
		printf("node->val = %d\n", node->val);
	}
	else 
	{
		printf("未找到\n");
	}

	system("pause");
	return 0;
}