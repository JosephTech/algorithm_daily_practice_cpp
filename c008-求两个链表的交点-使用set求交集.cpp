/*
求两个链表的交点

思路1：
	使用set容器
*/

#include <iostream>
#include <set>

struct ListNode {
	int val;
	ListNode * next;

	//构造函数
	ListNode(int x):val(x),next(NULL) {}
};

class Solution {
	ListNode * findIntersectionNode(ListNode *headA, ListNode *headB)
	{
		// 构造节点set容器
		std::set<ListNode*> node_set;

		// while遍历A,插入节点set容器中
		while (headA) 
		{
			node_set.insert(headA);
			headA = headA->next;
		}

		// while遍历B, 返回第一个相同的节点的地址
		while (headB)
		{
			// 若找到，则返回该节点的地址
			if (node_set.find(headB) != node_set.end()) //  =end是没找到。不等于，则找到。 
			{
				return headB;
			}
			headB = headB->next; //遍历。 下一个变成当前
		}
		// 遍历完也没找到
		return NULL;
	}
};


int main() 
{

	system("pause");
	return 0;
}