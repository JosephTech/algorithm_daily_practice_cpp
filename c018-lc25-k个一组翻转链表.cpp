/*
��Ŀ��
	k��һ�鷭ת����
	k��һ��������
	k С�ڵ��� ������

����ڵ���������k�����������ʣ��Ľڵ��豣��ԭ��˳��
*/
/*
���ӣ�
	1 -> 2 -> 3 -> 4 -> 5
��k=2ʱ
	2 -> 1 -> 4 -> 3 -> 5

��k=3ʱ
	3 -> 2 -> 1 -> 4 -> 5
*/
/*
LeetCodeϵ��֮��25. K ��һ�鷭ת����C++ ÿ��һ��leetcode��
https://blog.csdn.net/qq_28410301/article/details/100267021?utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-1.control&dist_request_id=&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-1.control
*/


#include <iostream>  // pause

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *reverse_k(ListNode *head, int k) {
		ListNode *dummy = new ListNode(0);   // �ڱ���  newֻ���ص�ַ�����Բ�������
		dummy->next = head;
		ListNode *pre = dummy, *start = head, *end = head, *next = head;
		while (next) {  // next���յ�ʱ�򣬾ͼ���
			for (int i = 1; i < k && end != NULL; i++)  // ά��end�����start����end��1�ƶ������
				end = end->next;
			if (end == NULL) // ��end�ƶ���NULL�ˣ��ͽ���
				break;
			next = end->next;  // ��¼ �߶� ��һ��
			end->next = NULL;  // Ϊ����reverse�����ܽ����� ��������һ��
			end = start;  // end ָ���߶ο�ʼ
			start = reverse(start);  // startָ���߶�  ��ת���ͷ
			pre->next = start;  // ������ϣ�����ͷ
			end->next = next;  // ����β
			pre = end;  // ά��pre���߶ε� ǰһ���ڵ�
			end = end->next;  // ά��end�� ���߶ε�ͷ�ڵ�
			start = end;  // ά��start
		}
		return dummy->next;
	}

private:
	ListNode *reverse(ListNode * head) {
		ListNode *pre = NULL, *curr = head, *next = NULL;  // ע���½�NULLָ��
		while (curr) {
			next = curr->next;  // ��¼��һ��
			curr->next = pre;  // ָ��ǰһ��
			pre = curr;  // ��ǰ �� ǰһ��
			curr = next;  // ��һ�� �� ��ǰ  ��  ������while(curr)
		}
		return pre;  // �������һ������Ϊ��ͷ
	}
};


int main() {
	ListNode a(1), b(2), c(3), d(4), e(5);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;

	Solution solve;
	ListNode * head = solve.reverse_k(&a, 3);

	while (head) {
		printf("%d ", head->val);
		head = head->next;
	}
	printf("\n");


	system("pause");
	return 0;
}

