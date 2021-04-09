/*
��Ŀ��
	��ָoffer
	ɾ�������� ���ظ�Ԫ�أ�������

���磺
	1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5
	ɾ����
	1 -> 2 -> 5
*/
/*
�ο����ϣ�
	��LeetCode 83��ɾ�����������е��ظ�Ԫ�� VS. ����ָoffer��ɾ���������ظ�Ԫ��
	https://blog.csdn.net/weixin_41888257/article/details/105178506
*/

#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}  // ���캯��
};


class Solution {
public:
	ListNode *deleteDuplication(ListNode *head) {  // ɾ���ظ�Ԫ��
		if (!head || !head->next) {  // ����0������1���ڵ㣬����
			return head;
		}
		ListNode *dummy = new ListNode(0);  // �ڱ�������. �����½������ص�ַ
		dummy->next = head;  // dummy��nextָ��ͷ
		ListNode *pre = dummy;  // ��ʼ����ά��preָ�룬 ָ���ظ��Ľڵ�
		ListNode *last = pre->next; // ά��lastָ�룬ָ����һ���ڵ�
		while (last) {  // ��last��ΪNULL��ʱ�򣬾ͼ���
			if (last->next && last->val == last->next->val) {  // ע�⣺ ���жϵ� ����ǰ�棬����˵last->next != NULL����ǰ��
				while (last->next && last->val == last->next->val) {  // ע��������last->next ��NULL, ֮��Ҫά����ȷ
					last = last->next;  // ����ظ��ڵ�
				}
				pre->next = last->next;  // ����
				last = last->next;  // ά����  ��һ����֪���ˣ��ƶ���last->next�����ƶ���NULL�ͽ�����
			}
			else {  // ������ظ����ͼ������ơ�  �����һ��value==NULL, �ͺ���
				pre = pre->next;
				last = last->next;
			}
		}
		return dummy->next;  // ���غ�����next
	}
};


int main() {
	ListNode a(1), b(2), c(3), d(3), e(3), f(4), g(5), h(5);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	f.next = &g;
	g.next = &h;

	Solution solve;
	ListNode *head = solve.deleteDuplication(&a);

	while (head) {
		printf("%d ", head->val);
		head = head->next;
	}
	printf("\n");

	system("pause");
	return 0;
}

