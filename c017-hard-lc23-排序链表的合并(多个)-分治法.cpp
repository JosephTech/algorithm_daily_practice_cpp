/*
���κ�����
����3��
	��k��������з��Σ��������кϲ�

����k������ÿ��������n���ڵ㣬ʱ�临�Ӷȣ�
	��1�֣� ����k/2�κϲ���ÿ�δ���2n�����֣�
	��2�֣� ����k/4�κϲ���ÿ�δ���4n�����֣�...
	...
	���һ�֣�����k/(2^logk)�κϲ���ÿ�δ���2^logk *N��ֵ
	��ע�⣺log����2Ϊ�׵ģ�(ע�⣬���һ�� 2^logk = k)
ʱ�临�Ӷȣ�
	2N*k/2 + 4N*k/4 + 8N*k/8 + 2^logk *N * k/(2^logk)
	= Nk + Nk + ... + Nk
	= O(kNlogk)  //��logk�κϲ�
*/

#include <iostream>
#include <vector>

// ����-���ݽṹ
struct ListNode {
	int val;
	ListNode *next; //ָ����
	// ���캯��
	ListNode(int x): val(x), next(NULL) {}
};

// �࣬��ߺ��� mergeTwoLists�� mergeKLists
class Solution {
public:
	ListNode *mergeTwoLists(ListNode * l1, ListNode * l2) { //��Ϊɶ�������ã� ��������l1��l2������ɶ��
		// �鲢
		//��ʱͷ�ڵ㡢�����ƶ���preָ��
		ListNode temp_head(0);
		ListNode *pre = &temp_head;
		while (l1 && l2) { //�����յ�ʱ��
			//˭С��pre->next����˭
			if (l1->val < l2->val) {
				pre->next = l1;
				l1 = l1->next; //ָ�����
			}
			else {
				pre->next = l2;
				l2 = l2->next; //ָ�����
			}
			pre = pre->next; //preָ�����
		}
		//˭��ʣ���У�����˭
		if (l1) {
			pre->next = l1;
		}
		if (l2) {
			pre->next = l2;
		}
		// ����
		return temp_head.next;
	}

	// ��϶������
	ListNode *mergeKList(std::vector<ListNode *> &lists) {
		// listsû��ͷ�ڵ㣬����NULL
		if (lists.size() == 0) {
			return NULL;
		}

		// lists��һ��ͷ�ڵ㣬����lists[0]
		if (lists.size() == 1) {
			return lists[0];
		}

		// lists��2��ͷ�ڵ㣬����mergeTwoLists
		if (lists.size() == 2) {
			return mergeTwoLists(lists[0], lists[1]);
		}

		// 2��lists.size()�� ǰһ��ŵ�һ��vector��sub1_lists����һ��ŵ���һ��vector��sub2_lists
		std::vector<ListNode *> sub1_lists;
		std::vector<ListNode *> sub2_lists;

		int mid = lists.size() / 2;

		for (int i = 0; i < mid; i++) {
			sub1_lists.push_back(lists[i]);
		}
		for (unsigned int i = mid; i < lists.size(); i++) {
			sub2_lists.push_back(lists[i]);
		}

		// ��sub1��sub2�ݹ����
		ListNode *l1 = mergeKList(sub1_lists);
		ListNode *l2 = mergeKList(sub2_lists);

		// mergeTwoLists
		return mergeTwoLists(l1, l2); //���һ�κϲ�
	}
};


int main() {
	// ʵ�����ڵ㡢����
	ListNode a(10);
	ListNode b(40);
	ListNode c(90);
	a.next = &b;
	b.next = &c;

	// ʵ�����ڵ㣬����
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
