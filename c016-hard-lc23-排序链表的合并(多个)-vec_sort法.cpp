/*
思路2：
	将k*n个节点放到vetcor中，再将vector排序，再将节点顺序相连。

设有k个链表，平均每个链表有n个节点，
时间复杂度：  
	因为排序的最优复杂度就是nlogn， 一共kN个节点，
	kN个节点顺序相连的时间复杂度是kN
	所以：
	kN*logkN + kN
	=O(kN*logkN)

	比如k=100,n=10000时
	logkN = 20，小于k
	即
	kNlogkN < k^2 * N
	比暴力法少
*/

#include <iostream>
#include <vector>
#include <algorithm>

// 链表-数据结构
struct ListNode {
	int val;
	ListNode *next;
	// 构造函数
	ListNode(int x): val(x), next(NULL) {}
};

//比较函数
bool cmp(const ListNode *a, const ListNode *b) // const确保  不被本函数变
{
	return a->val < b->val;
}


class Solution {
public:
	ListNode *mergeKLists(std::vector<ListNode *> &lists) { //传入引用，避免拷贝构造
		std::vector<ListNode *> node_vec;
		//全添到vector中
		for (unsigned int i = 0; i < lists.size(); i++) {
			ListNode *head = lists[i]; //取出头部指针，作为head
			while (head) {
				node_vec.push_back(head);
				head = head->next; // 遍历此链表。   添加到vector中
			}
		}
		// node_vec没有元素，就返回NULL。  感觉这一句是废话，可以不写
		if (node_vec.size() == 0) {
			return NULL;
		}
		//sort排序、连上、连上尾巴、返回
		std::sort(node_vec.begin(), node_vec.end(), cmp);
		for (unsigned int i = 1; i < node_vec.size(); i++) {
			node_vec[i - 1]->next = node_vec[i];
		}
		node_vec[node_vec.size() - 1]->next = NULL;
		return node_vec[0];
	}
};


int main() {
	ListNode a(10);
	ListNode b(40);
	ListNode c(70);
	a.next = &b;
	b.next = &c;

	ListNode e(20);
	ListNode f(80);
	e.next = &f;

	ListNode g(5);
	ListNode h(30);
	ListNode i(90);
	g.next = &h;
	h.next = &i;

	std::vector<ListNode *> node_vec;
	node_vec.push_back(&a);
	node_vec.push_back(&e);
	node_vec.push_back(&g);

	Solution solve;
	ListNode *head = solve.mergeKLists(node_vec);

	//打印
	while (head) {
		printf("%d  ", head->val);
		head = head->next; //移动指针
	}
	printf("\n");

	system("pause");
	return 0;
}
