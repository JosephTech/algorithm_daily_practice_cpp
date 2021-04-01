/*
LeetCode 23. Merge k Sorted Lists
Hard
��������ĺϲ��������
*/
/*
��Ŀ��
	��֪k��������������ͷ�ڵ�ָ�룬����k������ϲ����ϲ�����Ϊ����ģ����غϲ����ͷ�ڵ�
*/
/*
����1��
	�����ϲ���ÿ�κϲ�ǰ������������k������˳��ϲ�k-1��

����һ��k������ÿ������ڵ���Ϊn��
�÷�����ʱ�临�Ӷȣ�
	(n+n)+(2n+n)+...+((k-1)n + n) 
= (1+2+...+k-1)n +(k-1)n 
= (1+2+...+k)n  - n
= (k(k+1)/2)n -n
= ((k^2+k)/2)n-n
= ((k^2 + k-2)/2)n
= O(k^2 *n)  //ʱ�临�ӶȾ��� ����O
(��n��n������ϲ����൱�ڲ���n+n��)
*/
#include <iostream>
#include <vector>

// ����-���ݽṹ
struct ListNode {
	int val; //������
	ListNode *next; //ָ����
	// ���캯��
	ListNode(int x): val(x), next(NULL) {}
};


// �ϲ���������
class Solution {
public:
	//�ϲ���������
	ListNode *mergeTwoLists(ListNode * &l1, ListNode * &l2) {
		ListNode temp_head(0); //��ͷ
		ListNode *pre = &temp_head; // ������ ָ�룬���Զ���
		// �鲢�ϲ�
		while (l1 && l2) { //��һ����ͷ�ˣ����ˣ����ͽ���
			// l1С����l1
			if (l1->val < l2->val) {
				pre->next = l1;
				l1 = l1->next; // l1ָ�����
			}
			// l2С����l2
			else {
				pre->next = l2;
				l2 = l2->next;
			}
			pre = pre->next; // ������ ָ��pre����ƶ�
		}
		// l1 l2ʣ˭����˭
		if (l1) {
			pre->next = l1;
		}
		if (l2) {
			pre->next = l2;
		}
		return temp_head.next; //�����������.next��Ϊ ͷ�ڵ�ָ��
	}

	// �ϲ����������������ÿ�ֺϲ�������ֱ��ȫ���ϲ���
	ListNode *mergeKLists(std::vector<ListNode *> &lists) { // ��ߴ����ListNode *
		// ע�⣬�������á�  ��ֹ��������
		ListNode *head = lists[0];
		for (unsigned int i = 1; i < lists.size(); i++) { //��Ϊsize���ص��� unsigned int
			head = mergeTwoLists(head, lists[i]); //�������ã���ֹ��������
		}
		return head;
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

	//��ӡ
	while (head) {
		printf("%d  ", head->val);
		head = head->next; //�ƶ�headָ��
	}
	printf("\n");

	system("pause");
	return 0;
}
