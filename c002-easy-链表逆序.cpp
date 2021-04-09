/*
��֪����ͷ�ڵ�ָ��head�����������򡣣������������ռ䣬�����������ռ䣬ָ���ǲ���������vecto��
*/
#include <stdio.h>
#include <iostream>

// �ṹ�壬����Ľڵ�
struct ListNode {
	int val; //������
	ListNode *next; //��ַ��  ��ָ�룬����һ��ListNode�ĵ�ַ��

	//���캯��
	ListNode(int x) : val(x), next(NULL) { // nextָ������Ĭ��ֵNULL�� �Ͳ������
	}
};

class Solution {
public:
	ListNode * reverseList(ListNode *head) { // ����ֵ��ListNode*
		// head�浱ǰ�ڵ� �ĵ�ַ
		// new_head�� �ϸ��ڵ�ĵ�ַ
		// next��ʱ�� �¸��ڵ��ַ������ǰ�ڵ��ָ��
		
		ListNode *new_head = NULL;
		while (head) {
			//next ��ʱ���¸��ڵ��ַ������ǰ�ڵ�ָ��
			ListNode *next = head->next;

			// ��ת��ͷhead->next  ָ����һ��
			head->next = new_head;
			
			// ��ǰ�����һ���� ������һ���ڵ��ַnew_head�� 
			new_head = head;
			
			// ��һ����ɵ�ǰ�����µ�ǰ�ڵ��ַ�� 
			head = next;
		}
		return new_head; // ���new_headָ�����һ�� ��ǰ�ڵ�
		// ���next��head����NULL
	}
};

int main() {
	ListNode a(1); //����
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode e(5);

	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	//e.next = NULL;//��䲻�ã���ΪListNode�Ĺ��캯��д��

	printf("reverse����ǰ��\n");
	ListNode * head = &a;
	while (head) {
		printf("%d\n", head->val); // %d��ʽ��Ϊ����
		head = head->next; //��һ����ɵ�ǰ
	}

	printf("reverse�����\n");
	Solution sol;
	ListNode *new_head = sol.reverseList(&a);
	while (new_head) {
		printf("%d\n", new_head->val);
		new_head = new_head->next;
	}
	system("pause");
	return 0;
}