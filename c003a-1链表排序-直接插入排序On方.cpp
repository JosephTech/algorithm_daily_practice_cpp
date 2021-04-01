/*
思路分析：
	https://blog.csdn.net/Doutd_y/article/details/81557320
	将一个一个元素从原链表取出来，与新链表逐元素比较,插入到新链表
	时间复杂度0(n^2)， 空间复杂度O(1)
*/

#include <iostream> // pause用的

struct ListNode {
	int val;
	ListNode *next;
	//构造函数
	ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *insertSortList(ListNode *head) { //传入旧链表 头节点指针
		ListNode sort_head(0); //新链表的头 的前一个节点
		while (head) { //head指针可以动，遍历旧链表。当前节点
			ListNode *temp = head->next;
			ListNode *inser = &sort_head; //创建一个指针，可以动的，遍历新链表
			while (inser->next != NULL && inser->next->val < head->val) { 
				//结束条件：insert->next-val的位置，即新链表的下一个元素 比 这个待插入元素大
				//			或者是新链表的next是NULL,即正在最后一个节点，则直接连上
				inser = inser->next;
			}
			head->next = inser->next; //连上后驱节点
			inser->next = head; // 连上前驱节点
			head = temp; //旧链表的下一个节点
		}
		return sort_head.next;
	}
};

int main() {
	ListNode n1(2), n2(1), n3(88), n4(3), n5(6);
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;

	Solution solve;
	ListNode *new_head = solve.insertSortList(&n1);

	ListNode *head = new_head;
	//打印
	while (head) {
		printf("%d\n",head->val);
		head = head->next;
	}

	system("pause");
	return 0;
}