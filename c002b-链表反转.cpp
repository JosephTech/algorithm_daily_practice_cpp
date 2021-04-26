#include <iostream>  // pause

struct ListNode{
	int val;  // 数据域
	ListNode *next;  // 指针域
	ListNode(int x): val(x), next(NULL) {}  // 构造函数
};

class Solution {
public:
	ListNode *reverseLinkedList(ListNode *head) {  // 传入头节点指针
		ListNode *pre = NULL;  // 前一个节点指针
		while (head) {  // head是当前节点cur
			ListNode* next = head->next;  // 记录下一个节点  . 写在while里边，若head不存在，则head->next就不会报错
			head->next = pre;  // 指向前一个节点
			pre = head;  // 当前变成前一个
			head = next;  // 下一个变成当前
		}
		return pre;  // 若head=NULL，则也是返回NULL，不影响
	}
};

int main() {
	ListNode a(10), b(20), c(30);
	a.next = &b;  //链接
	b.next = &c;

	Solution solve;  //实例化
	ListNode *head = &a;
	while (head) {
		printf("[%d]\n", head->val);
		head = head->next;
	}
	printf("----------------\n");
	head = solve.reverseLinkedList(&a);
	while (head) {
		printf("[%d]\n", head->val);
		head = head->next;
	}

	system("pause");
	return 0;
}