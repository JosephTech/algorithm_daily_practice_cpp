/*
leetcode 234链表回文
palindrome linked list

题目：
	以O(1)的空间复杂度，判断链表是否回文

例如：
	1 -> 2 -> 3 -> 2 -> 1
	true
*/
/*
思路：
	快慢指针找到中点，
	翻转慢指针后边的
	逐个比较，返回true或者false
*/

#include <iostream>  // puase

struct ListNode {  // 数据结构
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}  // 构造函数
};

class Solution {
public:
	bool isPalindrome(ListNode *head) {
		if (!head) 
			return false;  // 严谨了
		ListNode *slow = head, *fast = head;
		while (fast->next && fast->next->next) {  // 不空的时候
			slow = slow->next;
			fast = fast->next->next;  // 走两步
		}
		slow->next = reverse(slow->next);  // 翻转 后边的
		slow = slow->next;  // slow和head都到起点
		while (head && slow) {  // 比较
			if (head->val != slow->val) {
				return false;
			}
			head = head->next;
			slow = slow->next;
		}
		return true;
	}
private:
	ListNode *reverse(ListNode *head) {  // 翻转链表
		ListNode *curr = head;  // 代码规范，多写一行吧
		ListNode *pre = NULL;
		while (curr) {
			ListNode *next = curr->next;  // 记录下一个
			curr->next = pre;  // 调转马头
			pre = curr;  // 当前 赋值给 上一个
			curr = next;  // 下一个 变成  当前
		}
		return pre;   // 返回 新头
	}
};



int main() {
	ListNode a(1), b(2), c(3), d(2), e(2);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;

	Solution solve;
	printf("%d\n", solve.isPalindrome(&a));

	system("pause");
	return 0;
}