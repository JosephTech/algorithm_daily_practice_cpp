/*
LeetCode141.Linked List Cycle
leetCode142.Linked List Cycle II
已知链表中可能存在环，若有环，返回环起始节点，否则返回NULL
*/
/*
思路1，使用set求环的起始节点
	1、遍历链表，将链表中节点对应的指针插入set。即将链表中节点的地址插入set。
	2、在遍历插入节点前，需要再set中查找，第一个在set中发现的节点地址，即是链表环的起点
*/
#include <iostream>
#include <set>

// 链表节点
struct ListNode {
	int val;
	ListNode *next; //指针，指向ListNode实例，可以用->从实例中取值

	// 构造函数
	ListNode(int x):val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * detectCycle(ListNode *head) 
	{
		// 实例化 set容器
		std::set<ListNode*> node_set;

		// 遍历链表，insert到set前，使用find判断是否存在
		while (head)
		{
			if (node_set.find(head) != node_set.end())  // 没查到，返回end
			{
				return head;
			}
			node_set.insert(head); //插入
			head = head->next;
		}
		return NULL;
	}
};


int main() {

	system("pause");
	return 0;
}
