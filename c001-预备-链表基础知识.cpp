/*
����
	�½�һ���ṹ��
	1���洢Ԫ�ص�������
	2���洢��һ��Ԫ�صĵ�ַ��
*/
#include <stdio.h>
#include <iostream> // ������һ����system("pause")��  ��cout

//�ṹ�塢��������val����ַ��*next
struct ListNode{
	int val;
	ListNode *next; //struct���� ʵ���ĵ�ַ ����next
};
int main() {
	ListNode a;
	ListNode b;
	ListNode c;
	ListNode d;
	ListNode e;
	a.val = 10;
	b.val = 20;
	c.val = 30;
	d.val = 40;
	e.val = 50;

	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = NULL; //c++��NULL��д��true��falseСд

	ListNode *head = &a; //ָ��head  ָ��ListNode��ʵ��a

	while (head) {
		//��ӡֵ
		printf("%d\n", head->val); //ָ��head ָ�� aʵ��
		head = head->next; //ָ��head ָ�� bʵ��
	}
	system("pause");
	return 0;
}
