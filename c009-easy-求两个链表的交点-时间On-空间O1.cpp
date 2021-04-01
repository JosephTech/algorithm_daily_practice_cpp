/*
set集合的时间复杂度是nlog(n)。  空间复杂度是O(n)（先记着）
*/

/*
思路2:，空间复杂度O(1)  (就是占用的多少内存空间)

	步骤1：计算headA链表长度， 计算headB链表长度，较长的链表多出的长度
	步骤2：将较长链表的指针，移动到和较短链表对齐的位置
	步骤3：headA和headB同时移动，当两指针指向同一节点时，即找到了
*/

#include <iostream> // "pause"用的

//结构体。 链表
struct ListNode {
	int val;
	ListNode * next; //指向下个实例

	// 构造函数
	ListNode(int x):val(x), next(NULL) {}
};

// 函数。 获取链表长度
int get_list_length(ListNode *head) 
{
	int len = 0;
	while (head) 
	{
		len++;
		head = head->next; //移到下一个节点
	}
	return len;
}

// 函数。将head指针 移动 （长-短）个位置。 （即 从1开始移动（长-短）个位置）
ListNode *forward_minus_len(int long_len, int short_len, ListNode * head) 
{
	int forward_len = long_len - short_len;

	// 向前移动forward_len
	while (head && forward_len) 
	{
		head = head->next;
		forward_len--;
	}
	return head;
}

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
	{
		// 求两个链表的长度
		int list_A_len = get_list_length(headA);
		int list_B_len = get_list_length(headB);

		// 长的两边 的head指针 向前移动 （long-short） 个位置
		if (list_A_len > list_B_len)
		{
			headA = forward_minus_len(list_A_len, list_B_len, headA); //复用headA
		}
		else 
		{
			headB = forward_minus_len(list_B_len, list_A_len, headB);
		}
		while (headA && headB) 
		{
			if (headA == headB) 
			{
				return headA;
			}
			headA = headA->next;
			headB = headB->next;
		}
		return NULL;
	}
};

int main() {
	// 实例化节点、赋值
	ListNode a1(1);
	ListNode a2(3);
	ListNode a3(2);

	ListNode b1(6);
	ListNode b2(7);

	ListNode c1(666);
	ListNode c2(777);
	ListNode c3(888);

	// 连接节点
	a1.next = &a2;
	a2.next = &a3;
	a3.next = &c1;

	c1.next = &c2;
	c2.next = &c3; // c3默认的构造是NULL

	b1.next = &b2;
	b2.next = &c1;

	Solution solve;// 实例化
	ListNode * result = solve.getIntersectionNode(&a1, &b1);

	if (result != NULL)
	{
		printf("交点 存储的值是：%d\n", result->val); // 指针（指向ListNode实例，即指向节点），取val
	}
	else
	{
		printf("无交点\n");
	}


	system("pause");
	return 0;
}