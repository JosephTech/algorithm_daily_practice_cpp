/*
��Ŀ��
	�������m��n����
*/
#include <stdio.h>
#include <iostream>

// ����
struct ListNode {
	//���캯��
	ListNode(int x) : val(x),next(NULL) {
	};

	int val; //������
	ListNode * next; // ��ַ�� next��
};

// ��
// 1��pre_head
// 
class Solution {
public: //������
	ListNode *reverseBetween(ListNode *head, int m, int n) {
		int change_len = n - m + 1; // m��n�Ľڵ��������ı���Щ�ڵ��ָ��
		ListNode *result = head; // ��������(ǰ���нڵ�)��result����head��
		ListNode *pre_head = NULL; //��ʼ��ǰ��

		// headָ���1�ƶ���m�������ƶ�m-1�Σ���ͬʱ��¼pre_headǰ��
		while (head && --m) { //head�ƶ�m-1��
			pre_head = head; //��ǰ�ڵ���ǰ��
			head = head->next; //�¸��ڵ��ɵ�ǰ�ڵ�
		}
		ListNode *modify_list_tail = head; // ��β���ڵ�

		// m~n����
		ListNode *new_head = NULL; // ǰһ���ڵ�
		while (head && change_len) {
			ListNode *next = head->next; //��ʱ�洢�¸��ڵ�
			head->next = new_head; //ָ��ǰһ��
			new_head = head; //��ǰ ��� ǰһ��
			head = next;// ��һ����ɵ�ǰ
			change_len--;
		}

		// ���� β��
		modify_list_tail->next = head;

		// if pre_head������ͷ��
		if (pre_head) {
			pre_head->next = new_head; //ָ����ͷ
		}
		else {
			result = new_head; // new_head��ͷ
		}
		return result;
	}
};


int main() {
	//�����ڵ�
	ListNode a(1); //ע���ǽڵ㡣������ָ�룩
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode e(5);

	// ���ӡ� 
	a.next = &b; //ע����a.next()����Ϊ��ʵ��
	b.next = &c;
	c.next = &d;
	d.next = &e; //eĬ��ָ��NULL . (���캯��)

	// ʵ����Solution
	// ����
	Solution solve;
	ListNode *head = solve.reverseBetween(&a, 1, 4); // 2~4���� ������ͷ

	// ������ӡ
	while (head) { //while(��ͷ)
		printf("%d\n",head->val);
		head = head->next;
	}

	system("pause");
	return 0;
}