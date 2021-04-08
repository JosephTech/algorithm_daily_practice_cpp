/*
题目：
	k个一组翻转链表
	k是一个正整数
	k 小于等于 链表长度

如果节点总数不是k整数倍，最后剩余的节点需保持原有顺序
*/
/*
例子：
	1 -> 2 -> 3 -> 4 -> 5
当k=2时
	2 -> 1 -> 4 -> 3 -> 5

当k=3时
	3 -> 2 -> 1 -> 4 -> 5
*/
/*
LeetCode系列之【25. K 个一组翻转链表】C++ 每天一道leetcode！
https://blog.csdn.net/qq_28410301/article/details/100267021?utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-1.control&dist_request_id=&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-1.control
*/


#include <iostream>  // pause

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *reverse_k(ListNode *head, int k) {
		ListNode *dummy = new ListNode(0);   // 哨兵。  new只返回地址，所以不用名字
		dummy->next = head;
		ListNode *pre = dummy, *start = head, *end = head, *next = head;
		while (next) {  // next不空的时候，就继续
			for (int i = 1; i < k && end != NULL; i++)  // 维护end最初在start处。end从1移动到最后
				end = end->next;
			if (end == NULL) // 若end移动到NULL了，就结束
				break;
			next = end->next;  // 记录 线段 下一个
			end->next = NULL;  // 为了让reverse函数能结束。 手术刀切一段
			end = start;  // end 指向线段开始
			start = reverse(start);  // start指向线段  翻转后的头
			pre->next = start;  // 手术缝合，连接头
			end->next = next;  // 连接尾
			pre = end;  // 维护pre，线段的 前一个节点
			end = end->next;  // 维护end， 新线段的头节点
			start = end;  // 维护start
		}
		return dummy->next;
	}

private:
	ListNode *reverse(ListNode * head) {
		ListNode *pre = NULL, *curr = head, *next = NULL;  // 注意新建NULL指针
		while (curr) {
			next = curr->next;  // 记录下一个
			curr->next = pre;  // 指向前一个
			pre = curr;  // 当前 变 前一个
			curr = next;  // 下一个 变 当前  。  所以用while(curr)
		}
		return pre;  // 返回最后一个，作为新头
	}
};


int main() {
	ListNode a(1), b(2), c(3), d(4), e(5);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;

	Solution solve;
	ListNode * head = solve.reverse_k(&a, 3);

	while (head) {
		printf("%d ", head->val);
		head = head->next;
	}
	printf("\n");


	system("pause");
	return 0;
}

