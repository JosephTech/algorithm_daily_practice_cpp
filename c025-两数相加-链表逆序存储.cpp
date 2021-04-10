/*
�ο����ӣ�
��LeetCode��2. ������ӣ���������洢�����ף� & 445. ������� II����������洢�����ѣ�ջ��
https://blog.csdn.net/weixin_41888257/article/details/107289086
*/
/*
2 ������ӣ�c++ ���� ��
https://blog.csdn.net/LIJIWEI0611/article/details/102709983?utm_medium=distribute.pc_relevant.none-task-blog-baidujs_title-0&spm=1001.2101.3001.4242
*/
/*
�����
leetcode 2 �������(c++)
https://zhuanlan.zhihu.com/p/102633949
*/

#include <iostream>  // pause

struct ListNode {  // ���ݽṹ
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}  // ���캯��
};

class Solution {
public:
	ListNode *twoSum(ListNode *l1, ListNode *l2) {
		int flag = 0;  // ��λ��ֵ 
		ListNode *dummy = new ListNode(0);  // ����
		ListNode *curr = dummy;  // ����ָ��
		int num = 0;
		while (l1 || l2) {
			if (l1)
				num += l1->val;
			if (l2)
				num += l2->val;
			curr->next = new ListNode(num % 10);  // ȡ�������֣� ��Ϊ��ǰλ
			flag = num / 10;  // �� ����flag
			curr = curr->next;  // �ƶ�currָ�롢l1ָ�롢 l2ָ��
			if (l1) 
				l1 = l1->next;
			if (l2) 
				l2 = l2->next;
			num = 0;  // ��һλ�ĺ�
			if (flag)
				num += flag;  // ����flag, ����sum����һ���ڵ�����á�
		}
		if (num)  // ��� ��ʣ�����
			curr->next = new ListNode(num);
		return dummy->next;
	}
};

/*
ע�⣺
	��д����ʱ��Ҫɾ���Լ�new�Ľڵ�
*/

int main() {
	ListNode a1(1), a2(2), a3(8),b1(3), b2(3), b3(3);

	a1.next = &a2;
	a2.next = &a3;
	
	b1.next = &b2;
	b2.next = &b3;

	Solution solve;
	ListNode * head =solve.twoSum(&a1, &b1);
	ListNode * curr = head;
	while (head) {
		printf("%d ", head->val);
		head = head->next;
	}
	printf("\n");
	
	while (curr) {  // ɾ��
		ListNode *next = curr->next;  // ��¼��һ��
		delete curr;  // ɾ����ǰ
		curr = next;  // ��һ��
	}

	system("pause");
	return 0;
}