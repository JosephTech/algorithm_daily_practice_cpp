/*
set���ϵ�ʱ�临�Ӷ���nlog(n)��  �ռ临�Ӷ���O(n)���ȼ��ţ�
*/

/*
˼·2:���ռ临�Ӷ�O(1)  (����ռ�õĶ����ڴ�ռ�)

	����1������headA�����ȣ� ����headB�����ȣ��ϳ����������ĳ���
	����2�����ϳ������ָ�룬�ƶ����ͽ϶���������λ��
	����3��headA��headBͬʱ�ƶ�������ָ��ָ��ͬһ�ڵ�ʱ�����ҵ���
*/

#include <iostream> // "pause"�õ�

//�ṹ�塣 ����
struct ListNode {
	int val;
	ListNode * next; //ָ���¸�ʵ��

	// ���캯��
	ListNode(int x):val(x), next(NULL) {}
};

// ������ ��ȡ������
int get_list_length(ListNode *head) 
{
	int len = 0;
	while (head) 
	{
		len++;
		head = head->next; //�Ƶ���һ���ڵ�
	}
	return len;
}

// ��������headָ�� �ƶ� ����-�̣���λ�á� ���� ��1��ʼ�ƶ�����-�̣���λ�ã�
ListNode *forward_minus_len(int long_len, int short_len, ListNode * head) 
{
	int forward_len = long_len - short_len;

	// ��ǰ�ƶ�forward_len
	while (head && forward_len) 
	{
		head = head->next;
		forward_len--;
	}
	return head;
}

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
	{
		// ����������ĳ���
		int list_A_len = get_list_length(headA);
		int list_B_len = get_list_length(headB);

		// �������� ��headָ�� ��ǰ�ƶ� ��long-short�� ��λ��
		if (list_A_len > list_B_len)
		{
			headA = forward_minus_len(list_A_len, list_B_len, headA); //����headA
		}
		else 
		{
			headB = forward_minus_len(list_B_len, list_A_len, headB);
		}
		while (headA && headB) 
		{
			if (headA == headB) 
			{
				return headA;
			}
			headA = headA->next;
			headB = headB->next;
		}
		return NULL;
	}
};

int main() {
	// ʵ�����ڵ㡢��ֵ
	ListNode a1(1);
	ListNode a2(3);
	ListNode a3(2);

	ListNode b1(6);
	ListNode b2(7);

	ListNode c1(666);
	ListNode c2(777);
	ListNode c3(888);

	// ���ӽڵ�
	a1.next = &a2;
	a2.next = &a3;
	a3.next = &c1;

	c1.next = &c2;
	c2.next = &c3; // c3Ĭ�ϵĹ�����NULL

	b1.next = &b2;
	b2.next = &c1;

	Solution solve;// ʵ����
	ListNode * result = solve.getIntersectionNode(&a1, &b1);

	if (result != NULL)
	{
		printf("���� �洢��ֵ�ǣ�%d\n", result->val); // ָ�루ָ��ListNodeʵ������ָ��ڵ㣩��ȡval
	}
	else
	{
		printf("�޽���\n");
	}


	system("pause");
	return 0;
}