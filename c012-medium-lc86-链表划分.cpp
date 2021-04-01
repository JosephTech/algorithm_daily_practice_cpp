/*
leetCode 86. Partition List
������
��֪����ͷָ��head����ֵx��������С��x�Ľڵ���ڴ��ڻ����x�Ľڵ�ǰ���ұ�����Щ�ڵ�ԭ�������λ��
*/
#include <iostream>

// �ṹ�塣����ڵ�ListNode
struct ListNode {
	int val;
	ListNode *next;

	//���캯��
	ListNode(int x):val(x), next(NULL) {}
};

// ��Solution����߶��庯��partition
class Solution {
public:
	ListNode *partition(ListNode *head, int x) 
	{
		ListNode less_head(0);
		ListNode more_head(0); //�½�����ͷ  ��ʵ����
		ListNode *less_ptr = &less_head; //ָ�� ��ͷ
		ListNode *more_ptr = &more_head;

		while (head) 
		{
			// С�ڣ�������less_head��ʹ��ptr������Ϊptr�ܶ���
			if (head->val < x) 
			{
				less_ptr->next = head; //����
				less_ptr = head; //�ƶ�less_ptr
			}

			// ���ڣ�������more_head
			else 
			{
				more_ptr->next = head; //����
				more_ptr = head; //�ƶ�more_ptr
			}
			head = head->next; // ָ��head ����
		}
		less_ptr->next = more_head.next; //����
		more_ptr->next = NULL; // β���ÿ�
		return less_head.next; // ���صڶ����ڵ㿪ʼ������
	}
};

//main
int main() {
	// ʵ���� ����ڵ�
	ListNode a(30);
	ListNode b(70);
	ListNode c(40);
	ListNode d(60);
	ListNode e(10);
	ListNode f(50);
	ListNode g(20);

	//����
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	f.next = &g;
	g.next = NULL;

	// ʵ����Solution�����ú���
	Solution solve;
	ListNode *head = solve.partition(&a, 39);

	while (head) 
	{
		printf("%d\n",head->val);
		head = head->next;
	}

	system("pause");
	return 0;
}

