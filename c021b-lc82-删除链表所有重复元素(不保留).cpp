/*
题目：删除链表中 所有重复元素，不保留

传入链表头节点指针
*/
#include <iostream>  // pause
using namespace std;

struct ListNode {
	int val;  // 数据域
	ListNode* next;  // 指针域
	ListNode(int x): val(x), next(NULL) {}  //构造函数
};


class Solution {
public:
	ListNode *removeDuplicates(ListNode* head) {  // 传入头节点指针，移除所有重复元素
		ListNode *dummyHead = new ListNode(0);  // 0也行，-1也行，反正不用它的数据域
		dummyHead->next = head;  // 连上
		ListNode *cur = dummyHead;  // 可动
		ListNode *pre = dummyHead;  // 前驱
		while (cur) {  // cur不空的时候
			if (cur->next && cur->val == cur->next->val) {  // next不是NULL，且值相等
				while (cur->next && cur->val == cur->next->val)  // next不是null 且相等 ,移动cur到重复元素结尾
					cur = cur->next;
				cur = cur->next;  // 后驱
				pre->next = cur;  // 连上
			}
			else {  // next是NULL，或者 不相等
				pre = cur;  // 当前变成前驱
				cur = cur->next;  // 移动当前，移动到next，（若next是NULL，则进不去下一轮while）
			}
		}
		ListNode *retNode = dummyHead->next;  // 记录
		delete dummyHead;  // 管理内存
		return retNode;
	}
};

int main() {
	ListNode a(1), b(1), c(2), d(3), e(3), f(3), g(4), h(5), x(6), y(6);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	f.next = &g;
	g.next = &h;
	h.next = &x;
	x.next = &y;

	Solution solve; // 实例化
	ListNode *head = solve.removeDuplicates(&a);

	while (head) {
		printf("%d\n", head->val);
		head = head->next;
	}

	system("pause");
	return 0;
}