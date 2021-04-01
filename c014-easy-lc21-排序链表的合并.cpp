/*
LeetCode 21. Merge Two Sorted Lists
Easy
��������ĺϲ�
*/
/*
��֪��������������ͷ�ڵ�ָ��l1��l2�� ������������ϲ��� �ϲ�����Ϊ����ģ� ���غϲ����ͷ�ڵ�
*/
/*
˼·��
	�鲢����

	�Ƚ�l1��l2ָ��Ľڵ㣬����С�Ľڵ���뵽preָ��󣬲���ǰ�ƶ���С�ڵ��Ӧ��ָ�롣
*/

#include <iostream>

//���ݽṹ��������
struct ListNode {
	int val;
	ListNode *next;

	//���캯��
	ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
	//�鲢����
	ListNode *  mergeTwoLists(ListNode *l1,ListNode *l2) {
		ListNode temp_head(0); //��ʱͷ
		ListNode *pre = &temp_head; // ָ�룬���ƶ���

		while (l1 && l2) 
		{
			//�� l1�������� ֵС������l1
			if (l1->val < l2->val) {
				pre->next = l1; //��ͷ����l1
				l1 = l1->next; //l1ָ�����
			}
			//��������l2
			else {
				pre->next = l2; //����l2
				l2 = l2->next; // l2ָ�����
			}
			pre = pre->next; //preָ�����
		}
		//ʣ������
		if (l1) { //ʣ�ķ�NULL
			pre->next = l1;
		}
		if (l2) {
			pre->next = l2;
		}
		return temp_head.next; //��ͷ�� ��ַ����һ��ListNode*ָ�룩
	}
};

int main() {
	//����l1
	ListNode a(1);
	ListNode b(4);
	ListNode c(6);
	a.next = &b;
	b.next = &c;

	//����l2
	ListNode d(0);
	ListNode e(5);
	ListNode f(7);
	d.next = &e;
	e.next = &f;

	Solution solve;
	ListNode * head= solve.mergeTwoLists(&a, &d);

	while (head) {
		printf("val = %d ", head->val);
		head = head->next;
	}

	system("pause");
	return 0;
}