/*
leetcode 234�������
palindrome linked list

��Ŀ��
	��O(1)�Ŀռ临�Ӷȣ��ж������Ƿ����

���磺
	1 -> 2 -> 3 -> 2 -> 1
	true
*/
/*
˼·��
	����ָ���ҵ��е㣬
	��ת��ָ���ߵ�
	����Ƚϣ�����true����false
*/

#include <iostream>  // puase

struct ListNode {  // ���ݽṹ
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}  // ���캯��
};

class Solution {
public:
	bool isPalindrome(ListNode *head) {
		if (!head) 
			return false;  // �Ͻ���
		ListNode *slow = head, *fast = head;
		while (fast->next && fast->next->next) {  // ���յ�ʱ��
			slow = slow->next;
			fast = fast->next->next;  // ������
		}
		slow->next = reverse(slow->next);  // ��ת ��ߵ�
		slow = slow->next;  // slow��head�������
		while (head && slow) {  // �Ƚ�
			if (head->val != slow->val) {
				return false;
			}
			head = head->next;
			slow = slow->next;
		}
		return true;
	}
private:
	ListNode *reverse(ListNode *head) {  // ��ת����
		ListNode *curr = head;  // ����淶����дһ�а�
		ListNode *pre = NULL;
		while (curr) {
			ListNode *next = curr->next;  // ��¼��һ��
			curr->next = pre;  // ��ת��ͷ
			pre = curr;  // ��ǰ ��ֵ�� ��һ��
			curr = next;  // ��һ�� ���  ��ǰ
		}
		return pre;   // ���� ��ͷ
	}
};



int main() {
	ListNode a(1), b(2), c(3), d(2), e(2);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;

	Solution solve;
	printf("%d\n", solve.isPalindrome(&a));

	system("pause");
	return 0;
}