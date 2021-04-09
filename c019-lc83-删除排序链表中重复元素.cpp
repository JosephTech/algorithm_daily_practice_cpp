/*
LeetCode��ѡ100�⡪����83�⡪��ɾ�����������е��ظ�Ԫ��
https://blog.csdn.net/weixin_43338519/article/details/102516371?utm_medium=distribute.pc_relevant.none-task-blog-baidujs_title-0&spm=1001.2101.3001.4242
*/

/*
ɾ�����������е��ظ�Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ��
���磺
	1 -> 1 -> 2
	1 -> 2
���磺
	1 -> 1 -> 2 -> 3 -> 3
	1 -> 2 -> 3
*/
/*
˼·��
	����һ���뵱ǰ��ͬ�� ��������һ�� ������
*/

#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}  // ���캯��
};


class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {  // duplicates:����Ʒ
		ListNode *curr = head;  // ��curr�ƶ����������׼
		while (curr->next) {  // ��next���յ�ʱ��
			if (curr->next->val == curr->val) {  // ��ǰֵ==��һ��ֵ�������� ���¸�
				curr->next = curr->next->next;
			}
			else {
				curr = curr->next;  // ע�⣬value����ʱ�򣬲��ƶ�curr����һ��
			}
		}
		return head;
	}
};


int main() {
	ListNode a(1), b(1), c(1), d(2), e(2), f(3);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;

	Solution solve;
	ListNode *head = solve.deleteDuplicates(&a);

	while (head) {
		printf("%d ", head->val);
		head = head->next;
	}
	printf("\n");

	system("pause");
	return 0;
}