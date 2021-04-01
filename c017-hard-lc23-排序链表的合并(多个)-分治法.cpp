/*
分治后相连
方案3：
	对k个链表进行分治，两两进行合并

设有k个链表，每个链表有n个节点，时间复杂度：
	第1轮， 进行k/2次合并，每次处理2n个数字；
	第2轮， 进行k/4次合并，每次处理4n个数字；...
	...
	最后一轮，进行k/(2^logk)次合并，每次处理2^logk *N个值
	（注意：log是以2为底的）(注意，最后一轮 2^logk = k)
时间复杂度：
	2N*k/2 + 4N*k/4 + 8N*k/8 + 2^logk *N * k/(2^logk)
	= Nk + Nk + ... + Nk
	= O(kNlogk)  //共logk次合并
*/

#include <iostream>
#include <vector>

// 链表-数据结构
struct ListNode {
	int val;
	ListNode *next; //指针域
	// 构造函数
	ListNode(int x): val(x), next(NULL) {}
};

// 类，里边函数 mergeTwoLists、 mergeKLists
class Solution {
public:
	ListNode *mergeTwoLists(ListNode * l1, ListNode * l2) { //这为啥不用引用？ 就两个数l1和l2，引用啥啊
		// 归并
		//临时头节点、可以移动的pre指针
		ListNode temp_head(0);
		ListNode *pre = &temp_head;
		while (l1 && l2) { //都不空的时候
			//谁小，pre->next连上谁
			if (l1->val < l2->val) {
				pre->next = l1;
				l1 = l1->next; //指针后移
			}
			else {
				pre->next = l2;
				l2 = l2->next; //指针后移
			}
			pre = pre->next; //pre指针后移
		}
		//谁还剩的有，连上谁
		if (l1) {
			pre->next = l1;
		}
		if (l2) {
			pre->next = l2;
		}
		// 返回
		return temp_head.next;
	}

	// 混合多个链表
	ListNode *mergeKList(std::vector<ListNode *> &lists) {
		// lists没有头节点，返回NULL
		if (lists.size() == 0) {
			return NULL;
		}

		// lists有一个头节点，返回lists[0]
		if (lists.size() == 1) {
			return lists[0];
		}

		// lists有2个头节点，返回mergeTwoLists
		if (lists.size() == 2) {
			return mergeTwoLists(lists[0], lists[1]);
		}

		// 2分lists.size()、 前一半放到一个vector里sub1_lists，后一般放到另一个vector里sub2_lists
		std::vector<ListNode *> sub1_lists;
		std::vector<ListNode *> sub2_lists;

		int mid = lists.size() / 2;

		for (int i = 0; i < mid; i++) {
			sub1_lists.push_back(lists[i]);
		}
		for (unsigned int i = mid; i < lists.size(); i++) {
			sub2_lists.push_back(lists[i]);
		}

		// 对sub1和sub2递归调用
		ListNode *l1 = mergeKList(sub1_lists);
		ListNode *l2 = mergeKList(sub2_lists);

		// mergeTwoLists
		return mergeTwoLists(l1, l2); //最后一次合并
	}
};


int main() {
	// 实例化节点、连接
	ListNode a(10);
	ListNode b(40);
	ListNode c(90);
	a.next = &b;
	b.next = &c;

	// 实例化节点，连接
	ListNode d(6);
	ListNode e(88);
	d.next = &e;

	ListNode f(30);
	ListNode g(60);
	ListNode h(100);
	f.next = &g;
	g.next = &h;

	std::vector<ListNode *> lists;
	lists.push_back(&a);
	lists.push_back(&d);
	lists.push_back(&f);

	Solution solve;
	ListNode *head = solve.mergeKList(lists);

	while (head) {
		printf("%d  ", head->val);
		head = head->next;
	}
	printf("\n");

	system("pause");
	return 0;
}
