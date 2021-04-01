/*
leetCode 142.
������
*/
/*
˼·2��
	����ָ�����ܷ�

��ָ��ÿ������������ָ��ÿ����һ��

����ʱ����Ȧ����
a+b+c+b = 2*(a+b)
�ɵ� a = c

���ԣ�
����ʼλ�� �� ����λ�� ����ͬ�ٶ�ͬʱ�����������㼴Ϊ����ʼ�ڵ�
*/

#include <iostream>

struct ListNode {
	int val;
	ListNode *next; // ָ��

	// ���캯��
	ListNode(int x):val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *detectCycle(ListNode *head) 
	{
		ListNode *fast = head;
		ListNode *slow = head;
		ListNode *meet = NULL;

		// fast��������slow��һ������¼����
		while(fast) // �ȵ�NULL����ѭ��
		{
			fast = fast->next;
			slow = slow->next; //����һ��

			if (!fast) // �ȵ�NULL,����
			{
				return NULL; //����break�������return
			}
			fast = fast->next;//����һ��
			if (fast == slow) //��Ȧ�� 
			{
				meet = fast;
				break; // ����while
			}
		}

		// δ����������NULL
		if (meet == NULL) // ע�⣺��==
		{
			return NULL;
		}

		// ��������head��meet����һ���������㼴Ϊ ����ʼλ��
		while (head && meet) //Ϊ�˴���淶��д�ġ�����д��while(1){}
		{
			if (head == meet) 
			{
				return head; //�ҵ��˻�����ʼλ��
			}
			head = head->next; //����һ��
			meet = meet->next;
		}
		return NULL; //�����߲�����һ����Ϊ�˴���淶��д�ġ�
	}
};

int main() {
	// �ڵ� ʵ����
	ListNode a(1);
	ListNode b(2);
	ListNode c(666888);
	ListNode d(4);
	ListNode e(5);
	ListNode f(6);
	ListNode g(7);

	// ���� ����Ľڵ�
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	f.next = &g;
	g.next = &c;

	// ʵ����Solution���������� ��ʾ����ֵ
	Solution solve;
	ListNode * node = solve.detectCycle(&a);

	if (node) //��ַ�ǿ�
	{
		printf("node->val = %d\n", node->val);
	}
	else 
	{
		printf("δ�ҵ�\n");
	}

	system("pause");
	return 0;
}