#include <iostream>  // pause

struct ListNode{
	int val;  // ������
	ListNode *next;  // ָ����
	ListNode(int x): val(x), next(NULL) {}  // ���캯��
};

class Solution {
public:
	ListNode *reverseLinkedList(ListNode *head) {  // ����ͷ�ڵ�ָ��
		ListNode *pre = NULL;  // ǰһ���ڵ�ָ��
		while (head) {  // head�ǵ�ǰ�ڵ�cur
			ListNode* next = head->next;  // ��¼��һ���ڵ�  . д��while��ߣ���head�����ڣ���head->next�Ͳ��ᱨ��
			head->next = pre;  // ָ��ǰһ���ڵ�
			pre = head;  // ��ǰ���ǰһ��
			head = next;  // ��һ����ɵ�ǰ
		}
		return pre;  // ��head=NULL����Ҳ�Ƿ���NULL����Ӱ��
	}
};

int main() {
	ListNode a(10), b(20), c(30);
	a.next = &b;  //����
	b.next = &c;

	Solution solve;  //ʵ����
	ListNode *head = &a;
	while (head) {
		printf("[%d]\n", head->val);
		head = head->next;
	}
	printf("----------------\n");
	head = solve.reverseLinkedList(&a);
	while (head) {
		printf("[%d]\n", head->val);
		head = head->next;
	}

	system("pause");
	return 0;
}