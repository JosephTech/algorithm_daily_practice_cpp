#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;  // 地址域
	ListNode(int x):val(x), next(NULL) {}  // 构造函数
};

class Solution {
public:
	ListNode* oddEvenList(ListNode *head) {  // 传入头节点
		if (!head)
			return NULL;
		if (!head->next)
			return head;  // 只有一个节点。 这两行可以不写，走到最后return也一样

		ListNode *dummyOdd = new ListNode(0);
		ListNode *dummyEven = new ListNode(0);  // 堆区数据

		ListNode *cur = head;  // 可动的
		ListNode *p_odd = dummyOdd, *q_even = dummyEven;  // 分别是奇指针、偶指针
		int cnt = 1;  // 计数的，奇数偶数，当前cur在哪个位置
		while (cur) {
			if (cnt % 2 == 1) { // 奇数
				p_odd->next = cur;  // 连上
				p_odd = p_odd->next;  // 走一步
			}
			else {
				q_even->next = cur;  // 连上
				q_even = q_even->next;  // 走一步
			}
			cur = cur->next;  //走一步
			cnt += 1;  //计数
		}
		q_even->next = NULL;  //偶数结尾 置为NULL
		p_odd->next = dummyEven->next;  // 连上偶数开头

		ListNode *retNode = dummyOdd->next;
		delete dummyOdd;
		delete dummyEven;  // 管理内存
		
		return retNode;  //返回
	}
};

int main() {
	ListNode a(1), b(2), c(3), d(4), e(5), f(6);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;


	Solution solve;  // 实例化
	ListNode *head = solve.oddEvenList(&a);

	while (head) {
		printf("%d\n", head->val);
		head = head->next;
	}

	system("pause");
	return 0;
}