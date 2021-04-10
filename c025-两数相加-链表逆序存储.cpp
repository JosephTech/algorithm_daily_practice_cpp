/*
参考链接：
【LeetCode】2. 两数相加（链表逆序存储——易） & 445. 两数相加 II（链表正序存储——难：栈）
https://blog.csdn.net/weixin_41888257/article/details/107289086
*/
/*
2 两数相加（c++ 链表 ）
https://blog.csdn.net/LIJIWEI0611/article/details/102709983?utm_medium=distribute.pc_relevant.none-task-blog-baidujs_title-0&spm=1001.2101.3001.4242
*/
/*
这个好
leetcode 2 两数相加(c++)
https://zhuanlan.zhihu.com/p/102633949
*/

#include <iostream>  // pause

struct ListNode {  // 数据结构
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}  // 构造函数
};

class Solution {
public:
	ListNode *twoSum(ListNode *l1, ListNode *l2) {
		int flag = 0;  // 进位的值 
		ListNode *dummy = new ListNode(0);  // 憨憨
		ListNode *curr = dummy;  // 工作指针
		int num = 0;
		while (l1 || l2) {
			if (l1)
				num += l1->val;
			if (l2)
				num += l2->val;
			curr->next = new ListNode(num % 10);  // 取余数部分， 作为当前位
			flag = num / 10;  // 商 更新flag
			curr = curr->next;  // 移动curr指针、l1指针、 l2指针
			if (l1) 
				l1 = l1->next;
			if (l2) 
				l2 = l2->next;
			num = 0;  // 下一位的和
			if (flag)
				num += flag;  // 若有flag, 更新sum，下一个节点继续用。
		}
		if (num)  // 如果 还剩余的有
			curr->next = new ListNode(num);
		return dummy->next;
	}
};

/*
注意：
	若写程序时候，要删除自己new的节点
*/

int main() {
	ListNode a1(1), a2(2), a3(8),b1(3), b2(3), b3(3);

	a1.next = &a2;
	a2.next = &a3;
	
	b1.next = &b2;
	b2.next = &b3;

	Solution solve;
	ListNode * head =solve.twoSum(&a1, &b1);
	ListNode * curr = head;
	while (head) {
		printf("%d ", head->val);
		head = head->next;
	}
	printf("\n");
	
	while (curr) {  // 删除
		ListNode *next = curr->next;  // 记录下一个
		delete curr;  // 删除当前
		curr = next;  // 下一个
	}

	system("pause");
	return 0;
}