/*
题目：
	剑指offer
	删除链表中 的重复元素，不保留

例如：
	1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5
	删除后：
	1 -> 2 -> 5
*/
/*
参考资料：
	【LeetCode 83】删除排序链表中的重复元素 VS. 【剑指offer】删除链表中重复元素
	https://blog.csdn.net/weixin_41888257/article/details/105178506
*/

#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}  // 构造函数
};


class Solution {
public:
	ListNode *deleteDuplication(ListNode *head) {  // 删除重复元素
		if (!head || !head->next) {  // 若有0个或者1个节点，返回
			return head;
		}
		ListNode *dummy = new ListNode(0);  // 哨兵，憨憨. 堆区新建，返回地址
		dummy->next = head;  // dummy的next指向头
		ListNode *pre = dummy;  // 初始化，维护pre指针， 指向不重复的节点
		ListNode *last = pre->next; // 维护last指针，指向下一个节点
		while (last) {  // 当last不为NULL的时候，就继续
			if (last->next && last->val == last->next->val) {  // 注意： 先判断的 放在前面，就是说last->next != NULL放在前边
				while (last->next && last->val == last->next->val) {  // 注意这里是last->next 不NULL, 之后要维护正确
					last = last->next;  // 多个重复节点
				}
				pre->next = last->next;  // 连上
				last = last->next;  // 维护。  画一画就知道了，移动到last->next，即移动到NULL就结束了
			}
			else {  // 如果不重复，就继续后移。  如果下一个value==NULL, 就后移
				pre = pre->next;
				last = last->next;
			}
		}
		return dummy->next;  // 返回憨憨的next
	}
};


int main() {
	ListNode a(1), b(2), c(3), d(3), e(3), f(4), g(5), h(5);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	f.next = &g;
	g.next = &h;

	Solution solve;
	ListNode *head = solve.deleteDuplication(&a);

	while (head) {
		printf("%d ", head->val);
		head = head->next;
	}
	printf("\n");

	system("pause");
	return 0;
}

