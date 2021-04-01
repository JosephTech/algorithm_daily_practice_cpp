/*
˼·������
	https://blog.csdn.net/Doutd_y/article/details/81557320
	��һ��һ��Ԫ�ش�ԭ����ȡ����������������Ԫ�رȽ�,���뵽������
	ʱ�临�Ӷ�0(n^2)�� �ռ临�Ӷ�O(1)
*/

#include <iostream> // pause�õ�

struct ListNode {
	int val;
	ListNode *next;
	//���캯��
	ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *insertSortList(ListNode *head) { //��������� ͷ�ڵ�ָ��
		ListNode sort_head(0); //�������ͷ ��ǰһ���ڵ�
		while (head) { //headָ����Զ���������������ǰ�ڵ�
			ListNode *temp = head->next;
			ListNode *inser = &sort_head; //����һ��ָ�룬���Զ��ģ�����������
			while (inser->next != NULL && inser->next->val < head->val) { 
				//����������insert->next-val��λ�ã������������һ��Ԫ�� �� ���������Ԫ�ش�
				//			�������������next��NULL,���������һ���ڵ㣬��ֱ������
				inser = inser->next;
			}
			head->next = inser->next; //���Ϻ����ڵ�
			inser->next = head; // ����ǰ���ڵ�
			head = temp; //���������һ���ڵ�
		}
		return sort_head.next;
	}
};

int main() {
	ListNode n1(2), n2(1), n3(88), n4(3), n5(6);
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;

	Solution solve;
	ListNode *new_head = solve.insertSortList(&n1);

	ListNode *head = new_head;
	//��ӡ
	while (head) {
		printf("%d\n",head->val);
		head = head->next;
	}

	system("pause");
	return 0;
}